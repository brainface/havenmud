#include <lib.h>
inherit LIB_ROOM;
#include "../rook.h"
 
static void create() {
  room::create();
  SetDomain("WestWood");
  SetShort("a section of tunnel");
  SetDayLong("The most notable feature of this room is the large "
    "gaping chasm leading down further into the earth.  A pathway "
    "leads along the edge of the chasm and descends down.  Small "
    "amounts of light filter in from the north, barely illuminating "
    "the room with enough natural light to cast shadows in strange "
    "ways on the walls.");
  SetNightLong("The most notable feature of this room is the large "
    "gaping chasm leading down further into the earth.  A pathway "
    "leads along the edge of the chasm and descends down.  No natural "
    "light filters into this room and it takes a lot of care to "
    "notice the edge of the chasm against the darkness of the room.");
  SetItems( ([
    ({"room"}) : (:GetLong:),
    ({"chasm","feature"}) : "This large hole appears to descend a "
      "long ways into the earth.",
    ({"earth"}) : "The earth here is cool to the touch and small "
      "litter the ground.",
    ({"light"}) : (query_night() ? "There is no light inside "
      "the tunnel." : "The light filters in ever so slightly from "
      "the room to the north."),
    ({"shadow","shadows","wall","walls"}) : "The small amounts of "
      "light here allow the stone walls to cast eery shadows about "
      "the room.",
    ({"path"}) : "The path leads along the edge of the wall and "
      "follows up an almost hidden set of stairs.",
  ]) );
  SetItemAdjectives( ([
    "feature" : ({"notable"}),
    "chasm" : ({"gaping","large"}),
    "light" : ({"small","amounts","natural"}),
    "shadow" : ({"strange"}),
  ]) );
  SetAmbientLight((query_night() ? SetAmbientLight(0) : 
    SetAmbientLight(5) ));
  SetClimate("indoors");
  SetExits( ([
    "down" : R_ROOM + "lair4",
    "north" : R_ROOM + "lair2",
  ]) );
  SetSmell( ([
    "default" : "The room smalls dank and of mold.",
  ]) );
  SetListen( ([
    "default" : "A small whistling of wind fills the room as air"
      "moves over the chasm.",
  ]) );
}
