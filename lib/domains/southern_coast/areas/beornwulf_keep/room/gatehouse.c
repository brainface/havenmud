#include <lib.h>
#include "path.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("the gatehouse");
    SetLong("The gatehouse of the keep is quieter than the outside, with "
          "the sounds of battle muffled by the enormous doors.  The room "
          "is sufficiently lit by torches lining the walls, which extend "
          "to the east and west towards other parts of the keep.");
    SetItems( ([
          ({ "torches" }) :
          "The torches line the walls of the keep, with one torch set "
          "every 6 feet.",
          ({ "gatehouse", "room" }) :
          (: GetLong :),
          ({ "walls" }) :
          "The walls are lined with torches.",
          ({ "doors" }) :
          "The doors are dark and foreboding from this side.",
      ]) );
    SetExits( ([
          "out" : BEORN_ROOM + "field3.c",
          "west" : BEORN_ROOM + "hall1.c",
          "east" : BEORN_ROOM + "hall2.c",
      ]) );
    SetObviousExits("out, west, east");
    SetInventory( ([
       BEORN_NPC + "hsoldier.c" : 4,
      ]) );
    SetClimate("indoors");
    SetAmbientLight(30);
}
