#include "weapon_cooldown.h"
#include "../SCBW/scbwdata.h"
#include "../SCBW/enumerations.h"

namespace hooks {

/// Calculates the unit's weapon cooldown, factoring in upgrades and status effects.
///
/// @return		The modified cooldown value.
u32 getModifiedWeaponCooldownHook(const CUnit* unit, u8 weaponId) {
	//Default StarCraft behavior
	u32 cooldown = weapons_dat::Cooldown[weaponId];

	if (unit->acidSporeCount) {
		u32 increaseAmt = cooldown >> 3;
		if (increaseAmt < 3) increaseAmt = 3;
		cooldown += increaseAmt * unit->acidSporeCount;
	}

	int cooldownModifier = (unit->stimTimer ? 1 : 0) - (unit->ensnareTimer ? 1 : 0)
		+ (unit->status & UnitStatus::CooldownUpgrade ? 1 : 0);
	if (cooldownModifier > 0)
		cooldown >>= 1;
	else if (cooldownModifier < 0)
		cooldown += cooldown >> 2;

	if (cooldown > 250) cooldown = 250;
	else if (cooldown < 5) cooldown = 5;

	return cooldown;
}

} //hooks
