/*
* mahkefel 3/22
* air elemental natural weapon
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sickle shaped chunk of ice");
  SetShort("a sickle shaped chunk of ice");
  SetLong(
    "This large chunk of ice is curved and wickedly sharp along "
    "one edge. One end comes to a narrow, jagged point, while the "
    "other seems to form a rough handle."
  );

  SetId( ({"sickle","chunk","ice"}) );
  SetAdjectives(({"sickle","shaped","chunk","of"}));
  SetClass(20);
  SetDamagePoints(3000);
  SetDamageType(COLD|SLASH);
  SetHands(1);
  SetMass(50);
  SetMaterial("natural");
  SetProperty("history",
    "This chunk of ice was long carried by an elemental. Due to "
    "that creature's magical influence, it will never melt."
  );
  SetRepairDifficulty(50);
  SetValue(600);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetWield("The chill of the ice numbs your hand.");
}

