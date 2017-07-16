/* File updated by Haun on 12/22/98
* for mud-upkeep purposes.
*/

#include <lib.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
    armour::create();
    SetMaterial("textile");
    SetWarmth(25);
    SetKeyName("robe");
    SetId( ({ "robe" }) );
    SetAdjectives( ({ "dark" }) );
    SetShort("a dark robe");
    SetLong("The dark robe is made of a heavy material, very much like "
      "velvet yet markedly different.  Its color is so dark that it "
      "almost seems to not be a color at all.  Except for the highly "
      "ornate red trim on each sleeve, there is no other "
      "ornamentation to be found on it.");
    SetMass(60);
    SetArmourClass(ARMOUR_CLOTH);
    SetSize(SIZE_SMALL);
    SetValue(600);
    SetDamagePoints(800);
    // SetProtection(BLUNT, 3);
    // SetProtection(SLASH, 5);
    // SetProtection(PIERCE, 3);
    // SetProtection(WATER, 3);
    // SetProtection(SHOCK, 5);
    // SetProtection(COLD, 4);
    // SetProtection(HEAT, 4);
    // SetProtection(GAS, 2);
    // SetProtection(ACID, 3);
    // SetProtection(MAGIC, 6); 
    SetArmourType(A_BODY_ARMOUR);
    SetRepairDifficulty(10);
    SetRepairSkills( ([
			"textile working" : 1,
			"armour smithing" : 1, 
      ]) );
    SetVendorType(VT_TREASURE | VT_ARMOUR);
    SetWear("An odd sensation, almost like an electrical charge, "
      "passes over you as you wear the robe.");
}
