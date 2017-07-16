#include <lib.h>
#include "../island.h"
inherit LIB_STORAGE;

static void create() {
  ::create();
  SetKeyName("buried chest");
  SetDamagePoints(2500);
  SetLockStrength(25);
  SetShort("a formerly buried chest");
  SetMass(1000);
  SetId( ({ "chest" }) );
  SetAdjectives( ({ "buried", "formerly" }) );
  SetLong(
    "This chest has seen better days.  It has been buried on a forested island for quite some time."
    );
  SetClosed(1);
  SetCanClose(1);
  SetMaxCarry(7500);
  SetCanLock(1);
  SetLocked(1);
  SetKeys( ({ "buried_chest_key" }) );
  SetInventory( ([
    ISLAND_OBJ "statue" : 1,
  ]) );
}

int eventReleaseObject(object s) {
  if (base_name(s) == "/domains/islands/areas/forested/obj/statue") {
    call_out( (: eventDestruct :), 1);
    environment()->eventPrint("The chest crumbles after being relieved of its prize.");
    return 1;
  }
  return 1;
}