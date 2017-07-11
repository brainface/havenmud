/* The file was updated by
* Haun on 1/19/99
* for MUD-UPKEEP purposes */
#include <lib.h>.c
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetMaterial("textile");
    SetWarmth(2);
    SetRepairSkills( ([
	    "textile working" : 1,
	    "armour smithing" : 1, 
      ]) );
    SetRepairDifficulty(10);
    SetKeyName("sock");
    SetId(( { "sock" }) );
    SetAdjectives( ({ "very", "dirty" }) );
    SetProperty("history", "The owner of these socks was probably killed"
      " before the chance of cleaning them was available.");
    SetShort("a pair of dirty socks");
    SetProperty("multiples", 1);
    SetLong("These socks appear to have been greatly used"
      " by their previous owner.  They are very dirty, and have"
      " a slight odor to them.  They are full of holes." );
    SetMass(15);
    SetVendorType(VT_CLOTHING);
    SetArmourClass(ARMOUR_CLOTH);
    SetValue(50);
    SetDamagePoints(180);
    SetArmourType(A_SOCK);
    // SetProtection(COLD,6);
    // SetProtection(HEAT,2);
    // SetProtection(SLASH,3);
    SetSize(SIZE_SMALL);
    SetWear("Despite the odor, you manage to wear the socks.");
}
/* File updated by Haun on 12/22/98
* for mud-upkeep purposes.
*/

