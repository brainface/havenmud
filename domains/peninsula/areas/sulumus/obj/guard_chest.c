// Proximo@Via Imperialis
// 06/03/2003

#include <lib.h>
#include <std.h>
#include "../sulumus.h"

inherit LIB_STORAGE;

static void create() {
  storage::create();
  SetKeyName("chest");
  SetId( ({ "chest" }) );
  SetAdjectives( ({ "giant", "wooden" }) );
  SetShort("a giant wooden chest");
  SetLong(
     "This very large chest is where surplus supplies for the guards is kept. "
     "It looks strong and sturdy, able to keep the items within safe and "
     "secure. "
  );
  SetPreventGet("The chest is far too large to carry.");
  SetInventory( ([
     S_OBJ + "spear" : random(6),
     S_OBJ + "leather_vest" : random(6),
     S_OBJ + "leather_helmet" : random(6),
     S_OBJ + "leather_boots" : random(6),
     S_OBJ + "leather_glove" : random(6),
     S_OBJ + "leather_pants" : random(6),
  ]) );
  SetLockStrength(500);
  SetLocked(1);
  SetClosed(1);
}
