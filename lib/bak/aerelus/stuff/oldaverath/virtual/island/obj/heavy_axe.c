#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create()
{
  ::create();
  SetKeyName("heavy axe");
  SetShort("a heavy axe");
  SetId(({ "axe" }) );
  SetAdjectives( ({ "heavy" }) );
  SetLong("This axe, though fairly heavy, is not terribly impressive.  It is "
          "somewhat dull, and not well balanced, but it seems to at least be "
          "useful.");
  SetMass(500);
  SetValue(25);
  SetVendorType(VT_WEAPON);
  SetClass(10);
  SetDamagePoints(125);
  SetWeaponType("hack");
  SetDamageType(SLASH);
//SetMaterial( ({ "metal" }) );
//SetRepairDifficulty(5);
//SetRepairSkills( ([
//  "metal working" : 0,
//  "weapon smithing" : 0
//]) );
}
