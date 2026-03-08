// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "holylight.hpp"

#include "../../clif.hpp"
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
