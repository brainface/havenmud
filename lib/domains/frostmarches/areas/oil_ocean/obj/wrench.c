//Illura@Haven
//Nov 2010
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../oil.h"
inherit LIB_ITEM;

static void create()
{
item::create();
        SetKeyName("wrench");
        SetId( ({ "wrench" }) );
        SetAdjectives(  ({ "hefty" })  );
        SetShort("a hefty wrench");
        SetLong("A metal wrench that feels good in the hand.");
        SetMass(80);
        SetValue(100);
        SetDamagePoints(1100);
        SetWeaponType("blunt");
        SetDamageType(BLUNT);
        SetClass(20);
        SetVendorType(VT_WEAPON);
        SetMaterial(  ({ "metal" })  );
        SetRepairSkills(  ([ 
		   "weapon smithing" : 1,
           "metal working"	 : 1,
		   ])  );
        SetRepairDifficulty(8);
}

