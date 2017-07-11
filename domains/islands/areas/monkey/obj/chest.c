// Island
// Aerelus

#include <lib.h>
#include "../island.h"
inherit LIB_STORAGE;
int eventLockChest();

static void create() {
  ::create();
  SetKeyName("chest");
  SetDamagePoints(25000);
  SetLockStrength(1000);
  SetShort("an ancient chest");
  SetMass(10000);
  SetId( ({ "chest" }) );
  SetAdjectives( ({ "ancient" }) );
  SetLong(
    "This old chest has been buried for a very long time. The wood has "
    "started to decay, but it still looks sturdy. There is a metal lock on "
    "the top that looks solid.");  
  SetClosed(1);
  SetCanClose(1);
  SetPreventGet("You cannot pick that up!");
  SetMaxCarry(7500);
  SetCanLock(1);
  SetLocked(1);
  SetKeys( ({ "island_key" }) );
  SetInventory( ([
    ISLAND_OBJ "knife" : 2,
  ]) );
}