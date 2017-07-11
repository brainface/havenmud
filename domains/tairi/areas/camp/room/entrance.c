#include <lib.h>
#include "../camp.h"
#include <domains.h>
#define WORLD  TAIRI_VIRTUAL "tairi_path/-3,0"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetNightLight(10);
  SetShort("a clearing near a encampment");
  SetExits( ([
    "north" : WORLD,
    "south" : CAMP_ROOM + "cl2",
    ]) );
  SetDayLong("The clearing is littered with small amounts of trash, all "
             "of which leads this place to have a nearly sinister feel, "
             "as if the residents have little regard for their surroundings "
             "and couldn't care less about the appearance.  A small path "
             "leads off to the north, which seems to lead to a cobblestone "
             "road of some type.  Off to the south is another clearing.");
  SetNightLong("The clearing sparkles in the starlight, with reflections "
               "bouncing off of small pieces of trash and refuse left "
               "by the inhabitants.  There is a small path which leads to "
               "a cobblestone path off to the north, while to the south is "
               "another clearing.");
  SetItems( ([
             ({ "trash", "refuse", "garbage", "litter" }) :
                 "This is just random debris left by the locals.",
               ]) );
  SetSmell( ([
              "default" : "The trash gives off a distasteful odor.",
             ]) );
  SetListen( ([
               "default" : "The sounds of life can be heard to the south.",
              ]) );
  }
