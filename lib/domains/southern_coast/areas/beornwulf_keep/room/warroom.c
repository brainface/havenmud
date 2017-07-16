#include <lib.h>
#include "path.h"

inherit LIB_ROOM;
static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(50);
    SetShort("Beornwulf's war room");
    SetLong("This is Lord Beornwulf's war room, where the tactics and "
          "strategies for the battle waging outside are determined.  The "
          "room is in a state of disorder, with papers and furniture laying "
          "wherever they happened to fall.");
    SetItems( ([
          ({ "papers" }) :
          "The papers have plans for defenses and counterattacks, but most "
          "have been discarded or torn up.",
          ({ "war room", "room" }) :
          (: GetLong :),
          ({ "furniture" }) :
          "There are several chairs scattered about the room, and a huge "
          "table is lying on its side in the center.",
          ({ "chairs" }) :
          "The chairs were once used to seat higher ranking members of "
          "Beornwulf's personal guard, but it seems most have gone unused for "
          "a long while.",
          ({ "table" }) :
          "The heavy oak table looks like it would be difficult to move.",
           ]) );
    SetExits( ([
          "north" : BEORN_ROOM + "hall3.c",
            ]) );
    SetObviousExits("north");
    SetInventory( ([
          BEORN_NPC + "humancapn.c" : 1,
          ]) );


    SetClimate("indoors");
    SetAmbientLight(35);
}
