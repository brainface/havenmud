/* a knife for male gelfling
   kyla 10-25-97
*/
#include <damage_types.h>
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("knife");
  SetId( ({
       "knife"
         }) );
  SetAdjectives( ({ 
        "sharp"
         }) );
  SetShort("a sharp knife");
  SetLong("This knife appears to be quite sharp and looks like it could "
           "do some real damage if used by a skilled hand.");
  SetMass(60);
  SetValue(55);
  SetVendorType(VT_WEAPON);
  SetClass(12);
  SetDamagePoints(600);
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetMaterial( ({"metal" }) );
  SetRepairSkills( ([
                 "metal working" : 0,
                 "weapon smithing" : 0,
                   ]) );
  SetRepairDifficulty(5);
  }
