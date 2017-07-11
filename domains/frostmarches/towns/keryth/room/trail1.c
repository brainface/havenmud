//coded by Syra 11/97
//taken over by Zedd 12/98

#include <lib.h>
#include "../keryth.h"

#define KERYTH 0

inherit LIB_ROOM;

int PreKeryth(string);

static void create() {
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetShort("Outside of Keryth");
  SetTown("Keryth");
  SetLong("While standing on the edge of town, one is likely to notice the "
          "informal, sprawling atmostphere of Keryth.  It is most likely "
          "that it was quickly put up, and not much thought of organization "
          "was made by the towns people.  The trail continues northwest into "
          "town, and south.");
  SetItems( ([
    ({ "town" }) : (:GetLong:),
    ({ "path", "trail" }) : 
       "The path contines northwest into town, and southwest away from "
       "town.  It is impossible to stray from the path, because the deep "
       "snow makes any other direction impassable.",
    ({ "deep snow", "layers of snow", "snow" }) :
       "Storms recently have accumulated several feet of snow.  It makes "
       "travel without a path difficult.",
  ]) );
  SetExits( ([ "south" : "/domains/frostmarches/virtual/frostmarchrd/0,60" ]) );
  AddExit("northwest", K_ROOM + "/road1.c", (:PreKeryth:) );
  SetListen( ([
    "default" : "There is no sound except the occasional crunch when a "
                "traveler's foot penetrates the layers of snow.",
  ]) );
}

int PreKeryth(string dir) {
  if (KERYTH && !creatorp(this_player())) {
    message("my_action", "Deep fallen snow blocks your way into Keryth.",
      this_player() );
    return 0;
  }
  return 1;
}
