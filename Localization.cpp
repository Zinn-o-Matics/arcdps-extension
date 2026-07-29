#include "Localization.h"

#include "ExtensionTranslations.h"

#include <ArcdpsUnofficialExtras/Definitions.h>
#include <array>

ArcdpsExtension::Localization::Localization() {
	Load(Lang::English, EXTENSION_TRANSLATION_ENGLISH);

	mCurrentTranslation = &mTranslations.at(Lang::English);
	mFallbackTranslation = &mTranslations.at(Lang::English);
}

std::string_view ArcdpsExtension::Localization::Translate(size_t pId) const {
	const auto it = mCurrentTranslation->find(pId);
	if (it == mCurrentTranslation->end()) {
		return mFallbackTranslation->at(pId);
	}
	return it->second;
}

std::string_view ArcdpsExtension::Localization::Translate(const std::string& pLang) const {
	return mTranslations.at(pLang).at(ET_LanguageName);
}

void ArcdpsExtension::Localization::Load(const std::string& pLang) {
	if (pLang == Lang::German) {
		Load(pLang, EXTENSION_TRANSLATION_GERMAN);
	} else if (pLang == Lang::French) {
		Load(pLang, EXTENSION_TRANSLATION_FRENCH);
	} else if (pLang == Lang::Spanish) {
		Load(pLang, EXTENSION_TRANSLATION_SPANISH);
	} else if (pLang == Lang::Chinese) {
		Load(pLang, EXTENSION_TRANSLATION_CHINESE);
	} else if (pLang == Lang::TChinese) {
		Load(pLang, EXTENSION_TRANSLATION_TCHINESE);
	}
}

void ArcdpsExtension::Localization::ChangeLanguage(const std::string& pLang) {
	mCurrentTranslation = &mTranslations.at(pLang);
}

void ArcdpsExtension::Localization::SChangeLanguage(const std::string& pLang) {
	Localization::instance().ChangeLanguage(pLang);
}
void ArcdpsExtension::Localization::ChangeFallbackLanguage(const std::string& pLang) {
	mFallbackTranslation = &mTranslations.at(pLang);
}
void ArcdpsExtension::Localization::SChangeFallbackLanguage(const std::string& pLang) {
	Localization::instance().ChangeFallbackLanguage(pLang);
}

const std::string& ArcdpsExtension::Localization::ToLangCode(gwlanguage lang) {
	switch (lang) {
		case GWL_ENG:
			return Lang::English;
		case GWL_FRE:
			return Lang::French;
		case GWL_GEM:
			return Lang::German;
		case GWL_SPA:
			return Lang::Spanish;
		case GWL_CN:
			return Lang::Chinese;
		default:
			return Lang::English;
	}
}
#ifdef ARCDPS_EXTENSION_UNOFFICIAL_EXTRAS
const std::string& ArcdpsExtension::Localization::ToLangCode(Language lang) {
	switch (lang) {
		case Language::English:
			return Lang::English;
		case Language::French:
			return Lang::French;
		case Language::German:
			return Lang::German;
		case Language::Spanish:
			return Lang::Spanish;
		case Language::Chinese:
			return Lang::Chinese;
		default:
			return Lang::English;
	}
}
#endif
