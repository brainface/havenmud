/*    /realms/haun/areas/mines/obj/hammer.c
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
    SetKeyName("hammer");
    SetId( ({ "hammer" }) ); 
    SetAdjectives( ({ "large", "mining" }) );
    SetShort("a large mining hammer");
    SetLong("This mining hammer is used to break the rock that lies on the in"
      "side of mines.  It is very heavy, and durable.");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(800);
    SetClass(6);
    SetValue(40);
    SetMaterials( ({"wood", "metal"}) );
    SetRepairSkills( ([
    	"wood working"  :  1, 
    	"metal working" : 1,
			"weapon smithing"  :  1,
      ]) );
    SetRepairDifficulty(1);
    SetMass(350);
    SetWeaponType("blunt");
    SetDamageType(BLUNT);
}
