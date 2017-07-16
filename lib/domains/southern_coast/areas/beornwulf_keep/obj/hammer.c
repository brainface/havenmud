#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("hammer");
  SetId( ({"hammer"}) );
  SetShort("a war hammer");
  SetLong("The head of this deadly looking weapon is uneven and reckless "
          "looking, it is obvious that it was made for functionality "
          "rather than show.");
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "iron working" : 4,
     "weapon smithing" : 5
     ]) );
  SetRepairDifficulty(30);
  SetMass(130);
  SetValue(300);
  SetDamagePoints(1800);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(14);
  SetVendorType(VT_WEAPON);
}
