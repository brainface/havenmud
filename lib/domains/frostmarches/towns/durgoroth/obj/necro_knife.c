#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("sacrificial knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "sacrificial" }) );
  SetShort("a sacrificial knife");
  SetLong("This knife has been crafted from the"
          " bones of a dead daemon. The blade"
          " is eight inches long and has various"
          " scratches along the hilt representing"
          " some form of hieroglyphics or runes."
  );
  SetClass(25);
  SetDamagePoints(1000);
  SetValue(900);
  SetWeaponType("knife");
  SetDamageType(PIERCE | MAGIC);
  SetMass(25);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_WEAPON);
}
