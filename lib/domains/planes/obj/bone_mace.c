/*
* mahkefel 3/11
* a mace made from the bone of a dragon
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("bone mace");
  SetShort("a bone mace");
  SetLong(
    "This heavy mace appears to be made from the knobby "
    "bone of a gargantuan creature. The larger end of "
    "the bone serves as the head of the mace, while "
    "the smaller end has been wrapped with leather to "
    "provide a strong grip."
  );

  SetId( ({"bone mace","mace"}) );
  SetAdjectives("bone");
  SetClass(17);
  SetDamagePoints(3000);
  SetDamageType(BLUNT);
  SetHands(1);
  SetMass(45);
  SetMaterial("natural");
  SetProperty("history",
    "This weapon is actually the knuckle bone of a "
    "slain dragon. Judging from the length, it must "
    "have been a fairly ancient wyrm of great size."
  );
  SetRepairDifficulty(50);
  SetValue(600);
  SetVendorType(VT_WEAPON);
  SetWeaponType("blunt");

}

