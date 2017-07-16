#include <lib.h>
#include "../minaret.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("inside an observatory");
  SetLong(
    "A large oval shaped enclosure is surrounded "
    "by the resin made walls of the observatory.  An "
    "opening in the roof allows for the telescope "
    "to stick out and pear at the sky.  The telescope "
    "in the center of the room is encircled with a "
    "wooden balustrade.  A large stone sculpture "
    "rests against the wall."
  );
  SetItems( ([
     ({ "wall", "walls", "observatory", "enclosure" }) : (: GetLong :),
     "balustrade" : "A wooden balustrade encircles "
         "the telescope.  It has been painted white.",
     ({ "cliff", "bluff", "sculpture", "cliff bluff" })  : 
         "The stone sculpture is shaped like "
         "a cliff bluff.  Water flows on top of it.",
    "water" : "Water flows out from the top of the sculpture, "
        "running along its top until it splashed off and down into "
        "a channel.",
    ({ "opening", "roof" }) : "The opening in the roof allows "
        "for the telescope to peer into the sky.",
     ]) );
  SetItemAdjectives( ([
    "balustrade" : ({ "wooden" }),
    "wall" : ({ "resin", "large", "oval" }),
    "sculpture" : ({ "stone", "large" }),
  ]) );
  SetListen( ([
    "default" : "Water splashes off the cliff bluff into a channel.",
    ]) );
  SetSmell( ([
    "default" : "Incense permeates the observatory.",
    ]) );
  SetInventory( ([
    MIN_NPC "/mystic" :1,
    MIN_OBJ "/ob_channel" : 1,
    MIN_OBJ "/telescope" : 1,
  ]) );
  SetExits( ([
    "out" : MIN_ROOMS "/path4t9",
  ]) );
}
