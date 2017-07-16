#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("spiked club");
  SetShort("a wicked spiked club");
  SetId( ({ "club", "spiked club" }) );
  SetLong("This viscious spiked club is an oversized tree limb "
          "with protrusions which can only be called spikes.  Its "
          "value is minimal, but its lethal power is undisputed.");
  SetValue(30);
  SetMaterial( ({ "wood", "metal" }) );
  SetDamagePoints(600);
  SetDamageType(BLUNT|PIERCE);
  SetWeaponType("blunt");
  SetClass(11);
  SetMass(60);
  }
