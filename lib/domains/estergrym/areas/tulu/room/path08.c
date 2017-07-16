/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../tulu.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("climbing a path near the top of a hill");
  SetExits( ([
    "north" : TULU_ROOM "hill01",
    "south" : TULU_ROOM "path07",
    ]) );
  SetLong(
    "The path ends here at the crest of the hill. To the south, the path leads back down "
    "the hill and back east to the Estergrym Mountains. Directly to the north, a scorched "
    "circle of blackened earth surrounds what can only be described as a henge of stone. "
    "Immense stone monuments form the circle, reaching easily 30 feet into the sky. No plants "
    "grow on the surface of this blasted hill."
    );
  SetSmell("The stench can easily be identified now as a mix of coppery blood and burnt meat.");
  SetItems( ([
    "path" : "The path leads back down the hill to the south.",
    ({ "circle", "henge" }) : "The circle of stone monuments forms a perfect circular henge.",
    "earth" : "The soil here is blackened and charred.",
    ({ "monument", "monuments" }) : "The stone monuments form a perfect circle.",
    ]) );
  SetItemAdjectives( ([
    "circle" : ({ "scorched", "stone", }),
    "earth"  : ({ "blackened", "scorched" }),
    "monument" : ({ "massive", "stone" }),
    ]) );
}