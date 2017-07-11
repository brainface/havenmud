#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("cultist staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "cultist", "black", "wooden" }) );
  SetShort("a black wooden staff");
  SetLong(
    "This long staff is made of a deep, black wood. It appears to be "
    "imbued with some form of evil magic."
  );
  SetHands(2);
  SetClass(25);
  SetWeaponType("pole");
  SetDamageType(BLUNT|MAGIC);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(8000);
  SetValue(8000);
  SetMass(200);
  SetMaterials( ({ "wood", "mithril" }) );
  SetRepairDifficulty(5);
  SetRepairSkills( ([
    "wood working" : 1,
     ]) );
 }
