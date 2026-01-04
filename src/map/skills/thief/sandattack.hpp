// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#pragma once

//#include "../weapon_skill_impl.hpp"
#include "../skill_impl.hpp"

#include "../../battle.hpp"

//class SkillSandAttack : public WeaponSkillImpl {
class SkillSandAttack : public SkillImplRecursiveDamageSplash {
public:
	//SkillSandAttack();

	//void calculateSkillRatio(const Damage *wd, const block_list *src, const block_list *target, uint16 skill_lv, int32 &base_skillratio) const override;
	//void applyAdditionalEffects(block_list *src, block_list *target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const override;

	SkillSandAttack();

	void calculateSkillRatio(const Damage *wd, const block_list *src, const block_list *target, uint16 skill_lv, int32 &base_skillratio, int32 mflag) const override;
	void applyAdditionalEffects(block_list *src, block_list *target, uint16 skill_lv, t_tick tick, int32 attack_type, enum damage_lv dmg_lv) const override;
};
