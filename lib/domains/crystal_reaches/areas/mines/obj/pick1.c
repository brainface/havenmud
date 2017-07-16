/*    /realms/haun/areas/mines/obj/pick.c
 *    created on 12/20/98
 *    by Haun
*/
#include <lib.h> 
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_DIGGING;

static void create() {
    item::create();
    digging::create();
    SetKeyName("mining pick");
    SetId( ({ "pick" }) );
    SetAdjectives( ({ "small", "mining" }) );
    SetShort("a small mining pick");
    SetLong(
    	"This mining pick is used to carefully tear away the sides of the "
    	"walls in the cave.  It seems to be worn, but is in fair condition.");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(200);


    SetClass(7);
    SetValue(40);
    SetMaterials( ({"wood", "metal"}) );
    SetRepairSkills( ([
    	"wood working"  :  1, 
    	"metal working" : 1,
			"weapon smithing"  :  1,
      ]) );
    SetRepairDifficulty(1);
    SetMass(120);
    SetWeaponType("hack");
    SetDamageType(PIERCE);
}
