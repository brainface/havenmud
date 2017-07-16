#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_DIGGING;

    static void create() {
    item::create();
    digging::create();
    	
    SetKeyName("pick");
    SetId( ({ "pick", "mining pick", "a mining pick" }) );
    SetAdjectives( ({ "mining" }) );
    SetShort("a mining pick");
    SetLong("The mining pick is used to shatter rock in the mines.");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(1000);
    SetClass(7);
    SetValue(40);
    SetMaterials( ({"wood", "metal"}) );
    SetRepairSkills( ([
    		"wood working"  : 1, 
    		"metal working" : 1,
    		]) );
    SetRepairDifficulty(1);
    SetMass(300);
    SetWeaponType("hack");
    SetDamageType(PIERCE);
}
