#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("quarterstaff");
  SetId( ({ "staff","quarterstaff"}) );
  SetAdjectives( ({ "long", "quarter" }) );
  SetShort("a long quarterstaff");
  SetLong(
     "This long stout staff is a wooden quarterstaff made for combat. "
     "This type of weapon is preferred by those who want to use a weapon "
     "that does not require using a shield, yet has more range than a knife. "
     "This is a weapon used commonly by mages of all kinds. "
  );
  SetClass(8);
  SetDamagePoints(475);
  SetHands(2);
  SetValue(50);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetMass(175);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
}
