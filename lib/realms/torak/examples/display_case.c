// Mahkefel 2010
// stealable transparent display case for
//   arcanith "smithy"
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
  SetLong(
    "This heavy wooden case proudly displays some of "
    "the artifacts recovered from the ruins of the city. "
    "The glass is thick and reinforced with a steel mesh, "
    "but the locks are only of moderate complexity."
  );
  SetMass(10);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(1000);
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

// inventory always visible to look in
int inventory_visible() {
    return 1;
}

// append internal desc to external desc
//  (so display case is "transparent")
string GetExternalDesc() {
  string desc;
  desc = ::GetExternalDesc();
  desc += ::GetInternalDesc();
  return desc;
}

