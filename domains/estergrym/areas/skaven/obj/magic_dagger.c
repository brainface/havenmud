#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../skaven.h"
inherit LIB_ITEM;

static void create()
{
item::create();
        SetKeyName("dagger");
        SetId( ({ "dagger", "wickedly sharp dagger", 
                  "wicked", "sharp", "wickedly" }) );
        SetAdjectives(  ({ "sharp", "wicked", "wickedly" })  );
        SetShort("a wickedly sharp dagger");
        SetLong("This dagger has been crafted from an unusual black "
                "metal that is strangely warm to the touch.  The "
                "blade itself is incredibly jagged and sharp.  Strange "
                "crimson runes adorn the blade." );
        SetMass(40);
        SetValue(1000);
        SetDamagePoints(1000);
        SetWeaponType("knife");
        SetDamageType(SLASH|COLD);
        SetClass(15);
        SetVendorType(VT_WEAPON);
        SetMaterial(  ({ "metal" })  );
        SetRepairSkills(  ([ 
        	"weapon smithing" : 7, 
          "metal working" : 7, 
          ])  );
        SetRepairDifficulty(99);
        SetProperty("magic", 
          "Several bloodthirsty souls are imprisoned within this blade.");
                
}
