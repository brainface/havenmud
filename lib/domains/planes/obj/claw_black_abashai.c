/*
* mahkefel 3/22
* abashai natural weapon
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

int changeDescription(object who);

static void create() {
  item::create();
  SetKeyName("draconic claws");
  SetShort("draconic claws");
  SetLong(
    "This is a severed hand from some monstrous creature. "
    "Thick black scales cover its entirety, and long "
    "yellow claws jut from each fingertip. Dark green "
    "ichor drips from the severed wrist."
  );

  SetId( ({"hand","paw","claws","claw"}) );
  SetAdjectives(({"draconic","abashai","devil's","scaly","severed"}));
  SetClass(17);
  SetDamagePoints(200);
  SetDamageType(PIERCE);
  SetHands(1);
  SetMass(20);
  SetMaterial("natural");
  SetProperty("history",
    "This is the severed hand of a black abashai, a "
    "relatively weak devil from the lower planes with "
    "some strange connection to dragonkind."
  );
  SetRepairDifficulty(50);
  SetValue(600);
  SetVendorType(VT_WEAPON);
  SetWeaponType("melee");
}

// if destination isn't an abashai, rename it
int eventMove(mixed dest) {
  if(dest->GetShort() != "a black abashai") {
    SetKeyName("severed hand");
    SetShort("a scaly devil's severed hand");
  }
  return item::eventMove(dest);
}
