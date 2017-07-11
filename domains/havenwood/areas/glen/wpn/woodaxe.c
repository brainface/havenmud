/*    Updated on 1/16/99
 *    by Haun for MUD_Upkeep purposes.
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
static void create() {
        item::create();
        SetShort("a sharp looking axe");
        SetMaterial( ({"metal","wood"}) );
        SetRepairSkills( ([
        		"metal working" : 5,
            "weapon smithing" : 6
        		]) );
        SetRepairDifficulty(30);
        SetLong("The axe is very sharp and has a heavy "
                "wooden handle.  It is designed to be used "
                "with two hands." );
        SetId( ({"sharp looking axe", "sharp axe","wood axe",
                 "axe"}) );
        SetClass(12);
        SetDamagePoints(2000);
        SetValue(350);
        SetWeaponType("hack");
        SetDamageType(SLASH);
        SetKeyName("axe");
        SetMass(85);
        SetVendorType(VT_WEAPON);
        SetAdjectives( ({ "wood" }) );
  			SetHands(2);
}
