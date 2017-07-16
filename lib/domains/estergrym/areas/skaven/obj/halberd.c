#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../skaven.h"
inherit LIB_ITEM;

static void create()
{
item::create();
        SetKeyName("halberd");
        SetId( "halberd" );
        SetAdjectives( "stout" );
        SetShort("a stout halberd");
        SetLong("This halberd consists of a pole about six feet "
                "long, topped with a axe-blade that is cruelly "
                "serrated.  While not fancy, this weapon is "
                "certainly functional." );
        SetMass(200);
        SetValue(380);
        SetDamagePoints(1200);
        SetWeaponType("pole");
        SetDamageType(SLASH);
        SetClass(13);
        SetVendorType(VT_WEAPON);
        SetMaterial(  ({ "metal" })  );
        SetRepairSkills(  ([ 
        	"weapon smithing" : 6, 
          "metal working"   : 6, 
          ])  );
        SetRepairDifficulty(15);
        SetHands(2);
}
        
        
