#include "UETranslations.h"

#include "Localization.h"

#include <format>
#include <KeyBindHelper.h>
#include <sstream>

ArcdpsExtension::UETranslation mapKeyControlToTranslationKeys(KeyBinds::KeyControl pKeyControl) {
	switch (pKeyControl) {
		case KeyBinds::KeyControl::Movement_MoveForward: return ArcdpsExtension::UETranslation::UE_Movement_MoveForward;
		case KeyBinds::KeyControl::Movement_MoveBackward: return ArcdpsExtension::UETranslation::UE_Movement_MoveBackward;
		case KeyBinds::KeyControl::Movement_StrafeLeft: return ArcdpsExtension::UETranslation::UE_Movement_StrafeLeft;
		case KeyBinds::KeyControl::Movement_StrafeRight: return ArcdpsExtension::UETranslation::UE_Movement_StrafeRight;
		case KeyBinds::KeyControl::Movement_TurnLeft: return ArcdpsExtension::UETranslation::UE_Movement_TurnLeft;
		case KeyBinds::KeyControl::Movement_TurnRight: return ArcdpsExtension::UETranslation::UE_Movement_TurnRight;
		case KeyBinds::KeyControl::Movement_Dodge: return ArcdpsExtension::UETranslation::UE_Movement_Dodge;
		case KeyBinds::KeyControl::Movement_Autorun: return ArcdpsExtension::UETranslation::UE_Movement_Autorun;
		case KeyBinds::KeyControl::Movement_Walk: return ArcdpsExtension::UETranslation::UE_Movement_Walk;
		case KeyBinds::KeyControl::Movement_Jump: return ArcdpsExtension::UETranslation::UE_Movement_Jump;
		case KeyBinds::KeyControl::Movement_SwimUp: return ArcdpsExtension::UETranslation::UE_Movement_SwimUp;
		case KeyBinds::KeyControl::Movement_SwimDown: return ArcdpsExtension::UETranslation::UE_Movement_SwimDown;
		case KeyBinds::KeyControl::Movement_AboutFace: return ArcdpsExtension::UETranslation::UE_Movement_AboutFace;
		case KeyBinds::KeyControl::Skills_SwapWeapons: return ArcdpsExtension::UETranslation::UE_Skills_SwapWeapons;
		case KeyBinds::KeyControl::Skills_WeaponSkill1: return ArcdpsExtension::UETranslation::UE_Skills_WeaponSkill1;
		case KeyBinds::KeyControl::Skills_WeaponSkill2: return ArcdpsExtension::UETranslation::UE_Skills_WeaponSkill2;
		case KeyBinds::KeyControl::Skills_WeaponSkill3: return ArcdpsExtension::UETranslation::UE_Skills_WeaponSkill3;
		case KeyBinds::KeyControl::Skills_WeaponSkill4: return ArcdpsExtension::UETranslation::UE_Skills_WeaponSkill4;
		case KeyBinds::KeyControl::Skills_WeaponSkill5: return ArcdpsExtension::UETranslation::UE_Skills_WeaponSkill5;
		case KeyBinds::KeyControl::Skills_HealingSkill: return ArcdpsExtension::UETranslation::UE_Skills_HealingSkill;
		case KeyBinds::KeyControl::Skills_UtilitySkill1: return ArcdpsExtension::UETranslation::UE_Skills_UtilitySkill1;
		case KeyBinds::KeyControl::Skills_UtilitySkill2: return ArcdpsExtension::UETranslation::UE_Skills_UtilitySkill2;
		case KeyBinds::KeyControl::Skills_UtilitySkill3: return ArcdpsExtension::UETranslation::UE_Skills_UtilitySkill3;
		case KeyBinds::KeyControl::Skills_EliteSkill: return ArcdpsExtension::UETranslation::UE_Skills_EliteSkill;
		case KeyBinds::KeyControl::Skills_ProfessionSkill1: return ArcdpsExtension::UETranslation::UE_Skills_ProfessionSkill1;
		case KeyBinds::KeyControl::Skills_ProfessionSkill2: return ArcdpsExtension::UETranslation::UE_Skills_ProfessionSkill2;
		case KeyBinds::KeyControl::Skills_ProfessionSkill3: return ArcdpsExtension::UETranslation::UE_Skills_ProfessionSkill3;
		case KeyBinds::KeyControl::Skills_ProfessionSkill4: return ArcdpsExtension::UETranslation::UE_Skills_ProfessionSkill4;
		case KeyBinds::KeyControl::Skills_ProfessionSkill5: return ArcdpsExtension::UETranslation::UE_Skills_ProfessionSkill5;
		case KeyBinds::KeyControl::Skills_ProfessionSkill6: return ArcdpsExtension::UETranslation::UE_Skills_ProfessionSkill6;
		case KeyBinds::KeyControl::Skills_ProfessionSkill7: return ArcdpsExtension::UETranslation::UE_Skills_ProfessionSkill7;
		case KeyBinds::KeyControl::Skills_SpecialAction: return ArcdpsExtension::UETranslation::UE_Skills_SpecialAction;
		case KeyBinds::KeyControl::Targeting_AlertTarget: return ArcdpsExtension::UETranslation::UE_Targeting_AlertTarget;
		case KeyBinds::KeyControl::Targeting_CallTarget: return ArcdpsExtension::UETranslation::UE_Targeting_CallTarget;
		case KeyBinds::KeyControl::Targeting_TakeTarget: return ArcdpsExtension::UETranslation::UE_Targeting_TakeTarget;
		case KeyBinds::KeyControl::Targeting_SetPersonalTarget: return ArcdpsExtension::UETranslation::UE_Targeting_SetPersonalTarget;
		case KeyBinds::KeyControl::Targeting_TakePersonalTarget: return ArcdpsExtension::UETranslation::UE_Targeting_TakePersonalTarget;
		case KeyBinds::KeyControl::Targeting_NearestEnemy: return ArcdpsExtension::UETranslation::UE_Targeting_NearestEnemy;
		case KeyBinds::KeyControl::Targeting_NextEnemy: return ArcdpsExtension::UETranslation::UE_Targeting_NextEnemy;
		case KeyBinds::KeyControl::Targeting_PreviousEnemy: return ArcdpsExtension::UETranslation::UE_Targeting_PreviousEnemy;
		case KeyBinds::KeyControl::Targeting_NearestAlly: return ArcdpsExtension::UETranslation::UE_Targeting_NearestAlly;
		case KeyBinds::KeyControl::Targeting_NextAlly: return ArcdpsExtension::UETranslation::UE_Targeting_NextAlly;
		case KeyBinds::KeyControl::Targeting_PreviousAlly: return ArcdpsExtension::UETranslation::UE_Targeting_PreviousAlly;
		case KeyBinds::KeyControl::Targeting_LockAutotarget: return ArcdpsExtension::UETranslation::UE_Targeting_LockAutotarget;
		case KeyBinds::KeyControl::Targeting_SnapGroundTarget: return ArcdpsExtension::UETranslation::UE_Targeting_SnapGroundTarget;
		case KeyBinds::KeyControl::Targeting_ToggleSnapGroundTarget: return ArcdpsExtension::UETranslation::UE_Targeting_ToggleSnapGroundTarget;
		case KeyBinds::KeyControl::Targeting_DisableAutotargeting: return ArcdpsExtension::UETranslation::UE_Targeting_DisableAutotargeting;
		case KeyBinds::KeyControl::Targeting_ToggleAutotargeting: return ArcdpsExtension::UETranslation::UE_Targeting_ToggleAutotargeting;
		case KeyBinds::KeyControl::Targeting_AllyTargetingMode: return ArcdpsExtension::UETranslation::UE_Targeting_AllyTargetingMode;
		case KeyBinds::KeyControl::Targeting_ToggleAllyTargetingMode: return ArcdpsExtension::UETranslation::UE_Targeting_ToggleAllyTargetingMode;
		case KeyBinds::KeyControl::UI_BlackLionTradingDialog: return ArcdpsExtension::UETranslation::UE_UI_BlackLionTradingDialog;
		case KeyBinds::KeyControl::UI_ContactsDialog: return ArcdpsExtension::UETranslation::UE_UI_ContactsDialog;
		case KeyBinds::KeyControl::UI_GuildDialog: return ArcdpsExtension::UETranslation::UE_UI_GuildDialog;
		case KeyBinds::KeyControl::UI_HeroDialog: return ArcdpsExtension::UETranslation::UE_UI_HeroDialog;
		case KeyBinds::KeyControl::UI_InventoryDialog: return ArcdpsExtension::UETranslation::UE_UI_InventoryDialog;
		case KeyBinds::KeyControl::UI_PetDialog: return ArcdpsExtension::UETranslation::UE_UI_PetDialog;
		case KeyBinds::KeyControl::UI_LogOut: return ArcdpsExtension::UETranslation::UE_UI_LogOut;
		case KeyBinds::KeyControl::UI_MailDialog: return ArcdpsExtension::UETranslation::UE_UI_MailDialog;
		case KeyBinds::KeyControl::UI_OptionsDialog: return ArcdpsExtension::UETranslation::UE_UI_OptionsDialog;
		case KeyBinds::KeyControl::UI_PartyDialog: return ArcdpsExtension::UETranslation::UE_UI_PartyDialog;
		case KeyBinds::KeyControl::UI_PvPPanel: return ArcdpsExtension::UETranslation::UE_UI_PvPPanel;
		case KeyBinds::KeyControl::UI_PvPBuild: return ArcdpsExtension::UETranslation::UE_UI_PvPBuild;
		case KeyBinds::KeyControl::UI_Scoreboard: return ArcdpsExtension::UETranslation::UE_UI_Scoreboard;
		case KeyBinds::KeyControl::UI_WizardsVaultDialog: return ArcdpsExtension::UETranslation::UE_UI_WizardsVaultDialog;
		case KeyBinds::KeyControl::UI_InformationDialog: return ArcdpsExtension::UETranslation::UE_UI_InformationDialog;
		case KeyBinds::KeyControl::UI_Show_HideChat: return ArcdpsExtension::UETranslation::UE_UI_Show_HideChat;
		case KeyBinds::KeyControl::UI_ChatCommand: return ArcdpsExtension::UETranslation::UE_UI_ChatCommand;
		case KeyBinds::KeyControl::UI_ChatMessage: return ArcdpsExtension::UETranslation::UE_UI_ChatMessage;
		case KeyBinds::KeyControl::UI_ChatReply: return ArcdpsExtension::UETranslation::UE_UI_ChatReply;
		case KeyBinds::KeyControl::UI_ShowHideUI: return ArcdpsExtension::UETranslation::UE_UI_ShowHideUI;
		case KeyBinds::KeyControl::UI_ShowHideSquadBroadcastChat: return ArcdpsExtension::UETranslation::UE_UI_ShowHideSquadBroadcastChat;
		case KeyBinds::KeyControl::UI_SquadBroadcastChatCommand: return ArcdpsExtension::UETranslation::UE_UI_SquadBroadcastChatCommand;
		case KeyBinds::KeyControl::UI_SquadBroadcastMessage: return ArcdpsExtension::UETranslation::UE_UI_SquadBroadcastMessage;
		case KeyBinds::KeyControl::Camera_FreeCamera: return ArcdpsExtension::UETranslation::UE_Camera_FreeCamera;
		case KeyBinds::KeyControl::Camera_ZoomIn: return ArcdpsExtension::UETranslation::UE_Camera_ZoomIn;
		case KeyBinds::KeyControl::Camera_ZoomOut: return ArcdpsExtension::UETranslation::UE_Camera_ZoomOut;
		case KeyBinds::KeyControl::Camera_LookBehind: return ArcdpsExtension::UETranslation::UE_Camera_LookBehind;
		case KeyBinds::KeyControl::Camera_ToggleActionCamera: return ArcdpsExtension::UETranslation::UE_Camera_ToggleActionCamera;
		case KeyBinds::KeyControl::Camera_DisableActionCamera: return ArcdpsExtension::UETranslation::UE_Camera_DisableActionCamera;
		case KeyBinds::KeyControl::Screenshot_Normal: return ArcdpsExtension::UETranslation::UE_Screenshot_Normal;
		case KeyBinds::KeyControl::Screenshot_Stereoscopic: return ArcdpsExtension::UETranslation::UE_Screenshot_Stereoscopic;
		case KeyBinds::KeyControl::Map_OpenClose: return ArcdpsExtension::UETranslation::UE_Map_OpenClose;
		case KeyBinds::KeyControl::Map_Recenter: return ArcdpsExtension::UETranslation::UE_Map_Recenter;
		case KeyBinds::KeyControl::Map_FloorDown: return ArcdpsExtension::UETranslation::UE_Map_FloorDown;
		case KeyBinds::KeyControl::Map_FloorUp: return ArcdpsExtension::UETranslation::UE_Map_FloorUp;
		case KeyBinds::KeyControl::Map_ZoomIn: return ArcdpsExtension::UETranslation::UE_Map_ZoomIn;
		case KeyBinds::KeyControl::Map_ZoomOut: return ArcdpsExtension::UETranslation::UE_Map_ZoomOut;
		case KeyBinds::KeyControl::Mounts_MountDismount: return ArcdpsExtension::UETranslation::UE_Mounts_MountDismount;
		case KeyBinds::KeyControl::Mounts_MountAbility1: return ArcdpsExtension::UETranslation::UE_Mounts_MountAbility1;
		case KeyBinds::KeyControl::Mounts_MountAbility2: return ArcdpsExtension::UETranslation::UE_Mounts_MountAbility2;
		case KeyBinds::KeyControl::Mounts_Raptor: return ArcdpsExtension::UETranslation::UE_Mounts_Raptor;
		case KeyBinds::KeyControl::Mounts_Springer: return ArcdpsExtension::UETranslation::UE_Mounts_Springer;
		case KeyBinds::KeyControl::Mounts_Skimmer: return ArcdpsExtension::UETranslation::UE_Mounts_Skimmer;
		case KeyBinds::KeyControl::Mounts_Jackal: return ArcdpsExtension::UETranslation::UE_Mounts_Jackal;
		case KeyBinds::KeyControl::Mounts_Griffon: return ArcdpsExtension::UETranslation::UE_Mounts_Griffon;
		case KeyBinds::KeyControl::Mounts_RollerBeetle: return ArcdpsExtension::UETranslation::UE_Mounts_RollerBeetle;
		case KeyBinds::KeyControl::Mounts_Warclaw: return ArcdpsExtension::UETranslation::UE_Mounts_Warclaw;
		case KeyBinds::KeyControl::Mounts_Skyscale: return ArcdpsExtension::UETranslation::UE_Mounts_Skyscale;
		case KeyBinds::KeyControl::Mounts_Turtle: return ArcdpsExtension::UETranslation::UE_Mounts_Turtle;
		case KeyBinds::KeyControl::Spectators_NearestFixedCamera: return ArcdpsExtension::UETranslation::UE_Spectators_NearestFixedCamera;
		case KeyBinds::KeyControl::Spectators_NearestPlayer: return ArcdpsExtension::UETranslation::UE_Spectators_NearestPlayer;
		case KeyBinds::KeyControl::Spectators_RedPlayer1: return ArcdpsExtension::UETranslation::UE_Spectators_RedPlayer1;
		case KeyBinds::KeyControl::Spectators_RedPlayer2: return ArcdpsExtension::UETranslation::UE_Spectators_RedPlayer2;
		case KeyBinds::KeyControl::Spectators_RedPlayer3: return ArcdpsExtension::UETranslation::UE_Spectators_RedPlayer3;
		case KeyBinds::KeyControl::Spectators_RedPlayer4: return ArcdpsExtension::UETranslation::UE_Spectators_RedPlayer4;
		case KeyBinds::KeyControl::Spectators_RedPlayer5: return ArcdpsExtension::UETranslation::UE_Spectators_RedPlayer5;
		case KeyBinds::KeyControl::Spectators_BluePlayer1: return ArcdpsExtension::UETranslation::UE_Spectators_BluePlayer1;
		case KeyBinds::KeyControl::Spectators_BluePlayer2: return ArcdpsExtension::UETranslation::UE_Spectators_BluePlayer2;
		case KeyBinds::KeyControl::Spectators_BluePlayer3: return ArcdpsExtension::UETranslation::UE_Spectators_BluePlayer3;
		case KeyBinds::KeyControl::Spectators_BluePlayer4: return ArcdpsExtension::UETranslation::UE_Spectators_BluePlayer4;
		case KeyBinds::KeyControl::Spectators_BluePlayer5: return ArcdpsExtension::UETranslation::UE_Spectators_BluePlayer5;
		case KeyBinds::KeyControl::Spectators_FreeCamera: return ArcdpsExtension::UETranslation::UE_Spectators_FreeCamera;
		case KeyBinds::KeyControl::Spectators_FreeCameraBoost: return ArcdpsExtension::UETranslation::UE_Spectators_FreeCameraBoost;
		case KeyBinds::KeyControl::Spectators_FreeCameraForward: return ArcdpsExtension::UETranslation::UE_Spectators_FreeCameraForward;
		case KeyBinds::KeyControl::Spectators_FreeCameraBackward: return ArcdpsExtension::UETranslation::UE_Spectators_FreeCameraBackward;
		case KeyBinds::KeyControl::Spectators_FreeCameraLeft: return ArcdpsExtension::UETranslation::UE_Spectators_FreeCameraLeft;
		case KeyBinds::KeyControl::Spectators_FreeCameraRight: return ArcdpsExtension::UETranslation::UE_Spectators_FreeCameraRight;
		case KeyBinds::KeyControl::Spectators_FreeCameraUp: return ArcdpsExtension::UETranslation::UE_Spectators_FreeCameraUp;
		case KeyBinds::KeyControl::Spectators_FreeCameraDown: return ArcdpsExtension::UETranslation::UE_Spectators_FreeCameraDown;
		case KeyBinds::KeyControl::Squad_Location_Arrow: return ArcdpsExtension::UETranslation::UE_Squad_Location_Arrow;
		case KeyBinds::KeyControl::Squad_Location_Circle: return ArcdpsExtension::UETranslation::UE_Squad_Location_Circle;
		case KeyBinds::KeyControl::Squad_Location_Heart: return ArcdpsExtension::UETranslation::UE_Squad_Location_Heart;
		case KeyBinds::KeyControl::Squad_Location_Square: return ArcdpsExtension::UETranslation::UE_Squad_Location_Square;
		case KeyBinds::KeyControl::Squad_Location_Star: return ArcdpsExtension::UETranslation::UE_Squad_Location_Star;
		case KeyBinds::KeyControl::Squad_Location_Spiral: return ArcdpsExtension::UETranslation::UE_Squad_Location_Spiral;
		case KeyBinds::KeyControl::Squad_Location_Triangle: return ArcdpsExtension::UETranslation::UE_Squad_Location_Triangle;
		case KeyBinds::KeyControl::Squad_Location_X: return ArcdpsExtension::UETranslation::UE_Squad_Location_X;
		case KeyBinds::KeyControl::Squad_ClearAllLocationMarkers: return ArcdpsExtension::UETranslation::UE_Squad_ClearAllLocationMarkers;
		case KeyBinds::KeyControl::Squad_Object_Arrow: return ArcdpsExtension::UETranslation::UE_Squad_Object_Arrow;
		case KeyBinds::KeyControl::Squad_Object_Circle: return ArcdpsExtension::UETranslation::UE_Squad_Object_Circle;
		case KeyBinds::KeyControl::Squad_Object_Heart: return ArcdpsExtension::UETranslation::UE_Squad_Object_Heart;
		case KeyBinds::KeyControl::Squad_Object_Square: return ArcdpsExtension::UETranslation::UE_Squad_Object_Square;
		case KeyBinds::KeyControl::Squad_Object_Star: return ArcdpsExtension::UETranslation::UE_Squad_Object_Star;
		case KeyBinds::KeyControl::Squad_Object_Spiral: return ArcdpsExtension::UETranslation::UE_Squad_Object_Spiral;
		case KeyBinds::KeyControl::Squad_Object_Triangle: return ArcdpsExtension::UETranslation::UE_Squad_Object_Triangle;
		case KeyBinds::KeyControl::Squad_Object_X: return ArcdpsExtension::UETranslation::UE_Squad_Object_X;
		case KeyBinds::KeyControl::Squad_ClearAllObjectMarkers: return ArcdpsExtension::UETranslation::UE_Squad_ClearAllObjectMarkers;
		case KeyBinds::KeyControl::MasterySkills_ActivateMasterySkill: return ArcdpsExtension::UETranslation::UE_MasterySkills_ActivateMasterySkill;
		case KeyBinds::KeyControl::MasterySkills_StartFishing: return ArcdpsExtension::UETranslation::UE_MasterySkills_StartFishing;
		case KeyBinds::KeyControl::MasterySkills_SummonSkiff: return ArcdpsExtension::UETranslation::UE_MasterySkills_SummonSkiff;
		case KeyBinds::KeyControl::MasterySkills_SetJadeBotWaypoint: return ArcdpsExtension::UETranslation::UE_MasterySkills_SetJadeBotWaypoint;
		case KeyBinds::KeyControl::MasterySkills_ScanForRift: return ArcdpsExtension::UETranslation::UE_MasterySkills_ScanForRift;
		case KeyBinds::KeyControl::MasterySkills_SkyscaleLeap: return ArcdpsExtension::UETranslation::UE_MasterySkills_SkyscaleLeap;
		case KeyBinds::KeyControl::MasterySkills_ConjuredDoorway: return ArcdpsExtension::UETranslation::UE_MasterySkills_ConjuredDoorway;
		case KeyBinds::KeyControl::Miscellaneous_AoELoot: return ArcdpsExtension::UETranslation::UE_Miscellaneous_AoELoot;
		case KeyBinds::KeyControl::Miscellaneous_Interact: return ArcdpsExtension::UETranslation::UE_Miscellaneous_Interact;
		case KeyBinds::KeyControl::Miscellaneous_ShowEnemyNames: return ArcdpsExtension::UETranslation::UE_Miscellaneous_ShowEnemyNames;
		case KeyBinds::KeyControl::Miscellaneous_ShowAllyNames: return ArcdpsExtension::UETranslation::UE_Miscellaneous_ShowAllyNames;
		case KeyBinds::KeyControl::Miscellaneous_StowDrawWeapon: return ArcdpsExtension::UETranslation::UE_Miscellaneous_StowDrawWeapon;
		case KeyBinds::KeyControl::Miscellaneous_ToggleLanguage: return ArcdpsExtension::UETranslation::UE_Miscellaneous_ToggleLanguage;
		case KeyBinds::KeyControl::Miscellaneous_RangerPetCombatToggle: return ArcdpsExtension::UETranslation::UE_Miscellaneous_RangerPetCombatToggle;
		case KeyBinds::KeyControl::Miscellaneous_ToggleFullScreen: return ArcdpsExtension::UETranslation::UE_Miscellaneous_ToggleFullScreen;
		case KeyBinds::KeyControl::Miscellaneous_EquipUnequipNovelty: return ArcdpsExtension::UETranslation::UE_Miscellaneous_EquipUnequipNovelty;
		case KeyBinds::KeyControl::Miscellaneous_ActivateChair: return ArcdpsExtension::UETranslation::UE_Miscellaneous_ActivateChair;
		case KeyBinds::KeyControl::Miscellaneous_ActivateMusicalInstrument: return ArcdpsExtension::UETranslation::UE_Miscellaneous_ActivateMusicalInstrument;
		case KeyBinds::KeyControl::Miscellaneous_ActivateHeldItem: return ArcdpsExtension::UETranslation::UE_Miscellaneous_ActivateHeldItem;
		case KeyBinds::KeyControl::Miscellaneous_ActivateToy: return ArcdpsExtension::UETranslation::UE_Miscellaneous_ActivateToy;
		case KeyBinds::KeyControl::Miscellaneous_ActivateTonic: return ArcdpsExtension::UETranslation::UE_Miscellaneous_ActivateTonic;
		case KeyBinds::KeyControl::Miscellaneous_DecorateModeToggle: return ArcdpsExtension::UETranslation::UE_Miscellaneous_DecorateModeToggle;
		case KeyBinds::KeyControl::Templates_BuildTemplate1: return ArcdpsExtension::UETranslation::UE_Templates_BuildTemplate1;
		case KeyBinds::KeyControl::Templates_BuildTemplate2: return ArcdpsExtension::UETranslation::UE_Templates_BuildTemplate2;
		case KeyBinds::KeyControl::Templates_BuildTemplate3: return ArcdpsExtension::UETranslation::UE_Templates_BuildTemplate3;
		case KeyBinds::KeyControl::Templates_BuildTemplate4: return ArcdpsExtension::UETranslation::UE_Templates_BuildTemplate4;
		case KeyBinds::KeyControl::Templates_BuildTemplate5: return ArcdpsExtension::UETranslation::UE_Templates_BuildTemplate5;
		case KeyBinds::KeyControl::Templates_BuildTemplate6: return ArcdpsExtension::UETranslation::UE_Templates_BuildTemplate6;
		case KeyBinds::KeyControl::Templates_BuildTemplate7: return ArcdpsExtension::UETranslation::UE_Templates_BuildTemplate7;
		case KeyBinds::KeyControl::Templates_BuildTemplate8: return ArcdpsExtension::UETranslation::UE_Templates_BuildTemplate8;
		case KeyBinds::KeyControl::Templates_BuildTemplate9: return ArcdpsExtension::UETranslation::UE_Templates_BuildTemplate9;
		case KeyBinds::KeyControl::Templates_EquipmentTemplate1: return ArcdpsExtension::UETranslation::UE_Templates_EquipmentTemplate1;
		case KeyBinds::KeyControl::Templates_EquipmentTemplate2: return ArcdpsExtension::UETranslation::UE_Templates_EquipmentTemplate2;
		case KeyBinds::KeyControl::Templates_EquipmentTemplate3: return ArcdpsExtension::UETranslation::UE_Templates_EquipmentTemplate3;
		case KeyBinds::KeyControl::Templates_EquipmentTemplate4: return ArcdpsExtension::UETranslation::UE_Templates_EquipmentTemplate4;
		case KeyBinds::KeyControl::Templates_EquipmentTemplate5: return ArcdpsExtension::UETranslation::UE_Templates_EquipmentTemplate5;
		case KeyBinds::KeyControl::Templates_EquipmentTemplate6: return ArcdpsExtension::UETranslation::UE_Templates_EquipmentTemplate6;
		case KeyBinds::KeyControl::Templates_EquipmentTemplate7: return ArcdpsExtension::UETranslation::UE_Templates_EquipmentTemplate7;
		case KeyBinds::KeyControl::Templates_EquipmentTemplate8: return ArcdpsExtension::UETranslation::UE_Templates_EquipmentTemplate8;
		case KeyBinds::KeyControl::Templates_EquipmentTemplate9: return ArcdpsExtension::UETranslation::UE_Templates_EquipmentTemplate9;
		case KeyBinds::KeyControl::Templates_FashionTemplate1: return ArcdpsExtension::UETranslation::UE_Templates_FashionTemplate1;
		case KeyBinds::KeyControl::Templates_FashionTemplate2: return ArcdpsExtension::UETranslation::UE_Templates_FashionTemplate2;
		case KeyBinds::KeyControl::Templates_FashionTemplate3: return ArcdpsExtension::UETranslation::UE_Templates_FashionTemplate3;
		case KeyBinds::KeyControl::Templates_FashionTemplate4: return ArcdpsExtension::UETranslation::UE_Templates_FashionTemplate4;
		case KeyBinds::KeyControl::Templates_FashionTemplate5: return ArcdpsExtension::UETranslation::UE_Templates_FashionTemplate5;
		case KeyBinds::KeyControl::Templates_FashionTemplate6: return ArcdpsExtension::UETranslation::UE_Templates_FashionTemplate6;
		case KeyBinds::KeyControl::Templates_FashionTemplate7: return ArcdpsExtension::UETranslation::UE_Templates_FashionTemplate7;
		case KeyBinds::KeyControl::Templates_FashionTemplate8: return ArcdpsExtension::UETranslation::UE_Templates_FashionTemplate8;
		case KeyBinds::KeyControl::Templates_FashionTemplate9: return ArcdpsExtension::UETranslation::UE_Templates_FashionTemplate9;
	}
	std::unreachable();
}

ArcdpsExtension::UETranslation mapKeyCodeToTranslationKeys(KeyBinds::KeyCode pKeyCode) {
	switch (pKeyCode) {
		case KeyBinds::KeyCode::LeftAlt:
			return ArcdpsExtension::UETranslation::UE_LeftAlt;
		case KeyBinds::KeyCode::LeftCtrl:
			return ArcdpsExtension::UETranslation::UE_LeftCtrl;
		case KeyBinds::KeyCode::LeftShift:
			return ArcdpsExtension::UETranslation::UE_LeftShift;
		case KeyBinds::KeyCode::CapsLock:
			return ArcdpsExtension::UETranslation::UE_CapsLock;
		case KeyBinds::KeyCode::Escape:
			return ArcdpsExtension::UETranslation::UE_Escape;
		case KeyBinds::KeyCode::NumLock:
			return ArcdpsExtension::UETranslation::UE_NumLock;
		case KeyBinds::KeyCode::Backspace:
			return ArcdpsExtension::UETranslation::UE_Backspace;
		case KeyBinds::KeyCode::Delete:
			return ArcdpsExtension::UETranslation::UE_Delete;
		case KeyBinds::KeyCode::Enter:
			return ArcdpsExtension::UETranslation::UE_Enter;
		case KeyBinds::KeyCode::Space:
			return ArcdpsExtension::UETranslation::UE_Space;
		case KeyBinds::KeyCode::Tab:
			return ArcdpsExtension::UETranslation::UE_Tab;
		case KeyBinds::KeyCode::End:
			return ArcdpsExtension::UETranslation::UE_End;
		case KeyBinds::KeyCode::Home:
			return ArcdpsExtension::UETranslation::UE_Home;
		case KeyBinds::KeyCode::Insert:
			return ArcdpsExtension::UETranslation::UE_Insert;
		case KeyBinds::KeyCode::Next:
			return ArcdpsExtension::UETranslation::UE_Next;
		case KeyBinds::KeyCode::Prior:
			return ArcdpsExtension::UETranslation::UE_Prior;
		case KeyBinds::KeyCode::ArrowDown:
			return ArcdpsExtension::UETranslation::UE_ArrowDown;
		case KeyBinds::KeyCode::ArrowLeft:
			return ArcdpsExtension::UETranslation::UE_ArrowLeft;
		case KeyBinds::KeyCode::ArrowRight:
			return ArcdpsExtension::UETranslation::UE_ArrowRight;
		case KeyBinds::KeyCode::ArrowUp:
			return ArcdpsExtension::UETranslation::UE_ArrowUp;
		case KeyBinds::KeyCode::F1:
			return ArcdpsExtension::UETranslation::UE_F1;
		case KeyBinds::KeyCode::F2:
			return ArcdpsExtension::UETranslation::UE_F2;
		case KeyBinds::KeyCode::F3:
			return ArcdpsExtension::UETranslation::UE_F3;
		case KeyBinds::KeyCode::F4:
			return ArcdpsExtension::UETranslation::UE_F4;
		case KeyBinds::KeyCode::F5:
			return ArcdpsExtension::UETranslation::UE_F5;
		case KeyBinds::KeyCode::F6:
			return ArcdpsExtension::UETranslation::UE_F6;
		case KeyBinds::KeyCode::F7:
			return ArcdpsExtension::UETranslation::UE_F7;
		case KeyBinds::KeyCode::F8:
			return ArcdpsExtension::UETranslation::UE_F8;
		case KeyBinds::KeyCode::F9:
			return ArcdpsExtension::UETranslation::UE_F9;
		case KeyBinds::KeyCode::F10:
			return ArcdpsExtension::UETranslation::UE_F10;
		case KeyBinds::KeyCode::F11:
			return ArcdpsExtension::UETranslation::UE_F11;
		case KeyBinds::KeyCode::F12:
			return ArcdpsExtension::UETranslation::UE_F12;
		case KeyBinds::KeyCode::F13:
			return ArcdpsExtension::UETranslation::UE_F13;
		case KeyBinds::KeyCode::F14:
			return ArcdpsExtension::UETranslation::UE_F14;
		case KeyBinds::KeyCode::F15:
			return ArcdpsExtension::UETranslation::UE_F15;
		case KeyBinds::KeyCode::F16:
			return ArcdpsExtension::UETranslation::UE_F16;
		case KeyBinds::KeyCode::F17:
			return ArcdpsExtension::UETranslation::UE_F17;
		case KeyBinds::KeyCode::F18:
			return ArcdpsExtension::UETranslation::UE_F18;
		case KeyBinds::KeyCode::F19:
			return ArcdpsExtension::UETranslation::UE_F19;
		case KeyBinds::KeyCode::F20:
			return ArcdpsExtension::UETranslation::UE_F20;
		case KeyBinds::KeyCode::F21:
			return ArcdpsExtension::UETranslation::UE_F21;
		case KeyBinds::KeyCode::F22:
			return ArcdpsExtension::UETranslation::UE_F22;
		case KeyBinds::KeyCode::F23:
			return ArcdpsExtension::UETranslation::UE_F23;
		case KeyBinds::KeyCode::F24:
			return ArcdpsExtension::UETranslation::UE_F24;
		case KeyBinds::KeyCode::F25:
			return ArcdpsExtension::UETranslation::UE_F25;
		case KeyBinds::KeyCode::F26:
			return ArcdpsExtension::UETranslation::UE_F26;
		case KeyBinds::KeyCode::F27:
			return ArcdpsExtension::UETranslation::UE_F27;
		case KeyBinds::KeyCode::F28:
			return ArcdpsExtension::UETranslation::UE_F28;
		case KeyBinds::KeyCode::F29:
			return ArcdpsExtension::UETranslation::UE_F29;
		case KeyBinds::KeyCode::F30:
			return ArcdpsExtension::UETranslation::UE_F30;
		case KeyBinds::KeyCode::F31:
			return ArcdpsExtension::UETranslation::UE_F31;
		case KeyBinds::KeyCode::F32:
			return ArcdpsExtension::UETranslation::UE_F32;
		case KeyBinds::KeyCode::F33:
			return ArcdpsExtension::UETranslation::UE_F33;
		case KeyBinds::KeyCode::F34:
			return ArcdpsExtension::UETranslation::UE_F34;
		case KeyBinds::KeyCode::F35:
			return ArcdpsExtension::UETranslation::UE_F35;
		case KeyBinds::KeyCode::PlusNum:
			return ArcdpsExtension::UETranslation::UE_PlusNum;
		case KeyBinds::KeyCode::DecimalNum:
			return ArcdpsExtension::UETranslation::UE_DecimalNum;
		case KeyBinds::KeyCode::DivideNum:
			return ArcdpsExtension::UETranslation::UE_DivideNum;
		case KeyBinds::KeyCode::MultiplyNum:
			return ArcdpsExtension::UETranslation::UE_MultiplyNum;
		case KeyBinds::KeyCode::_0_NUM:
			return ArcdpsExtension::UETranslation::UE_0_NUM;
		case KeyBinds::KeyCode::_1_NUM:
			return ArcdpsExtension::UETranslation::UE_1_NUM;
		case KeyBinds::KeyCode::_2_NUM:
			return ArcdpsExtension::UETranslation::UE_2_NUM;
		case KeyBinds::KeyCode::_3_NUM:
			return ArcdpsExtension::UETranslation::UE_3_NUM;
		case KeyBinds::KeyCode::_4_NUM:
			return ArcdpsExtension::UETranslation::UE_4_NUM;
		case KeyBinds::KeyCode::_5_NUM:
			return ArcdpsExtension::UETranslation::UE_5_NUM;
		case KeyBinds::KeyCode::_6_NUM:
			return ArcdpsExtension::UETranslation::UE_6_NUM;
		case KeyBinds::KeyCode::_7_NUM:
			return ArcdpsExtension::UETranslation::UE_7_NUM;
		case KeyBinds::KeyCode::_8_NUM:
			return ArcdpsExtension::UETranslation::UE_8_NUM;
		case KeyBinds::KeyCode::_9_NUM:
			return ArcdpsExtension::UETranslation::UE_9_NUM;
		case KeyBinds::KeyCode::EnterNum:
			return ArcdpsExtension::UETranslation::UE_EnterNum;
		case KeyBinds::KeyCode::MinusNum:
			return ArcdpsExtension::UETranslation::UE_MinusNum;
		case KeyBinds::KeyCode::ImeKey1:
			return ArcdpsExtension::UETranslation::UE_ImeKey1;
		case KeyBinds::KeyCode::ImeKey2:
			return ArcdpsExtension::UETranslation::UE_ImeKey2;
		case KeyBinds::KeyCode::RightAlt:
			return ArcdpsExtension::UETranslation::UE_RightAlt;
		case KeyBinds::KeyCode::RightCtrl:
			return ArcdpsExtension::UETranslation::UE_RightCtrl;
		case KeyBinds::KeyCode::RightShift:
			return ArcdpsExtension::UETranslation::UE_RightShift;
		case KeyBinds::KeyCode::Eject:
			return ArcdpsExtension::UETranslation::UE_Eject;
		case KeyBinds::KeyCode::EqualNum:
			return ArcdpsExtension::UETranslation::UE_EqualNum;
		case KeyBinds::KeyCode::ClearNum:
			return ArcdpsExtension::UETranslation::UE_ClearNum;
		case KeyBinds::KeyCode::LeftCmd:
			return ArcdpsExtension::UETranslation::UE_LeftCmd;
		case KeyBinds::KeyCode::Function:
			return ArcdpsExtension::UETranslation::UE_Function;
		case KeyBinds::KeyCode::RightCmd:
			return ArcdpsExtension::UETranslation::UE_RightCmd;
		case KeyBinds::KeyCode::Scroll:
			return ArcdpsExtension::UETranslation::UE_Scroll;
		case KeyBinds::KeyCode::Pause:
			return ArcdpsExtension::UETranslation::UE_Pause;
		case KeyBinds::KeyCode::LeftWin:
			return ArcdpsExtension::UETranslation::UE_LeftWin;
		case KeyBinds::KeyCode::RightWin:
			return ArcdpsExtension::UETranslation::UE_RightWin;
		case KeyBinds::KeyCode::Menu:
			return ArcdpsExtension::UETranslation::UE_Menu;
		default:
			return static_cast<ArcdpsExtension::UETranslation>(ArcdpsExtension::ExtensionTranslation::ET_Unknown);
	}
}

std::string_view to_string(KeyBinds::KeyControl pKeyControl) {
	auto key = mapKeyControlToTranslationKeys(pKeyControl);
	return ArcdpsExtension::Localization::STranslate(key);
}

std::string GetModifier(KeyBinds::Modifier pMod) {
	const auto& localization = ArcdpsExtension::Localization::instance();

	std::string res;

	if (pMod & KeyBinds::Modifier_Ctrl) {
		res.append(localization.Translate(ArcdpsExtension::UE_Modifier_Ctrl)).append(" + ");
	}
	if (pMod & KeyBinds::Modifier_Alt) {
		res.append(localization.Translate(ArcdpsExtension::UE_Modifier_Alt)).append(" + ");
	}
	if (pMod & KeyBinds::Modifier_Shift) {
		res.append(localization.Translate(ArcdpsExtension::UE_Modifier_Shift)).append(" + ");
	}
	return res;
}

std::string to_string(KeyBinds::Key pKeyBind, HKL pKeyboardLayout, bool pNotSetText) {
	if (pKeyBind.DeviceType == KeyBinds::DeviceType::Unset) {
		if (pNotSetText) {
			return std::string(ArcdpsExtension::Localization::STranslate(ArcdpsExtension::UE_Unset));
		}
		return "";
	}

	std::string res = GetModifier(pKeyBind.Modifier);

	if (pKeyBind.DeviceType == KeyBinds::DeviceType::Keyboard) {
		res.append(to_string(static_cast<KeyBinds::KeyCode>(pKeyBind.Code), pKeyboardLayout));
	} else if (pKeyBind.DeviceType == KeyBinds::DeviceType::Mouse) {
		res.append(to_string(static_cast<KeyBinds::MouseCode>(pKeyBind.Code)));
	}

	return res;
}

std::string to_string(KeyBinds::KeyCode pKeyCode, HKL pKeyboardLayout) {
	using KeyBinds::KeyCode;
	if (pKeyCode >= KeyCode::A && pKeyCode <= KeyCode::Z || pKeyCode >= KeyCode::_0 && pKeyCode <= KeyCode::_9) {
		UINT scanCode = KeyCodeToMsvcScanCode(pKeyCode);
		UINT keyExW = MapVirtualKeyExW(scanCode, MAPVK_VSC_TO_VK_EX, pKeyboardLayout);
		return std::string(1, static_cast<char>(keyExW));
	}
	// OEM keys (like Ä, Ö or #)
	if (pKeyCode == KeyCode::Tilde || pKeyCode == KeyCode::Minus || pKeyCode == KeyCode::Equals || pKeyCode == KeyCode::OpenBracket
		|| pKeyCode == KeyCode::CloseBracket || pKeyCode == KeyCode::Semicolon || pKeyCode == KeyCode::Quote || pKeyCode == KeyCode::Hash
		|| pKeyCode == KeyCode::Backslash || pKeyCode == KeyCode::Colon || pKeyCode == KeyCode::Period || pKeyCode == KeyCode::Slash) {
		UINT scanCode = KeyCodeToMsvcScanCode(pKeyCode);
		UINT keyExW = MapVirtualKeyExW(scanCode, MAPVK_VSC_TO_VK_EX, pKeyboardLayout);
		wchar_t shortCutRealNameWstr[32];
		constexpr byte keyState[256]{};
		int toUnicodeCount = ToUnicodeEx(keyExW, scanCode, keyState, shortCutRealNameWstr, 32, 1 << 2, pKeyboardLayout);

		// if dead key is hit, the count will be negative, but still contains the written symbol count
		toUnicodeCount = std::abs(toUnicodeCount);

		int count = WideCharToMultiByte(CP_UTF8, 0, shortCutRealNameWstr, toUnicodeCount, nullptr, 0, nullptr, nullptr);
		std::string str(count, 0);
		WideCharToMultiByte(CP_UTF8, 0, shortCutRealNameWstr, toUnicodeCount, str.data(), count, NULL, NULL);
		return str;
	}

	// translated by hand!
	auto trans = mapKeyCodeToTranslationKeys(pKeyCode);
	return std::string(ArcdpsExtension::Localization::STranslate(trans));
}

std::string to_string(KeyBinds::MouseCode pMouseCode) {
	using KeyBinds::MouseCode;
	auto key = static_cast<int32_t>(pMouseCode);
	auto mouse = ArcdpsExtension::Localization::STranslate(ArcdpsExtension::UE_Mouse);

	if (pMouseCode == MouseCode::Mouse_2) {
		// empty, cause we can use key directly
	} else if (pMouseCode == MouseCode::Mouse_3) {
		key = 3;
	} else {
		++key;
	}

	return std::format("{} {}", mouse, key);
}