#include <lib.h>
#include "../../haven.h"
inherit LIB_ROOM;

int GuildCheck() {
  object who = this_player();
  
  if (who->GetGuild() != "order" && !creatorp(who)) {
    who->eventPrint("A strange repulsion prevents your going upstairs.");
    return 0;
  }
  return 1;
}

static void create() {
  ::create();
  SetTown("Haven");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "out" : H_ROOM "holy_path/hp2",
    ]) );
  AddExit("up", H_ROOM "sisterhood/upstairs", (: GuildCheck :) );
  SetShort("inside the cozy building");
  SetLong(
    "Though this building appeared to be cozy from the outside, inside it is "
    "very tidy and orderly. A stairway in the back of the building leads to "
    "a second level, but a firm aura prevents most people from going up. A "
    "large wooden counter stands near the front entrance, and on the opening "
    "is a little silver button."
    );
  SetInventory( ([
    H_ROOM "sisterhood/button" : 1,
    ]) );
  SetItems( ([
    ({ "counter" }) : "The counter is large and wooden. On its surface is a "
                      "small silver button.",
    ({ "stairs", "stairway" }) : "The stairs seem to ward off intruders.",
    ]) );
}
