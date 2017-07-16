#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("hand crossbow");
  SetRepairDifficulty(18);
  SetRepairSkills( ([
    "weapon smithing" : 1,
   "wood working" : 1,
    ]) );
  SetMaterial("wood");
  SetShort("a hand-held crossbow");
  SetId( ({ "crossbow", "hand crossbow", "hand-held crossbow" }) );
  SetAdjectives( ({ "hand-held" }) );
  SetLong("This small yet deadly crossbow is designed for hand \n"
          "use by a skilled warrior.");
  SetValue(100);
  SetClass(12);
  SetMass(75);
  SetDamageType(PIERCE|MAGIC);
  SetWeaponType("projectile");
  SetDamagePoints(800);
  SetVendorType(VT_WEAPON);
  }
