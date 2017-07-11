#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("glowing rapier");
  SetRepairDifficulty(22);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
     "metal working" : 1,
     "weapon smithing" : 3,
     ]) );
  SetShort("a glowing elven rapier");
  SetAdjectives( ({ "elven", "glowing" }) );
  SetId( ({ "rapier" }) );
  SetLong("This long, thin sword is a rapier of the type "
          "commonly used by the Haven Town Guard.  Its razor-thin "
          "length is used more for piercing than for slashing, "
          "but it still makes a wicked tear in flesh.");
  SetClass(50);
  SetDamagePoints(9600);
  SetValue(36000);
  SetMass(190);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetRadiantLight(20);
  }
