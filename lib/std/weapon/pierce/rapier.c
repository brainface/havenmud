#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("elven rapier");
  SetShort("an elven rapier");
  SetId( ({ "rapier" }) );
  SetAdjectives( ({ "elven", "long", "razor", "thin", "razor-thin" }) );
  SetLong(
    "This long, thin sword is a rapier of the type "
    "commonly used by the Haven Town Guard.  Its razor-thin "
    "length is used more for piercing than for slashing, "
    "but it still makes a wicked tear in flesh."
  );
  SetClass(14);
  SetDamagePoints(1200);
  SetValue(180);
  SetMass(90);  
  SetMaterial( ({ "metal" }) );
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 3,
  ]) );
  SetRepairDifficulty(22);
}
