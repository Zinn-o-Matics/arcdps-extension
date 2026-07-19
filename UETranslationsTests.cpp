#include "UETranslations.h"

#include "Localization.h"
#include "Singleton.h"

#include <gtest/gtest.h>

using namespace ArcdpsExtension;

class UETranslationsTests : public ::testing::Test {
public:
	static void TearDownTestSuite() {
		g_singletonManagerInstance.Shutdown();
	}

protected:
	HKL germanHkl = nullptr;
	HKL englishHkl = nullptr;

	void SetUp() override {
		germanHkl = LoadKeyboardLayoutA("00000407", KLF_NOTELLSHELL);
		ASSERT_NE(germanHkl, nullptr) << "Failed to load German layout";

		englishHkl = LoadKeyboardLayoutA("00000409", KLF_NOTELLSHELL);
		ASSERT_NE(englishHkl, nullptr) << "Failed to load English layout";

		auto& localization = Localization::instance();
		localization.Load(Lang::German);
		localization.Load(Lang::French);
		localization.Load(Lang::Spanish);
		localization.Load(Lang::Chinese);

		localization.Load(Lang::English, UE_TRANSLATIONS_ENGLISH);
		localization.Load(Lang::French, UE_TRANSLATIONS_FRENCH);
		localization.Load(Lang::German, UE_TRANSLATIONS_GERMAN);
		localization.Load(Lang::Spanish, UE_TRANSLATIONS_SPANISH);

		::testing::Test::SetUp();
	}
	void TearDown() override {
		g_singletonManagerInstance.Shutdown();

		if (germanHkl != nullptr) {
			UnloadKeyboardLayout(germanHkl);
			germanHkl = nullptr;
		}
		if (englishHkl != nullptr) {
			UnloadKeyboardLayout(englishHkl);
			englishHkl = nullptr;
		}

		::testing::Test::TearDown();
	}
};

TEST_F(UETranslationsTests, KeyControl) {
	Localization::SChangeLanguage(Lang::English);
	ASSERT_EQ(to_string(KeyBinds::KeyControl::Camera_DisableActionCamera), Localization::STranslate(UE_Camera_DisableActionCamera));
	ASSERT_EQ(to_string(KeyBinds::KeyControl::Templates_FashionTemplate9), Localization::STranslate(UE_Templates_FashionTemplate9));
}

TEST_F(UETranslationsTests, MouseCode) {
	Localization::SChangeLanguage(Lang::English);
	// This test is relevant, cause the num order of mouse codes is weird.
	ASSERT_EQ(to_string(KeyBinds::MouseCode::Mouse_1), "Mouse 1");
	ASSERT_EQ(to_string(KeyBinds::MouseCode::Mouse_3), "Mouse 3");
	ASSERT_EQ(to_string(KeyBinds::MouseCode::Mouse_2), "Mouse 2");
	ASSERT_EQ(to_string(KeyBinds::MouseCode::Mouse_4), "Mouse 4");
}

TEST_F(UETranslationsTests, KeyCodeEnglish) {
	Localization::SChangeLanguage(Lang::English);
	ASSERT_EQ(to_string(KeyBinds::KeyCode::A, englishHkl), "A");
	ASSERT_EQ(to_string(KeyBinds::KeyCode::Z, englishHkl), "Z");
	ASSERT_EQ(to_string(KeyBinds::KeyCode::ArrowDown, englishHkl), "Down Arrow");
	ASSERT_EQ(to_string(KeyBinds::KeyCode::Hash, englishHkl), "\\");
	ASSERT_EQ(to_string(KeyBinds::KeyCode::Tilde, englishHkl), "`");
	ASSERT_EQ(to_string(KeyBinds::KeyCode::PlusNum, englishHkl), "Add (NUM)");
	ASSERT_EQ(to_string(KeyBinds::KeyCode::Semicolon, englishHkl), ";");
}

TEST_F(UETranslationsTests, KeyCodeGerman) {
	Localization::SChangeLanguage(Lang::German);
	ASSERT_EQ(to_string(KeyBinds::KeyCode::A, germanHkl), "A");
	ASSERT_EQ(to_string(KeyBinds::KeyCode::Z, germanHkl), "Y");
	ASSERT_EQ(to_string(KeyBinds::KeyCode::ArrowDown, germanHkl), (const char*)u8"Pfeiltaste abwärts");
	ASSERT_EQ(to_string(KeyBinds::KeyCode::Hash, germanHkl), "#");
	ASSERT_EQ(to_string(KeyBinds::KeyCode::Tilde, germanHkl), "^");
	ASSERT_EQ(to_string(KeyBinds::KeyCode::PlusNum, germanHkl), "Plus (ZB)");
	ASSERT_EQ(to_string(KeyBinds::KeyCode::Semicolon, germanHkl), "ö");
	Localization::SChangeLanguage(Lang::English);
}

TEST_F(UETranslationsTests, KeyEnglish) {
	Localization::SChangeLanguage(Lang::English);
	ASSERT_EQ(to_string(KeyBinds::Key(), englishHkl), "");
	ASSERT_EQ(to_string(KeyBinds::Key(), englishHkl, true), Localization::STranslate(UE_Unset));
	ASSERT_EQ(to_string(KeyBinds::Key(KeyBinds::MouseCode::Mouse_1), englishHkl), "Mouse 1");
	ASSERT_EQ(to_string(KeyBinds::Key(KeyBinds::MouseCode::Mouse_1, KeyBinds::Modifier_Shift), englishHkl), "Shift + Mouse 1");
	ASSERT_EQ(to_string(KeyBinds::Key(KeyBinds::MouseCode::Mouse_1, KeyBinds::Modifier_Shift | KeyBinds::Modifier_Alt), englishHkl), "Alt + Shift + Mouse 1");
	ASSERT_EQ(to_string(KeyBinds::Key(KeyBinds::KeyCode::_5_NUM), englishHkl), "5 (NUM)");
	ASSERT_EQ(to_string(KeyBinds::Key(KeyBinds::KeyCode::_5_NUM, KeyBinds::Modifier_Shift), englishHkl), "Shift + 5 (NUM)");
	ASSERT_EQ(to_string(KeyBinds::Key(KeyBinds::KeyCode::_5_NUM, KeyBinds::Modifier_Shift | KeyBinds::Modifier_Alt), englishHkl), "Alt + Shift + 5 (NUM)");
}

TEST_F(UETranslationsTests, KeyGerman) {
	Localization::SChangeLanguage(Lang::German);
	ASSERT_EQ(to_string(KeyBinds::Key(), germanHkl), "");
	ASSERT_EQ(to_string(KeyBinds::Key(), germanHkl, true), Localization::STranslate(UE_Unset));
	ASSERT_EQ(to_string(KeyBinds::Key(KeyBinds::MouseCode::Mouse_1), germanHkl), "Maus 1");
	ASSERT_EQ(to_string(KeyBinds::Key(KeyBinds::MouseCode::Mouse_1, KeyBinds::Modifier_Shift), germanHkl), "Umschalttaste + Maus 1");
	ASSERT_EQ(to_string(KeyBinds::Key(KeyBinds::MouseCode::Mouse_1, KeyBinds::Modifier_Shift | KeyBinds::Modifier_Alt), germanHkl), "Alt + Umschalttaste + Maus 1");
	ASSERT_EQ(to_string(KeyBinds::Key(KeyBinds::KeyCode::_5_NUM), germanHkl), "5 (ZB)");
	ASSERT_EQ(to_string(KeyBinds::Key(KeyBinds::KeyCode::_5_NUM, KeyBinds::Modifier_Shift), germanHkl), "Umschalttaste + 5 (ZB)");
	ASSERT_EQ(to_string(KeyBinds::Key(KeyBinds::KeyCode::_5_NUM, KeyBinds::Modifier_Shift | KeyBinds::Modifier_Alt), germanHkl), "Alt + Umschalttaste + 5 (ZB)");
	Localization::SChangeLanguage(Lang::English);
}
