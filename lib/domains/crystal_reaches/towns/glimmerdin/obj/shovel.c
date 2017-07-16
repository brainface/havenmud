/*    /realms/haun/areas/mines/obj/shovel.c
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
    SetKeyName("shovel");
    SetId( ({ "shovel" }) );
    SetAdjectives( ({ "small", "mining" }) );
    SetShort("a small mining shovel");
    SetLong("This shovel is used to move dirt and other material in the"
      " Glimmerdin mines.  It has a wooden handle, and a very"
      " sharp metal point.");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(800);
    SetClass(6);
    SetValue(45);
    SetMaterials( ({"wood", "metal"}) );
    SetRepairSkills( ([
      "wood working"  :  1, 
      "metal working" : 1,
	    "weapon smithing"  :  1,
      ]) );
    SetRepairDifficulty(1);
    SetMass(200);
    SetWeaponType("hack");
    SetDamageType(PIERCE);
}
