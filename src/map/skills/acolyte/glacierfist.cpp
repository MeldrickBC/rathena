// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "glacierfist.hpp"

#include <config/core.hpp>

#include "map/status.hpp"

SkillGlacierFist::SkillGlacierFist() : WeaponSkillImpl(CH_TIGERFIST) {
}

void SkillGlacierFist::castendDamageId(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32& flag) const {
	status_change* sc = status_get_sc(src);

	if (!(flag & 1)) {
		skill_area_temp[1] = target->id;

		map_foreachinshootrange(skill_area_sub, target,
			skill_get_splash(getSkillId(), skill_lv), BL_CHAR | BL_SKILL,
			src, getSkillId(), skill_lv, tick, flag | BCT_ENEMY | 1,
			skill_castend_damage_id);

		skill_attack(skill_get_type(getSkillId()), src, src, target, getSkillId(), skill_lv, tick, flag);

	}
	else
		if (skill_area_temp[1] != target->id)
			skill_attack(skill_get_type(getSkillId()), src, src, target, getSkillId(), skill_lv, tick, flag | SD_SPLASH);
}

void SkillGlacierFist::calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& skillratio, int32 mflag) const {
	skillratio += 150 + 50 * skill_lv;
	const status_change* sc = status_get_sc(src);
	if (sc && sc->getSCE(SC_COMBOEXTEND) && sc->getSCE(SC_COMBOEXTEND)->val2)
		skillratio += (skillratio * sc->getSCE(SC_COMBOEXTEND)->val2 * 5) / 100;
}

void SkillGlacierFist::applyAdditionalEffects(block_list* src, block_list* target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const {
	if (!(status_bl_has_mode(target, MD_STATUSIMMUNE)))
		sc_start(src, target, SC_STUN, 20, 0, 500);
}
