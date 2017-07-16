#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../skaven.h"
inherit LIB_ITEM;

static void create()
{
item::create();
        SetKeyName("morning star");
        SetId( "star" );
        SetAdjectives(  ({ "heavy", "iron", "morning" })  );
        SetShort("a heavy iron morning star");
        SetLong("This morning star has been sturdily crafted from "
                "iron with a leather grip.  The head of the weapon "
                "is liberally studded with sharp iron spikes and "
                "flanges that appear to have been poisoned before as " 
                "small traces of a purplish residue cover the weapon.");
        SetMass(200);
        SetValue(1500);
        SetDamagePoints(1500);
        SetWeaponType("blunt");
        SetDamageType(BLUNT);
        SetClass(18);
        SetPoison(40);
        SetVendorType(VT_WEAPON);
        SetMaterial(  ({ "metal" })  );
        SetRepairSkills(  ([ 
        	"weapon smithing" : 8, 
          "metal working" : 8, ])  );
        SetRepairDifficulty(85);
                       
}
