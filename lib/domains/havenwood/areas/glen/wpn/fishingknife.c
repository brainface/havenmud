/*    Updated on 1/16/99
 *    by Haun for MUD_Upkeep purposes.
*/
#include <lib.h>nife.c
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
static void create() {
        item::create();
        SetMaterial("metal");
        SetRepairSkills( ([
           "metal working" : 5,
           "weapon smithing"   : 6
           ]) );
        SetRepairDifficulty(30);
        SetShort("a fishing knife");
        SetLong("This knife is very long and very sharp.  "
                "It is well crafted, and has an ivory handle. "
                "It is used primarily for gutting fish."
                ".");
        SetId( ({"fishing knife","knife"}) );
        SetClass(12);
        SetDamagePoints(1000);
        SetValue(145);
        SetWeaponType("knife");
        SetDamageType(PIERCE|SLASH);
        SetKeyName("knife");
        SetMass(50);
        SetVendorType(VT_WEAPON);
}
