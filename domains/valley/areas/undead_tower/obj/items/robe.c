///   Created by Severen   ///
///     Late December      ///
///        robe.c          ///

#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <lib.h>
#include "/domains/valley/areas/undead_tower/defs.h"
inherit LIB_ARMOUR;

static void create() {
    ::create();
    SetValue(200);
    SetArmourType(A_BODY_ARMOUR);
  SetProperty("multiples", 1);
    SetSize(SIZE_VERY_SMALL);
   SetArmourClass(ARMOUR_CLOTH);
    SetVendorType(VT_ARMOUR);
    SetKeyName("robe");
    SetDamagePoints(250);
    SetRepairSkills( ([
	"textile working" : 9,
	"armour smithing" : 9,
      ]) );
    SetRepairDifficulty(10);
    SetShort("a robe with magical runes");
    SetId( ({ "robe" }) );
    SetAdjectives( ({ "with", "magical", "designs" }) );
    SetMaterial( ({ "textile" }) );
    SetLong("This is a robe with magical runes upon it. "
      "It is black with silver designs upon its sleeves. The "
      "robe is rather short but looks in relatively good shape.");
    SetMass(50);
    // SetProtection(MAGIC, 5);
}
