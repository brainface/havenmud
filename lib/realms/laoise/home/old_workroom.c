/*  This is a basic workroom object that connects
 *  your workroom to Olympus, the home of the GodBoard.
 *  Please make sure to read that board at least once per
 *  day, as it is the prime means of communication.
 *  Created by Duuktsaryth@Haven
 */
#include <lib.h>
#include <std.h>
#include <dirs.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("A black void");
  SetLong("Suspended in a black void is a tangle of spider webbing. "
    "It thickens in the middle, forming an area for sitting and reclining. "
    "Papers scattered across the webbing suggest this is a work area.");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetItems( ([
    ({"web", "webbing"}) :
    "This appears to be spider's webbing, but it is of an "
    "unusual thickness. In the center there is a bulge that "
    "resembles a couch.",
    ({"paper", "papers"}) :
    "The papers are covered with notes and sketches all in the "
    "same messy handwriting.",
    ({"chair", "couch", "thickening"}) :
    "The webbing bunches together here, forming a decent "
    "approxmation of a couch.",
  ]) );
  SetSmell( ([
    "default" : "A sharp metallic tang cuts through the air.",
    ]) );
  SetListen( ([
    "default" : "Chittering and clicking echo through the darkness.",
    ]) );
  SetExits( ([
     "north" : DIR_STANDARD_DOMAIN "/staffroom",
     "east"  : STD_AREA "room/basic",
    "south" : "/realms/laoise/home/other_room",
      ]) );
  }
