#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("bone scythe");
  SetId( ({ "bone scythe","scythe" }) );
   SetAdjectives( ({ "sharp","jagged","bone","evil" }) );
  SetShort("a huge bone scythe");
  SetLong("A jagged metal blade tops a huge pole made of finely polished "
          "bone.  Strange, writhing symbols are carved into every inch of " 
          "shaft, giving it an appearance of great power.");
  SetMass(230);
  SetValue(150);
  SetDamagePoints(1200);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetClass(15);
  SetHands(2);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal","natural" }) );
  SetRepairDifficulty(20);
  SetRepairSkills( ([
                    "metal working" : 5,
                    "weapon smithing" : 5,
                  ]) );
}
