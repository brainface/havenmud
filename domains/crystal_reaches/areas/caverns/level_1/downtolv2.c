/*  Down to Level 2  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a passage leading downward");

  SetLong("A passage leads down deeper into the earth here.  In both "
          "directions you cannot see very far, as the passageway is twisting "
          "and turning.  However the path leads generally down deeper into "
          "the ground, and also back to the caverns to the southeast.  This "
          "tunnel seems to be used little as the ground underfoot is uneven "
          "and rough.");

  SetSmell( ([
    "default"  :  "The air seems old and heavy here."
  ]) );

  SetListen( ([
    "default"  :  "It is deathly quiet here."
  ]) );

  SetExits( ([
    "down"       :  ROOMLV2 + "/cave2a",
    "southeast"  :  ROOMLV1 + "/cave1c",
  ]) );
  SetObviousExits("southeast, down");

  SetItems( ([
    ({ "passage leading downward", "passage down", "passage downward",
       "passage" })  :  (: GetLong :),
    ({ "ground" })  :
       "The path is uneven and rough, which provides good purchase in the "
       "spots where the passage becomes steep.",
    ({ "tunnel", "passageway" })  :
       "The passage winds and curves around, become steep at some points, and "
       "relatively flat in others.  It leads downwards and to the northwest.",
    ({ "earth" })  :
       "Earth, as in the ground?? So maybe Kailie would be a better word?",
  ]) );
}
