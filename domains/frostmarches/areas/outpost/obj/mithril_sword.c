#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({"two", "handed", "mithril"}) );
  SetShort("a two-handed mithril sword");
  SetLong("The hilt of this two-handed mithril sword is in the shape of a "
          "dragon. The tail of this mithril dragon is the used as the sword's "
          "grip and the wings protects the wielders hands like a crossbar. "
          "The dragon's mouth is open with the blade coming out of it like "
          "a flame. Etched into the left wing of the dragon is a balance. ");
  SetMass(300);
  SetValue(3000);
  SetDamagePoints(3000);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetClass(35);
  SetHands(2);
  SetMaterial( ({"metal"}) );
  SetRepairDifficulty(60);
  SetVendorType(VT_WEAPON);
}

