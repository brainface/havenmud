#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
    inherit LIB_ITEM;
    static void create() {
    item::create();
    SetKeyName("light axe");
    SetId( ({ "axe", "light axe"}) );
    SetAdjectives( ({ "light" }) );
    SetShort("a light axe");
    SetLong("This light axe is small and its handle is thin.  When "
      "used by skilled hands it can cut wood effectively.");
    SetVendorType(VT_WEAPON);
    SetMaterials(({"metal", "wood"}));
    SetRepairSkills( ([
    		"metal working"  :  2, 
    	  "wood working" : 1,
    		]) );
    SetRepairDifficulty(1);
    SetDamagePoints(700);
    SetClass(9);
    SetValue(250);
    SetMass(125);
    SetWeaponType("hack");
    SetDamageType(SLASH);
}
