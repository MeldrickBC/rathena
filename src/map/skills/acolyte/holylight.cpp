// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "holylight.hpp"

#include "../../clif.hpp"
#include "../../pc.hpp"
#include "../../status.hpp"
#include "../../pc.hpp"

SkillHolyLight::SkillHolyLight() : SkillImpl(AL_HOLYLIGHT) {
}

void SkillHolyLight::castendDamageId(block_list *src, block_list *target, uint16 skill_lv, t_tick tick, int32& flag) const {
	status_change_end(target, SC_P_ALTER);
	
	map_session_data* sd = BL_CAST(BL_PC, src);

	/*if (sd) {
		int16 weapon = sd->status.weapon;
		switch (weapon) {
			case W_STAFF:
			case W_2HSTAFF:
			case W_BOOK:
				skill_attack(BF_MAGIC, src, src, target, AL_HOLYLIGHT, skill_lv, tick, flag);
				break;
			default:
				skill_attack(BF_WEAPON, src, src, target, AL_C_HOLYLIGHT_MELEE, skill_lv, tick, flag);
				break;
		}
	}
	else 
		skill_attack(BF_MAGIC, src, src, target, AL_HOLYLIGHT, skill_lv, tick, flag);	*/
	skill_attack(BF_MAGIC, src, src, target, getSkillId(), skill_lv, tick, flag);
}

void SkillHolyLight::calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const {
	const map_session_data* sd = BL_CAST(BL_PC, src);

	base_skillratio += 25;
	if (sd && sd->sc.getSCE(SC_SPIRIT) && sd->sc.getSCE(SC_SPIRIT)->val2 == SL_PRIEST)
		base_skillratio *= 5; //Does 5x damage include bonuses from other skills?
}
