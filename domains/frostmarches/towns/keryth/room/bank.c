//coded by Syra 11/97
//taken over by Zedd 12/98

#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(50);
  SetTown("Keryth");
  SetShort("the Keryth Bank");
  SetLong("This wooden building contrasts with the snow outside and provides "
          "a safe environment for business transactions.  The room is "
          "utterly clean, almost to the point of sterility.  The Keryth bank is "
          "known for dealing in unusual currencies.");
  SetItems( ([
    ({ "wooden building", "building", "safe environment", "environment",
       "bank" }) :
       (: GetLong :),
    ({ "snow" }) :
       "The snow outside would make one appreciate the warmth and security "
       "of being indoors."
  ]) );
  SetExits( ([ "out" : K_ROOM "/road2" ]) );
  SetInventory( ([ K_NPC "/banker" : 1 ]) );
  SetListen( ([ "default" : "Silence dominates the room." ]) );
}
