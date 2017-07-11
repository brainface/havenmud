#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rapier");
  SetRepairDifficulty(22);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
     "metal working" : 1,
     "weapon smithing" : 3,
     ]) );
  SetShort("an elven rapier");
  SetAdjectives( ({ "elven" }) );
  SetId( ({ "rapier", "elven rapier" }) );
  SetLong("This long, thin sword is a rapier of the type "
          "commonly used by the Haven Town Guard.  Its razor-thin "
          "length is used more for piercing than for slashing, "
          "but it still makes a wicked tear in flesh.");
  SetClass(14);
  SetDamagePoints(1200);
  SetValue(180);
  SetMass(90);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  }
