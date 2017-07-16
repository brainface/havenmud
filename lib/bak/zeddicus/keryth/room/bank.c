#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("indoors");
  SetAmbientLight(50);
  SetTown("Keryth");
  SetShort("the Bank of Keryth");
  SetLong("This wooden building contrasts with the snow outside and provides "
          "a safe environment for business transactions.  The room is utterly "
          "clean, almost to the point of sterility.  The Bank of Keryth is "
          "known for dealing in unusual currencies.");

  SetItems( ([
    ({ "building", "safe environment", "environment", "bank" }) : (: GetLong :)
  ]) );

  SetExits( ([ "out" : K_ROOM "main_05" ]) );
  SetListen( ([ "default" : "Silence dominates the room." ]) );
}
