/*
* mahkefel
* balrog ripoff weapon
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("fiery whip");
  SetShort("a fiery whip");
  SetLong(
    "A long tongue of flame whips about seemingly of "
    "its own volition from the charred grip of this "
    "terrifying weapon."
  );

  SetId( ({"whip"}) );
  SetAdjectives(({"fiery"}));
  SetClass(35);
  SetDamagePoints(3000);
  SetDamageType(HEAT|SLASH);
  SetHands(1);
  SetMass(20);
  SetMaterial("natural");
  SetProperty("history",
    "This is nothing from the surface of the world."
  );
  SetProperty("magic",
    "It's made of living flame. It probably burns things. "
    "You needed a spell to tell that."
  );
  SetRepairDifficulty(50);
  SetValue(1600);
  SetVendorType(VT_WEAPON);
  SetWeaponType("projectile");
}


