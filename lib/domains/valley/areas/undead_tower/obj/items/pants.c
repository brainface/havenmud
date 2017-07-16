///   Created by Severen   ///
///     Late December      ///
///        pants.c         ///

#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <lib.h>
#include <size.h>
#include "/domains/valley/areas/undead_tower/defs.h"
inherit LIB_ARMOUR;

static void create() {
    ::create();
    SetValue(10);
    SetArmourType(A_PANTS);
    SetVendorType(VT_ARMOUR);
   SetArmourClass(ARMOUR_CLOTH);
    SetKeyName("old pants");
    SetDamagePoints(250);
    SetRepairSkills( ([
	"textile working" : 1,
	"armour smithing" : 1,
      ]) );
    SetRepairDifficulty(2);
    SetShort("a pair of old pants");
    SetId( ({ "pants" }) );
    SetAdjectives( ({ "pair", "old", "of" }) );
    SetMaterial( ({ "textile" }) );
    SetLong("This is an old pair of pants. They are "
      "very small and do not have any pockets. What was once "
      "black is now faded into a dull grey and several holes "
      "found their way on them.");
    SetMass(45);
    SetSize(SIZE_VERY_SMALL);
}
