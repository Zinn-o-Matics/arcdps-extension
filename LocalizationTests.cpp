#include "ExtensionTranslations.h"
#include "Localization.h"
#include "Singleton.h"

#include <gtest/gtest.h>

using namespace ArcdpsExtension;

class LocalizationTests : public ::testing::Test {
public:
	static void TearDownTestSuite() {
		g_singletonManagerInstance.Shutdown();
	}

protected:
	void SetUp() override {
		auto& localization = Localization::instance();
		localization.Load(Lang::German);
		localization.Load(Lang::French);
		localization.Load(Lang::Spanish);
		localization.Load(Lang::Chinese);
		localization.Load(Lang::TChinese);

		::testing::Test::SetUp();
	}
	void TearDown() override {
		g_singletonManagerInstance.Shutdown();

		::testing::Test::TearDown();
	}
};

TEST_F(LocalizationTests, BaseTranslations) {
	auto& localization = Localization::instance();

	localization.ChangeLanguage(Lang::English);
	ASSERT_EQ(localization.Translate(ET_Left), "Left");
	localization.ChangeLanguage(Lang::German);
	ASSERT_EQ(localization.Translate(ET_Left), "Links");
	localization.ChangeLanguage(Lang::French);
	ASSERT_EQ(localization.Translate(ET_Left), "Gauche");
	localization.ChangeLanguage(Lang::Spanish);
	ASSERT_EQ(localization.Translate(ET_Left), "Izquierda");
	localization.ChangeLanguage(Lang::Chinese);
	ASSERT_EQ(localization.Translate(ET_Left), "居左");
	localization.ChangeLanguage(Lang::TChinese);
	ASSERT_EQ(localization.Translate(ET_Left), "靠左");
}

TEST_F(LocalizationTests, BaseTranslationsLang) {
	auto& localization = Localization::instance();

	ASSERT_EQ(localization.Translate(Lang::English, ET_Left), "Left");
	ASSERT_EQ(localization.Translate(Lang::German, ET_Left), "Links");
	ASSERT_EQ(localization.Translate(Lang::French, ET_Left), "Gauche");
	ASSERT_EQ(localization.Translate(Lang::Spanish, ET_Left), "Izquierda");
	ASSERT_EQ(localization.Translate(Lang::Chinese, ET_Left), "居左");
	ASSERT_EQ(localization.Translate(Lang::TChinese, ET_Left), "靠左");
}

TEST_F(LocalizationTests, BaseTranslationsSpecialChars) {
	auto& localization = Localization::instance();

	localization.ChangeLanguage(Lang::German);
	ASSERT_EQ(localization.Translate(ET_SizingPolicyManualWindowSize), "Manuelle Fenstergröße");
	localization.ChangeLanguage(Lang::French);
	ASSERT_EQ(localization.Translate(ET_UpdateRestartPending), "La mise à jour automatique est terminée, redémarrez votre jeu pour l'activer.");
	localization.ChangeLanguage(Lang::Spanish);
	ASSERT_EQ(localization.Translate(ET_UpdateInProgress), "Actualización automática en curso");
	localization.ChangeLanguage(Lang::Chinese);
	ASSERT_EQ(localization.Translate(ET_SizingPolicySizeContentToWindow), "根据窗口大小调整内容大小");
	localization.ChangeLanguage(Lang::TChinese);
	ASSERT_EQ(localization.Translate(ET_SizingPolicySizeContentToWindow), "調整內容到視窗的大小");
}

TEST_F(LocalizationTests, OverrideTranslation) {
	auto& localization = Localization::instance();

	localization.ChangeLanguage(Lang::English);
	ASSERT_EQ(localization.Translate(ET_Left), "Left");
	localization.AddTranslation(Lang::English, ET_Left, "Rêchts");
	ASSERT_EQ(localization.Translate(ET_Left), "Rêchts");
}
