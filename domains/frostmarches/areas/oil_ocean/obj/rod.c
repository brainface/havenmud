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
        SetKeyName("rod");
        SetId( ({ "rod" }) );
        SetAdjectives(  ({ "long", "metal" })  );
        SetShort("a long metal rod");
        SetLong("A three foot thin metal rod used to keep workers in line.");
        SetMass(80);
        SetValue(150);
        SetDamagePoints(1100);
        SetWeaponType("pole");
        SetDamageType(BLUNT);
        SetClass(20);
        SetVendorType(VT_WEAPON);
        SetMaterial(  ({ "metal" })  );
        SetRepairSkills(  ([ 
		   "weapon smithing" : 1,
		   "metal working"   : 1,
		   ])  );
        SetRepairDifficulty(8);
}

