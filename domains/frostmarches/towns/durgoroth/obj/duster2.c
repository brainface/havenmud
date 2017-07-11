#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create(){
  item::create();
  SetKeyName("knuckle duster");
  SetId( ({ "duster" }) );
  SetAdjectives( ({ "knuckle", }) );
  SetShort("a knuckle duster");
  SetLong(
    "This is a large metallic band that wraps"
    " neatly over the knuckles. There is a"
    " bar for gripping which also increases"
    " the force of the blow."
  );
  SetClass(22);
  SetDamagePoints(1000);
  SetValue(500);
  SetWeaponType("melee");
  SetDamageType(BLUNT);
  SetMass(25);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}
