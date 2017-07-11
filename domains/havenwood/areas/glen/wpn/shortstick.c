/*    Updated on 1/16/99
 *    by Haun for MUD_Upkeep purposes.
*/
#include <lib.h>c
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
static void create() {
        item::create();
        SetMaterial("wood");
        SetRepairSkills( ([
           "wood working" : 1,
           "weapon smithing" : 2,
       	 	 ]) );
        SetRepairDifficulty(10);
        SetShort("a short stick");
        SetLong("This short stick is probably the toy of some "
                "poor gelfling child that was slaughtered in cold blood.  "
                "It would probably hurt if one was to get whacked "
                "with it.");
        SetId( ({"short stick","stick"}));
        SetClass(5);
        SetDamagePoints(1100);
        SetValue(70);
        SetWeaponType("blunt");
        SetDamageType(BLUNT);
        SetKeyName("stick");
        SetMass(35);
        SetVendorType(VT_WEAPON);
}
