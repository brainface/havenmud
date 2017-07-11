#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "north" : YOZRATH_ROOM "gate4",
    "south" : "/domains/yozrath/virtual/" "desert/0,-2",
    ]) );
  SetShort("at the Southern Gate to the open desert");
  SetLong(
    "To the south, the Southern Gate opens a path into the open bled. "
    "To the north, the City of Yozrath opens into the bustling center "
    "of trade for the desert. Buildings line the road, but from here "
    "none of them appear to be accessable. Surrounding the city is a "
    "large stone wall to defend against desert raiders."
    );
  SetItems(([
    "gate" : "The Southern Gate leads out into the open bled.",
    ({ "building", "buildings" }) : "Various buildings line the "
             "road, but none appear accessable from here.",
    "wall" : "The stone wall which guards the city is large and "
             "very impressive.",
    ]) );
  SetItemAdjectives( ([
    "gate" : ({ "south", "southern" }),
    "building" : ({ "various", }),
    "wall" : ({ "city", "stone" }),
    ]) );
  SetSmell("The smells of the city are overwhelming.");
  SetListen("Conversation echoes at all hours.");
  SetInventory( ([
    YOZRATH_NPC + "guard" : 2,
    ]) );                                 
}
