#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("massive two-handed sword");
  SetShort("a massive two-handed sword");
  SetId( ({ "sword", "orcslayer" }) );
  SetAdjectives( ({ "massive", "two", "handed" }) );
  SetClass(26);
  SetHands(2);
  SetLong(
    "This massive two-handed sword is made of a light metal that "
    "is surprisingly durable. The blade remains sharp through use."
    );
  SetProperty("magic", "The blade is the famed weapon \"Orcslayer\".");
  SetVendorType(VT_WEAPON|VT_MAGIC);
  SetDamageType(SLASH);
  SetDamagePoints(99999);
  SetValue(1200);
  SetMass(40);
  SetMaterials( ({ "mithril" }) );
  SetWeaponType("slash");
}

void eventDeteriorate(int x) { return; }