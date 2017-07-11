#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  ::create();
  SetKeyName("shortsword");
  SetId( ({ "sword", "shortsword" }) );
  SetAdjectives( ({"short", "bloody"}) );
  SetShort("a bloody shortsword");
  SetLong(
    "The blade on the shortsword is covered with dried blood. Some "
    "intricate designs have been etched into the center of the blade "
    "from tip to hilt. The handle is made of wood in which the sword "
    "has been molded to fit into place. It is small with thin grooves on "
    "the surface."
  );
  SetClass(17);
  SetDamagePoints(540);
  SetValue(80);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMass(55);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(5);
}
