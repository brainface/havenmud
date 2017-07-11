#include <lib.h>
inherit LIB_DOOR;
static void create(string town, string owner) {
  door::create();
  if (!town || !owner) return;
  SetSide("north", 
    ([ "id"       : "door",
       "short"    : "a sturdy door",
       "long"     : "This sturdy door prevents unwanted guests from bothering " + owner + ".",
       "lockable" : 1,
       "keys"     : town + "_" + owner + "_key"
     ]) );
  SetSide("south", 
    ([ "id"       : "door",
       "short"    : "a sturdy door",
       "long"     : "This sturdy door prevents unwanted guests from bothering " + owner + ".",
       "lockable" : 1,
       "keys"     : town + "_" + owner + "_key"
     ]) );
  SetClosed(1);
  SetLocked(1);
  SetLockStrength(500);
}
