// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "skill_factory_custom.hpp"

#include "../swordman/bash.hpp"
//
#include "../archer/impressiveriff.hpp"
#include "../archer/magicstrings.hpp"
#include "../archer/perfecttablature.hpp"
#include "../archer/songoflutie.hpp"
//
#include "../archer/harmoniclick.hpp"
#include "../archer/lullaby.hpp"
#include "../archer/powerchord.hpp"
#include "../archer/battletheme.hpp"
#include "../archer/classicalpluck.hpp"
#include "../archer/downtempo.hpp"







class SkillCustomBash;
class SkillCustomImpressiveRiff;
class SkillCustomMagicStrings;
class SkillCustomPerfectTablature;
class SkillCustomSongofLutie;

class SkillCustomHarmonicLick;
class SkillCustomLullaby;
class SkillCustomPowerChord;
class SkillCustomBattleTheme;
class SkillCustomClassicalPluck;
class SkillCustomDownTempo;
class SkillCustomAcousticRhythm;
class SkillCustomMentalSensing;


#pragma region Custom Skills
#pragma region NV_C_COLLECT

class SkillCCollect : public SkillImpl {
public:
	SkillCCollect();

	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
};

SkillCCollect::SkillCCollect() : SkillImpl(NV_C_COLLECT) {
}

void SkillCCollect::castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	map_session_data* sd = BL_CAST(BL_PC, src);

	if (sd) {
		if (map_foreachinallrange(skill_greed, target,
			skill_get_splash(getSkillId(), skill_lv), BL_ITEM, target))
			clif_skill_nodamage(src, *target, getSkillId(), skill_lv);
	}
};

#pragma endregion

#pragma region AM_C_CARTCANNON

class SkillCCartCannonApple : public SkillImpl {
public:
	SkillCCartCannonApple();
	void castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
	void calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const override;	
};
SkillCCartCannonApple::SkillCCartCannonApple() : SkillImpl(AM_C_CARTCANNON_APPLE) {};

void SkillCCartCannonApple::castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	skill_attack(BF_WEAPON, src, src, target, getSkillId(), skill_lv, tick, flag);
};
void SkillCCartCannonApple::calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const {
	base_skillratio += 200 + 50 * skill_lv;
};

class SkillCCartCannonMelon : public SkillImpl {
public:
	SkillCCartCannonMelon();
	void castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
	void calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const override;
	void applyAdditionalEffects(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const override;
};
SkillCCartCannonMelon::SkillCCartCannonMelon() : SkillImpl(AM_C_CARTCANNON_MELON) {};

void SkillCCartCannonMelon::castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	skill_attack(BF_WEAPON, src, src, target, getSkillId(), skill_lv, tick, flag);
};
void SkillCCartCannonMelon::calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const {
	base_skillratio += 200 + 30 * skill_lv;
};
void SkillCCartCannonMelon::applyAdditionalEffects(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const {
	if (sc_start4(src, target, SC_MELON_BOMB, 100, skill_lv, 20, 20, 0, 3000)) {
		clif_specialeffect(target, EF_DECAGILITY, AREA);
	}
};

class SkillCCartCannonCoconut : public SkillImpl {
public:
	SkillCCartCannonCoconut();
	void castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
	void calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const override;
	void applyAdditionalEffects(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const override;
};
SkillCCartCannonCoconut::SkillCCartCannonCoconut() : SkillImpl(AM_C_CARTCANNON_COCONUT) {};

void SkillCCartCannonCoconut::castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	skill_attack(BF_WEAPON, src, src, target, getSkillId(), skill_lv, tick, flag);
};
void SkillCCartCannonCoconut::calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const {
	base_skillratio += 200 + 30 * skill_lv;
};
void SkillCCartCannonCoconut::applyAdditionalEffects(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const {
	sc_start(src, target, SC_STUN, 20, skill_lv, 2000);
};

class SkillCCartCannonPineapple : public SkillImpl {
public:
	SkillCCartCannonPineapple();
	void castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
	void calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const override;
	void applyAdditionalEffects(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const override;
};
SkillCCartCannonPineapple::SkillCCartCannonPineapple() : SkillImpl(AM_C_CARTCANNON_PINEAPPLE) {};

void SkillCCartCannonPineapple::castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	skill_attack(BF_WEAPON, src, src, target, getSkillId(), skill_lv, tick, flag);
};
void SkillCCartCannonPineapple::calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const {
	base_skillratio += 200 + 30 * skill_lv;
};
void SkillCCartCannonPineapple::applyAdditionalEffects(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const {
	sc_start(src, target, SC_BLEEDING, 1000, skill_lv, 100000);
};

class SkillCCartCannonBanana : public SkillImpl {
public:
	SkillCCartCannonBanana();
	void castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
	void calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const override;
	void applyAdditionalEffects(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const override;
};
SkillCCartCannonBanana::SkillCCartCannonBanana() : SkillImpl(AM_C_CARTCANNON_BANANA) {};

void SkillCCartCannonBanana::castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	skill_attack(BF_WEAPON, src, src, target, getSkillId(), skill_lv, tick, flag);
};
void SkillCCartCannonBanana::calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const {
	base_skillratio -= 100 + 10 * skill_lv;
};
void SkillCCartCannonBanana::applyAdditionalEffects(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const {
	sc_start(src, target, SC_BANANA_BOMB_SITDOWN, 1000, skill_lv, 500);
};

class SkillCCartCannonSpore : public SkillImplRecursiveDamageSplash {
public:
	SkillCCartCannonSpore();
};
SkillCCartCannonSpore::SkillCCartCannonSpore() : SkillImplRecursiveDamageSplash(AM_C_CARTCANNON_SPORE) {};

class SkillCCartCannon : public SkillImpl {
public:
	SkillCCartCannon();
	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
};
SkillCCartCannon::SkillCCartCannon() : SkillImpl(AM_C_CARTCANNON) {};
void SkillCCartCannon::castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	map_session_data* sd = BL_CAST(BL_PC, src);
	if (sd) {
		int32 i = sd->equip_index[EQI_AMMO];
		if (i) {
			t_itemid ammo_id = sd->inventory_data[i]->nameid;
			if (ammo_id > 0)
				sd->itemid = ammo_id;
				if (itemdb_group.item_exists(IG_BOMB, ammo_id)) {
					if (battle_check_target(src, target, BCT_ENEMY) > 0) {// Only attack if the target is an enemy.
						switch (ammo_id) {
						case ITEMID_APPLE_BOMB:
							skill_attack(BF_WEAPON, src, src, target, AM_C_CARTCANNON_APPLE, skill_lv, tick, flag);
							battle_consume_ammo(sd, AM_C_CARTCANNON_APPLE, skill_lv);
							break;
						case ITEMID_COCONUT_BOMB:
							skill_attack(BF_WEAPON, src, src, target, AM_C_CARTCANNON_COCONUT, skill_lv, tick, flag);
							battle_consume_ammo(sd, AM_C_CARTCANNON_COCONUT, skill_lv);
							break;
						case ITEMID_MELON_BOMB:
							skill_attack(BF_WEAPON, src, src, target, AM_C_CARTCANNON_MELON, skill_lv, tick, flag);
							battle_consume_ammo(sd, AM_C_CARTCANNON_MELON, skill_lv);
							break;
						case ITEMID_PINEAPPLE_BOMB:
							skill_attack(BF_WEAPON, src, src, target, AM_C_CARTCANNON_PINEAPPLE, skill_lv, tick, flag);
							battle_consume_ammo(sd, AM_C_CARTCANNON_PINEAPPLE, skill_lv);
							break;
						case ITEMID_BANANA_BOMB:
							skill_attack(BF_WEAPON, src, src, target, AM_C_CARTCANNON_BANANA, skill_lv, tick, flag);
							battle_consume_ammo(sd, AM_C_CARTCANNON_BANANA, skill_lv);
							break;
						case ITEMID_BOMB_MUSHROOM_SPORE:
							clif_soundeffect(*src, "explosion_attack.wav", 0, AREA);
							clif_specialeffect(target, EF_SPR_LIGHTPRINT2, AREA);
							map_foreachinrange(skill_area_sub, target, skill_get_splash(AM_C_CARTCANNON_SPORE, skill_lv), BL_CHAR | BL_SKILL, src, AM_C_CARTCANNON_SPORE, skill_lv, tick + (200 + status_get_amotion(src)), flag | BCT_ENEMY | SD_SPLASH | 1, skill_castend_damage_id);
							battle_consume_ammo(sd, AM_C_CARTCANNON_SPORE, skill_lv);
							break;
						}
					}
					else
						clif_skill_fail(*sd, getSkillId());
				}
		}
	}
};
#pragma endregion

#pragma region HP_C_RADIUSLUCIS
class SkillCRadiusLucis : public SkillImpl {
public:
	SkillCRadiusLucis();

	void castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
	void calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const override;
};
SkillCRadiusLucis::SkillCRadiusLucis() : SkillImpl(HP_C_RADIUSLUCIS) {
};
void SkillCRadiusLucis::castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	clif_skill_nodamage(src, *target, getSkillId(), skill_lv);
	if (skill_attack(BF_MAGIC, src, src, target, getSkillId(), skill_lv, tick, flag)) {
		map_session_data* sd = BL_CAST(BL_PC, src);
		if (sd && pc_checkskill(sd, AL_DECAGI)) {
			status_change* tsc = status_get_sc(target);
			status_data* sstatus = status_get_status_data(*src);
			int32 DecAgiLv = pc_checkskill(sd, AL_DECAGI);
			if (tsc && (!tsc->getSCE(SC_DECREASEAGI)) && sc_start(src, target, SC_DECREASEAGI, (50 + DecAgiLv * 3 + (status_get_lv(src) + sstatus->int_) / 5), DecAgiLv, skill_get_time(AL_DECAGI, DecAgiLv)))
				clif_specialeffect(target, EF_DECAGILITY, AREA);
		}
	}
};
void SkillCRadiusLucis::calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const {
	base_skillratio += 400 + 100 * skill_lv;
};
#pragma endregion

#pragma region PR_C_SACRUSIMPETUS 
class SkillCSacrusImpetus : public SkillImpl {
public:
	SkillCSacrusImpetus();

	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
};
SkillCSacrusImpetus::SkillCSacrusImpetus() : SkillImpl(PR_C_SACRUSIMPETUS) {
}
void SkillCSacrusImpetus::castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	map_session_data* sd = BL_CAST(BL_PC, src);

	if (sd == nullptr || sd->status.party_id == 0 || (flag & 1)) {

		// Animations don't play when outside visible range
		if (check_distance_bl(src, target, AREA_SIZE) && src == target)
			clif_skill_nodamage(target, *target, getSkillId(), skill_lv);

		status_data* sstatus = status_get_status_data(*src);
		int32 mindmg = sstatus->matk_min + sstatus->batk;
		int32 maxdmg = sstatus->matk_max + sstatus->batk;

		if (src->id != target->id) {
			mindmg /= 2;
			maxdmg /= 2;
		}

		mindmg += 50 + 5 * skill_lv;
		maxdmg += 50 + 5 * skill_lv;

		if (src->id != target->id) {
			map_session_data* dstsd = BL_CAST(BL_PC, target);
			if (dstsd) {
				mindmg = mindmg * dstsd->status.base_level / 100;
				maxdmg = maxdmg * dstsd->status.base_level / 100;
			}
		}

		if (maxdmg < mindmg)
			maxdmg = mindmg;

		sc_start4(src, target, skill_get_sc(getSkillId()), 100, skill_lv, mindmg, maxdmg, src->id, skill_get_time(getSkillId(), skill_lv));
	}
	else if (sd)
		party_foreachsamemap(skill_area_sub, sd, skill_get_splash(getSkillId(), skill_lv), src, getSkillId(), skill_lv, tick, flag | BCT_PARTY | 1, skill_castend_nodamage_id);
};

// PR_C_SACRUSIMPETUS_ATK
class SkillCSacrusImpetusAtk : public SkillImpl {
public:
	SkillCSacrusImpetusAtk();

	void castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override;
};
SkillCSacrusImpetusAtk::SkillCSacrusImpetusAtk() : SkillImpl(PR_C_SACRUSIMPETUS_ATK) {
};
void SkillCSacrusImpetusAtk::castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	skill_attack(BF_WEAPON, src, src, target, getSkillId(), skill_lv, tick, flag);
};
#pragma endregion

#pragma endregion

#pragma region Official Skills with Custom Changes

#pragma region BA_ASSASSINCROSS
class SkillCustomImpressiveRiff : public SkillImpressiveRiff {
	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override {
		skill_castend_song(src, getSkillId(), skill_lv, tick);
	}
	void castendPos2(block_list* src, int32 x, int32 y, uint16 skill_lv, t_tick tick, int32& flag) const override {
		//does nothing
	}
};
#pragma endregion

#pragma region BA_POEMBRAGI
class SkillCustomMagicStrings : public SkillMagicStrings {
	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override {
		skill_castend_song(src, getSkillId(), skill_lv, tick);
	}
	void castendPos2(block_list* src, int32 x, int32 y, uint16 skill_lv, t_tick tick, int32& flag) const override {
		//does nothing
	}
};
#pragma endregion

#pragma region BA_WHISTLE
class SkillCustomPerfectTablature : public SkillPerfectTablature {
	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override {
		skill_castend_song(src, getSkillId(), skill_lv, tick);
		clif_soundeffect(*src, "whistle.wav", 0, AREA);
	}
	void castendPos2(block_list* src, int32 x, int32 y, uint16 skill_lv, t_tick tick, int32& flag) const override {
		//does nothing
	}
};
#pragma endregion

#pragma region BA_APPLEIDUN
class SkillCustomSongofLutie : public SkillSongofLutie {
	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override {
		skill_castend_song(src, getSkillId(), skill_lv, tick);
	}
	void castendPos2(block_list* src, int32 x, int32 y, uint16 skill_lv, t_tick tick, int32& flag) const override {
		//does nothing
	}
};
#pragma endregion
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region BD_RINGNIBELUNGEN
class SkillCustomHarmonicLick : public SkillHarmonicLick {
	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override {
		skill_castend_song(src, getSkillId(), skill_lv, tick);
	}
	void castendPos2(block_list* src, int32 x, int32 y, uint16 skill_lv, t_tick tick, int32& flag) const override {
		//does nothing
	}
};
#pragma endregion

#pragma region BD_LULLABY
class SkillCustomLullaby : public SkillLullaby {
	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override {
		skill_castend_song(src, getSkillId(), skill_lv, tick);
	}
	void castendPos2(block_list* src, int32 x, int32 y, uint16 skill_lv, t_tick tick, int32& flag) const override {
		//does nothing
	}
};
#pragma endregion

#pragma region BD_INTOABYSS
class SkillCustomPowerChord : public SkillPowerChord {
	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override {
		skill_castend_song(src, getSkillId(), skill_lv, tick);
	}
	void castendPos2(block_list* src, int32 x, int32 y, uint16 skill_lv, t_tick tick, int32& flag) const override {
		//does nothing
	}
};
#pragma endregion

#pragma region BD_DRUMBATTLEFIELD
class SkillCustomBattleTheme : public SkillBattleTheme {
	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override {
		skill_castend_song(src, getSkillId(), skill_lv, tick);
	}
	void castendPos2(block_list* src, int32 x, int32 y, uint16 skill_lv, t_tick tick, int32& flag) const override {
		//does nothing
	}
};
#pragma endregion

#pragma region BD_ROKISWEIL
class SkillCustomClassicalPluck : public SkillClassicalPluck {
	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override {
		skill_castend_song(src, getSkillId(), skill_lv, tick);
	}
	void castendPos2(block_list* src, int32 x, int32 y, uint16 skill_lv, t_tick tick, int32& flag) const override {
		//does nothing
	}
};
#pragma endregion

#pragma region BD_ETERNALCHAOS
class SkillCustomDownTempo : public SkillDownTempo {
	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override {
		skill_castend_song(src, getSkillId(), skill_lv, tick);
	}
	void castendPos2(block_list* src, int32 x, int32 y, uint16 skill_lv, t_tick tick, int32& flag) const override {
		//does nothing
	}
};
#pragma endregion

#pragma region BD_SIEGFRIED
class SkillCustomAcousticRhythm : public SkillAcousticRhythm {
	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override {
		skill_castend_song(src, getSkillId(), skill_lv, tick);
	}
	void castendPos2(block_list* src, int32 x, int32 y, uint16 skill_lv, t_tick tick, int32& flag) const override {
		//does nothing
	}
};
#pragma endregion

#pragma region BD_RICHMANKIM
class SkillCustomMentalSensing : public SkillMentalSensing {
	void castendNoDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const override {
		skill_castend_song(src, getSkillId(), skill_lv, tick);
	}
	void castendPos2(block_list* src, int32 x, int32 y, uint16 skill_lv, t_tick tick, int32& flag) const override {
		//does nothing
	}
};
#pragma endregion


#pragma endregion

class SkillCustomBash : public SkillBash {
	void calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const override {
		// Normal Bash:
		// Base 100% + 30% per level
		// base_skillratio += 30 * skill_lv;

		// But my custom Bash Skill is stronger:
		// Base 100% + 300% per level
		base_skillratio += 300 * skill_lv;
	}
};

std::unique_ptr<const SkillImpl> SkillFactoryCustom::create(const e_skill skill_id) const {
#if 1
	switch (skill_id) {
		//case SM_BASH:
			//return std::make_unique<SkillCustomBash>();
		case BA_ASSASSINCROSS:
			return std::make_unique<SkillCustomImpressiveRiff>();
		case BA_POEMBRAGI:
			return std::make_unique<SkillCustomMagicStrings>();
		case BA_WHISTLE:
			return std::make_unique<SkillCustomPerfectTablature>();
		case BA_APPLEIDUN:
			return std::make_unique<SkillCustomSongofLutie>();
		case BD_RINGNIBELUNGEN:
			return std::make_unique<SkillCustomHarmonicLick>();
		case BD_LULLABY:
			return std::make_unique<SkillCustomLullaby>();
		case BD_INTOABYSS:
			return std::make_unique<SkillCustomPowerChord>();
		case BD_DRUMBATTLEFIELD:
			return std::make_unique<SkillCustomBattleTheme>();
		case BD_ROKISWEIL:
			return std::make_unique<SkillCustomClassicalPluck>();
		case BD_ETERNALCHAOS:
			return std::make_unique<SkillCustomDownTempo>();
		case BD_SIEGFRIED:
			return std::make_unique<SkillCustomAcousticRhythm>();
		case BD_RICHMANKIM:
			return std::make_unique<SkillCustomMentalSensing>();
		case NV_C_COLLECT:
			return std::make_unique<SkillCCollect>();
		case PR_C_SACRUSIMPETUS:
			return std::make_unique<SkillCSacrusImpetus>();
		case PR_C_SACRUSIMPETUS_ATK:
			return std::make_unique<SkillCSacrusImpetusAtk>();
		case HP_C_RADIUSLUCIS:
			return std::make_unique<SkillCRadiusLucis>();
		case AM_C_CARTCANNON:
			return std::make_unique<SkillCCartCannon>();
		case AM_C_CARTCANNON_APPLE:
			return std::make_unique<SkillCCartCannonApple>();
		case AM_C_CARTCANNON_COCONUT:
			return std::make_unique<SkillCCartCannonCoconut>();
		case AM_C_CARTCANNON_MELON:
			return std::make_unique<SkillCCartCannonMelon>();
		case AM_C_CARTCANNON_PINEAPPLE:
			return std::make_unique<SkillCCartCannonPineapple>();
		case AM_C_CARTCANNON_BANANA:
			return std::make_unique<SkillCCartCannonBanana>();
		case AM_C_CARTCANNON_SPORE:
			return std::make_unique<SkillCCartCannonSpore>();
		default:
			return nullptr;
	}
#endif	
	return nullptr;
}
