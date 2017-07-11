#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int changeDescription(object who);

static void create() {
  ::create();
  SetKeyName("claw");
  SetShort("a set of exoskeletal claws");
  SetId( ({
    "claws", "hand"
  }) );
  SetAdjectives( ({  "exoskeletal", "set" }) );
  SetLong(
    "This set of exoskeletal claws is tainted a green hue "
    "and the claws themselves are long and sharp.  They "
    "appear to be insectoid."
  );
  SetWeaponType("melee");
  SetDamageType(PIERCE);
  SetVendorType(VT_WEAPON);
  SetClass(30);
  SetDamagePoints(2000);
  SetValue(random(500)+800);
  SetMass(50);
  SetMaterial("natural");
  SetRepairDifficulty(20);
}

/*
// if destination isn't an abashai, rename it
int eventMove(mixed dest) {
  if(dest->GetShort() && dest->GetShort() != "a thri-kreen worker") {
    SetKeyName("severed hand");
    SetShort("a thri-kreen's severed hand");
  }
  return ::eventMove(dest);
}
*/
