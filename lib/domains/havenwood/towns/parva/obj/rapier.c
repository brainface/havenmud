#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("parvan rapier");
  SetShort("a fine parvan rapier");
  SetId( ({ "rapier" }) );
  SetAdjectives( ({ "fine", "parvan" }) );
  SetLong(
    "This long, thin sword is a rapier of the type "
    "commonly used by the duelers in Parva.  Its razor-thin "
    "length is used more for piercing than for slashing, "
    "but it still makes a wicked tear in flesh."
  );
  SetClass(20);
  SetDamagePoints(1200);
  SetValue(200);
  SetMass(90);  
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(25);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetVendorType(VT_WEAPON);

}
