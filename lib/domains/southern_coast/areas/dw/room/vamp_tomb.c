/*  The tomb of the vampire */
#include "../newbie.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetShort("inside a tomb");
  SetLong("The dust of the ages fills the tomb, making it hard to "
          "discern any details. The walls of this tomb are covered "
          "in strange markings which seem to be words in a long "
          "forgotten tongue which can only be the Archaic language "
          "of the ancients. In the center of the room is a large "
          "sarcophogus which seems to be the focal point of the "
          "room.");
  SetListen( ([
     "default" : "The tomb is deathly quiet.",
    ]) );
  SetSmell( ([
     "default" : "The scent of dust is heavy in the air.",
    ]) );
  SetExits( ([
     "out" : NEWBIE_ROOM + "/field10",
     ]) );
  SetInventory( ([
      NEWBIE_NPC + "/vamp" : 1,
    ]) );
  SetItems( ([
     ({ "writing", "words", "markings" }) : "These words make "
                   "very little sense, and seem to have no meaning.",
     ({ "sarcophogus" }) : "This is a large coffin of the type used "
                           "by the massively wealthy in the ages "
                           "leading up to the GodsWar.",
    ]) );
 }
