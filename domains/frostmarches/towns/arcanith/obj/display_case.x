#include <lib.h>
#include "../ruins.h"
inherit LIB_STORAGE;

static void create() {
  mapping inventory = ([]);
  storage::create();
  SetShort("a glass display case");
  SetKeyName("display case");
  SetId( ({ "case","display" }) );
  SetAdjectives( ({ "glass","display" }) );
  SetLong("This contains a couple stealable shop "
    "items and one minor magic item. Should be "
    "visible when looking at it."
  );
  SetMass(10);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(90);
  SetPreventGet("The display case is firmly affixed "
    "the marble floor.");
  SetLockStrength(500); // GoodStrength?
  SetPick(1);
  SetCanLock(1);
  SetLocked(1);
  SetOpacity(0);
  inventory[OBJ + "/plate_breastplate"] = 1;
  inventory[OBJ + "/knife_old"] = random(2);
  inventory[OBJ + "/marble_chunk"] = random(3);
  inventory[OBJ + "/rapier_old"] = random(2);
  SetInventory(inventory);
}


