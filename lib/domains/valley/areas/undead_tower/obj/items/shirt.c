///   Created by Severen   ///
///    Early December      ///
///       shirt.c          ///

#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <lib.h>
#include <size.h>
#include "/domains/valley/areas/undead_tower/defs.h"
inherit LIB_ARMOUR;

static void create() {
    ::create();
    SetValue(10);
    SetArmourType(A_SHIRT);
    SetVendorType(VT_ARMOUR);
    SetKeyName("shirt");
    SetDamagePoints(250);
    SetRepairSkills( ([
	"textile working" : 1,
	"armour smithing" : 1,
      ]) );
    SetRepairDifficulty(2);
    SetShort("a dirty torn shirt");
   SetArmourClass(ARMOUR_CLOTH);
    SetId( ({ "shirt" }) );
    SetAdjectives( ({ "dirty", "torn" }) );
    SetMaterial( ({ "textile" }) );
    SetLong("This is an dirty, torn up shirt. It has been "
      "torn off at the sleeves and smells musty. It "
      "used to be green but now has blackened stains "
      "and crud on it.");
    SetMass(40);
   SetSize(SIZE_VERY_SMALL);
}
