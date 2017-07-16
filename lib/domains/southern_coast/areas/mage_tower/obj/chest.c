#include <lib.h>
#include "../mage_tower.h"
inherit LIB_STORAGE;
int eventLockChest();

static void create() {
  ::create();
  SetKeyName("chest");
  SetDamagePoints(25000);
  SetLockStrength(1000);
  SetShort("a heavy oak chest");
  SetMass(10000);
  SetId( ({ "chest" }) );
  SetAdjectives( ({ "heavy", "oak" }) );
  SetLong("This heavy chest is made of a stout oak. "
          "It has a thick metal lock on the front which "
          "seems to be of a sturdy make.");
  SetClosed(1);
  SetCanClose(1);
  SetPreventGet("You cannot pick that up!");
  SetMaxCarry(7500);
  SetCanLock(1);
  SetLocked(1);
  SetKeys( ({ "chest_key" }) );
  SetInventory( ([
    TOWER_OBJ "amulet" : 1,
  ]) );
}


varargs mixed eventOpen(object who, string id, object tool) {
  who->AddQuest("the Ransacker of the Mage Tower",  
                "Haven Mage Tower");
  SetInventory( ([
    TOWER_OBJ "amulet" : 1,
  ]) );
  call_out( (: eventLockChest :), 1);
  ::eventOpen(who, id, tool);
}

varargs void reset(int count) {
  ::reset(count);
  SetClosed(1);
  SetInventory( ([
    TOWER_OBJ "amulet" : 1,
  ]) );
  SetLocked(1);
}

mixed eventUnlock(object who, object key) {
  mixed res = ::eventUnlock(who, key);
  if (res == 1) { key->eventDestruct(); }
  return res;
}


int eventLockChest() {
  SetLocked(1);
  return 1;
}
