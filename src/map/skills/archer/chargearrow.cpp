// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "chargearrow.hpp"

#include "map/pc.hpp"

SkillChargeArrow::SkillChargeArrow() : WeaponSkillImpl(AC_CHARGEARROW)
{
}

void SkillChargeArrow::calculateSkillRatio(const Damage* wd, const block_list* src, const block_list* target, uint16 skill_lv, int32& base_skillratio, int32 mflag) const
{
	const map_session_data *sd = BL_CAST(BL_PC, src);
	base_skillratio += 50;

	if (sd) {
		base_skillratio += -50 + 80 * skill_lv;
		if (sd->status.weapon != W_BOW)
			base_skillratio = base_skillratio * 0.5;
	}
}
