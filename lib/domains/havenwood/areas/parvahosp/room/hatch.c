#include <lib.h>
inherit LIB_DOOR;

static void create() {
   ::create();
   SetSide("down", ([ "id" : ({ "hatchway","hatch" }),
                      "short" : "a hatchway",
                      "long" : "The hatchway, sturdy and made of wood, covers "
                         "up the exit going down.",
                      "lockable" : 1,
                      "keys" : "parvahospital_storagekey",
                 ]) );
   SetSide("up",  ([ "id" : ({ "hatchway","hatch" }),
                      "short" : "a hatchway",
                      "long" : "The hatchway, sturdy and made of wood, covers "
                         "the exit above.",
                      "lockable" : 1,
                      "keys" : "parvahospital_storagekey",
                 ]) );
   SetClosed(1);
   SetLocked(1);
   SetPick(1);
   SetLockStrength(2);
}
