#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("the central hallway of the Grand Palace");
  SetLong("The hallway runs off in three directions here. To the west "
          "the hallway leads to the exit of the palace. To the north, "
          "the audience chamber of the Daimyo sits, resplendent in glory "
          "for Clan Minamoto. To the south is a dimly lit room that "
          "does not seem to be decorated.");
  SetItems( ([
    ({ "hallway", "hall", "directions" }) :
    	 (: GetLong :),
    ({ "exit" }) :
    	 "The exit of the palace is west down the hallway.",
    ({ "chamber" }) :
    	 "The audience chamber of the Daimyo is north along the hallway.",
    ({ "room" }) :
    	 "The dimly lit room sits to the south of the hallway.",
    ]) );
  SetItemAdjectives( ([
    "room" : ({ "dimly", "lit" }),
    "chamber" : ({ "audience", "daimyo" }),
    "hallway" : ({ "central" }),
    ]) );
  SetSmell( ([
    "default" : "The perfume of the flowers brightens the room.",
    ]) );
  SetListen( ([
    "default" : "The sounds of palace life echo through the hallway.",
    ]) );
  SetInventory( ([
     TAI_RI_NPC "sam_guard" : random(6),
    ]) );
  SetExits( ([
    "north" : "p1",
    "west"  : "p4",
    "south" : "p3",
    ]) );
}
