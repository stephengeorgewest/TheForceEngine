#pragma once
//////////////////////////////////////////////////////////////////////
// Dark Forces Player -
// Player information and object data.
//////////////////////////////////////////////////////////////////////

#include <TFE_System/types.h>
#include <TFE_Asset/dfKeywords.h>
#include <TFE_Jedi/Level/rsector.h>
#include <TFE_Jedi/Level/robject.h>
#include <TFE_Jedi/Task/task.h>
#include <TFE_FileSystem/stream.h>
#include "sound.h"
#include "time.h"

struct ProjectileLogic;
struct Logic;

namespace TFE_DarkForces
{
	// TODO: Factor out the PlayerItems into a struct
	// so that it can be directly allocated and copied when saving the inventory for
	// Jabba's Ship.
	struct PlayerInfo
	{
		// Items
		//   Weapons
		JBool itemPistol;
		JBool itemRifle;
		JBool itemAutogun;
		JBool itemMortar;
		JBool itemFusion;
		JBool itemConcussion;
		JBool itemCannon;
		//   Keys
		JBool itemRedKey;
		JBool itemYellowKey;
		JBool itemBlueKey;
		JBool itemGoggles;
		JBool itemCleats;
		JBool itemMask;
		//   Inventory
		JBool itemPlans;
		JBool itemPhrik;
		JBool itemDatatape;
		JBool itemUnused;
		JBool itemNava;
		JBool itemDtWeapon;
		JBool itemCode1;
		JBool itemCode2;
		JBool itemCode3;
		JBool itemCode4;
		JBool itemCode5;
		JBool itemCode6;
		JBool itemCode7;
		JBool itemCode8;
		JBool itemCode9;
		//   Ammo
		s32 ammoEnergy;
		s32 ammoPower;
		s32 ammoPlasma;
		s32 ammoDetonator;
		s32 ammoShell;
		s32 ammoMine;
		s32 ammoMissile;
		//   Health & Shields
		s32 pileSaveMarker;
		s32 shields;
		s32 health;
		s32 healthFract;
		//   Weapon
		s32 newWeapon;
		s32 curWeapon;
		s32 maxWeapon;
		s32 saveWeapon;
	};

	extern PlayerInfo s_playerInfo;
	extern fixed16_16 s_batteryPower;
	extern s32 s_lifeCount;
	extern s32 s_playerLight;
	extern s32 s_headwaveVerticalOffset;
	extern s32 s_weaponLight;
	extern s32 s_baseAtten;
	extern s32 s_invincibility;
	extern JBool s_oneHitKillEnabled;
	extern JBool s_instaDeathEnabled;
	extern fixed16_16 s_gravityAccel;
	extern JBool s_weaponFiring;
	extern JBool s_weaponFiringSec;
	extern JBool s_wearingCleats;
	extern JBool s_wearingGasmask;
	extern JBool s_nightvisionActive;
	extern JBool s_headlampActive;
	extern JBool s_superCharge;
	extern JBool s_superChargeHud;
	extern JBool s_playerSecMoved;
	extern JBool s_aiActive;
	extern u32* s_playerInvSaved;
	// Eye parameters
	extern fixed16_16 s_playerHeight;
	extern fixed16_16 s_playerYPos;
	extern vec3_fixed s_eyePos;	// s_camX, s_camY, s_camZ in the DOS code.
	extern angle14_32 s_pitch, s_yaw, s_roll;
	extern angle14_32 s_playerYaw;
	extern Tick s_playerTick;
	extern Tick s_reviveTick;

	extern SecObject* s_playerObject;
	extern SecObject* s_playerEye;

	// Speed Modifiers
	extern s32 s_playerRun;
	extern s32 s_jumpScale;
	extern s32 s_playerSlow;
	extern s32 s_waterSpeed;

	extern Task* s_playerTask;

	// Sounds
	extern SoundSourceId s_landSplashSound;
	extern SoundSourceId s_landSolidSound;
	extern SoundSourceId s_gasDamageSoundSource;
	extern SoundSourceId s_maskSoundSource1;
	extern SoundSourceId s_maskSoundSource2;
	extern SoundSourceId s_invCountdownSound;
	extern SoundSourceId s_jumpSoundSource;
	extern SoundSourceId s_nightVisionActiveSoundSource;
	extern SoundSourceId s_nightVisionDeactiveSoundSource;
	extern SoundSourceId s_playerDeathSoundSource;
	extern SoundSourceId s_crushSoundSource;
	extern SoundSourceId s_playerHealthHitSoundSource;
	extern SoundSourceId s_kyleScreamSoundSource;
	extern SoundSourceId s_playerShieldHitSoundSource;

	void player_init();
	void player_readInfo(u8* inv, s32* ammo);
	void player_writeInfo(u8* inv, s32* ammo);
	void player_clearEyeObject();
	void player_createController(JBool clearData = JTRUE);
	void player_setupObject(SecObject* obj);
	void player_setupEyeObject(SecObject* obj);
	void player_revive();
	s32  player_getLifeCount();
	void player_getVelocity(vec3_fixed* vel);
	fixed16_16 player_getSquaredDistance(SecObject* obj);
	void player_setupCamera();
	void player_applyDamage(fixed16_16 healthDmg, fixed16_16 shieldDmg, JBool playHitSound);

	JBool player_hasWeapon(s32 weaponIndex);
	JBool player_hasItem(s32 itemIndex);

	void computeExplosionPushDir(vec3_fixed* pos, vec3_fixed* pushDir);
	void computeDamagePushVelocity(ProjectileLogic* proj, vec3_fixed* vel);

	void cheat_teleport();
	void cheat_enableNoheightCheck();
	void cheat_bugMode();
	void cheat_pauseAI();
	void cheat_postal();
	void cheat_fullAmmo();
	void cheat_unlock();
	void cheat_maxout();
	void cheat_godMode();

	// New TFE Cheats
	void cheat_fly();
	void cheat_noclip();
	void cheat_tester();
	void cheat_addLife();
	void cheat_subLife();
	void cheat_die();
	void cheat_oneHitKill();
	void cheat_instaDeath();

	// Serialization
	void playerLogic_serialize(Logic*& logic, SecObject* obj, Stream* stream);
}  // namespace TFE_DarkForces