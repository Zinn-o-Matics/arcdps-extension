#pragma once

#include "arcdps_structs_slim.h"
#include "ExtensionTranslations.h"
#include "Singleton.h"

#include <concepts>
#include <cstddef>
#include <ranges>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>


#ifdef ARCDPS_EXTENSION_UNOFFICIAL_EXTRAS
#include <ArcdpsUnofficialExtras/Definitions.h>
#endif

namespace ArcdpsExtension {
	namespace Lang {
		inline std::string English = "en";
		inline std::string French = "fr";
		inline std::string German = "de";
		inline std::string Spanish = "es";
		inline std::string Chinese = "zh-cn";
		inline std::string TChinese = "zh-tw";
	} // namespace Lang

	namespace details {
		template<typename T>
		concept PairLike =
				requires { std::tuple_size<std::remove_cvref_t<T>>::value; } // This cannot be tuple_size_v, it causes a hard error
				&& std::tuple_size_v<std::remove_reference_t<T>> == 2;

		template<typename T>
		concept KeyValueRange =
				std::ranges::range<T>
				&& PairLike<std::ranges::range_value_t<T>>;

		template<typename T, typename K, typename V>
		concept KeyValueRangeOf =
				KeyValueRange<T>
				&& std::convertible_to<
						std::tuple_element_t<0, std::remove_cvref_t<std::ranges::range_value_t<T>>>,
						K>
				&& std::convertible_to<
						std::tuple_element_t<1, std::remove_cvref_t<std::ranges::range_value_t<T>>>,
						V>;
	} // namespace details

	/**
	 * How to use:<br>
	 * Call `Load()` with your translations you want to add.
	 * Call it within `mod_init` or as early as possible.
	 *
	 * <b>Make sure to properly setup and teardown the Singleton class.</b>
	 *
	 * Call `ChangeLanguage` when you want to change the language.
	 * Call it once to setup the language the user has in `mod_init`
	 *
	 * Call `ChangeFallbackLanguage` when you want to change the fallback language.
	 * It defaults to English.
	 *
	 * You can add or replace translations with `AddTranslation`.
	 * If you have a big range of translations to add in bulk, use `Load`.
	 *
	 * Some functions have static alternative prefixes starting with `S...`.
	 * That function calls instance() and then its counter-part.
	 */
	class Localization final : public Singleton<Localization> {
	public:
		Localization();

		/**
		 * Translate the id to the current default language.
		 * If id is not found, it will return the fallback translation.
		 *
		 * @param pId the id of the translation (normally the enum you use)
		 * @throws std::out_of_range if the id is not found in the fallback translation.
		 * @return Null terminated string_view. Use .data() instead of .c_str() if you need a const char*
		 */
		[[nodiscard]] std::string_view Translate(size_t pId) const;

		/**
		 * Translate the id to the given language.
		 * If id is not found, it will return the fallback translation.
		 *
		 * @param lang the language key (e.g. "de", "zh-cn")
		 * @param pId the id of the translation (normally the enum you use)
		 * @throws std::out_of_range if the lang is not found in the list of languages, or if the id is not found in the fallback translation.
		 * @return Null terminated string_view. Use .data() instead of .c_str() if you need a const char*
		 */
		[[nodiscard]] std::string_view Translate(const std::string& lang, size_t pId) const {
			const auto& langMap = mTranslations.at(lang);
			const auto& it = langMap.find(pId);
			if (it == langMap.end()) {
				return mFallbackTranslation->at(pId);
			}
			return it->second;
		}

		template<typename E>
		requires std::is_enum_v<E>
		[[nodiscard]] std::string_view Translate(E pId) const {
			return Translate(std::to_underlying(pId));
		}
		template<typename E>
		requires std::is_enum_v<E>
		[[nodiscard]] std::string_view Translate(const std::string& lang, E pId) const {
			return Translate(lang, std::to_underlying(pId));
		}

		template<typename Num>
		requires std::is_integral_v<Num> && (!std::same_as<Num, size_t>)
		[[nodiscard]] std::string_view Translate(Num pId) const {
			return Translate(static_cast<size_t>(pId));
		}
		template<typename Num>
		requires std::is_integral_v<Num> && (!std::same_as<Num, size_t>)
		[[nodiscard]] std::string_view Translate(const std::string& lang, Num pId) const {
			return Translate(lang, static_cast<size_t>(pId));
		}

		[[nodiscard]] std::string_view Translate(const std::string& pLang) const;

		template<typename... Args>
		[[nodiscard]] static std::string_view STranslate(Args... args) {
			return Localization::instance().Translate(std::forward<Args>(args)...);
		}

		/**
		 * Add/Overwrite a key-value-range of translations.
		 * The value of the range must be convertible to `std::string_view`.
		 * Example ranges: `std::map<Key, const char*>` or `std::vector<std::pair<Key, const char*>>`.
		 */
		template<typename R>
		requires details::KeyValueRangeOf<R, size_t, std::string_view>
		void Load(const std::string& pLang, const R& pRange) {
			for (auto&& [key, value] : pRange) {
				AddTranslation(pLang, key, value);
			}
		}

		/**
		 * Add/Overwrite a key-value-range of translations.
		 * The value of the range must be convertible to `std::u8string_view`.
		 * Example ranges: `std::map<Key, const char8_t*>` or `std::vector<std::pair<Key, const char8_t*>>`.
		 */
		template<typename R>
		requires details::KeyValueRangeOf<R, size_t, std::u8string_view>
		void Load(const std::string& pLang, const R& pRange) {
			Load(pLang, pRange | std::views::transform([](const auto& p) {
							std::u8string_view value(p.second);
							return std::pair(p.first, std::string_view(reinterpret_cast<const char*>(value.data()), value.size()));
						}));
		}

		/**
		 * Load the default translations for the specified language.
		 * Call it for each default language you want to support.
		 * This is not needed for English, because that one is loaded on construction.
		 * Default languages are available in @ref ::ArcdpsExtension::Lang.
		 */
		void Load(const std::string& pLang);

		void ChangeLanguage(const std::string& pLang);
		static void SChangeLanguage(const std::string& pLang);

		void ChangeFallbackLanguage(const std::string& pLang);
		static void SChangeFallbackLanguage(const std::string& pLang);

		template<typename... Args>
		void AddTranslation(const std::string& pLanguage, size_t pTranslation, Args&&... args) {
			mTranslations[pLanguage][pTranslation] = std::move(std::string(std::forward<Args...>(args...)));
			Languages.insert(pLanguage);
		}

		template<typename E, typename... Args>
		requires std::is_enum_v<E>
		void AddTranslation(const std::string& pLanguage, E pTranslation, Args&&... args) {
			AddTranslation(pLanguage, static_cast<std::underlying_type_t<E>>(pTranslation), std::forward<Args...>(args...));
		}

		template<typename Num, typename... Args>
		requires std::is_integral_v<Num> && (!std::same_as<Num, size_t>)
		void AddTranslation(const std::string& pLanguage, Num pTranslation, Args&&... args) {
			AddTranslation(pLanguage, static_cast<size_t>(pTranslation), std::forward<Args...>(args...));
		}

		/**
		 * Get the stored list of available language keys.
		 *
		 * Languages are represented as strings, typically following standard language
		 * codes (e.g., "en" for English, "de" for German, etc.). This set is automatically
		 * updated when new translations are added via `AddTranslation`.
		 *
		 * Use this set to access the list of all available languages to e.g., implement language selection menus.
		 */
		const std::unordered_set<std::string>& GetLanguages() const {
			return Languages;
		}

		static const std::string& ToLangCode(gwlanguage lang);
#ifdef ARCDPS_EXTENSION_UNOFFICIAL_EXTRAS
		static const std::string& ToLangCode(Language lang);
#endif

	private:
		using Translation = std::unordered_map<size_t, std::string>;
		std::unordered_map<std::string, Translation> mTranslations;

		Translation* mCurrentTranslation = nullptr;
		Translation* mFallbackTranslation = nullptr;

		/**
		 * Stores the set of all language keys currently in use.
		 *
		 * Languages are represented as strings, typically following standard language
		 * codes (e.g., "en" for English, "de" for German, etc.). This set is automatically
		 * updated when new translations are added via `AddTranslation`.
		 *
		 * Use this set to access the list of all available languages to e.g., implement language selection menus.
		 */
		std::unordered_set<std::string> Languages;
	};
} // namespace ArcdpsExtension
