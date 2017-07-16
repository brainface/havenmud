#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("battle axe");
  SetId( ({"axe"}) );
  SetAdjectives( ({ "battle", "steel" }) );
  SetShort("a steel battle axe");
  SetLong(
    "The wicked steel blade of this battle "
    "axe looks like it would do a lot of "
    "damage to an opponent. The head of "
    "the axe is mounted on a three foot "
    "long shaft of steel."
  );
  SetClass(15);
  SetDamagePoints(2000);
  SetValue(850);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetKeyName("battle axe");
  SetMass(350);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({ "steel" }) );
  SetHands(2);
}

