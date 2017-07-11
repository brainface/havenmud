#include <lib.h>
#include "../goblins.h"
inherit LIB_ROOM;

int GuildCheck();

static void create() {
  room::create();
  SetShort("a well used path");
  SetLong("The path continues to the northwest and to the south. "
          "To the south, the path leads to a very large tent "
          "which seem to be of some importance to the town. "
          "The grasses seem to be trampled here. There is a "
          "heavy brown tent here with a strange aura protecting it." 
          );
  SetSmell( ([
      "default" : "The reek of decaying food comes from the south.",
      ]) );
  SetListen( ([
     "default" : "The sounds of goblin laughter come from the south.",
      ]) );
  SetItems( ([
    "tent" : "This tent is the home of the sworn Goblin Horde, the Khan's Army.",
    ]) );
  SetItemAdjectives( ([
    "tent" : ({ "heavy", "brown" }),
    ]) );
  AddEnter("tent", GOBLIN_TENT "horde", (: GuildCheck :) );
  SetExits( ([
     "northwest" : GOBLIN_ROOM + "m_3",
     "south"     : GOBLIN_ROOM + "m_7",
    ]) );
  SetInventory( ([
      GOBLIN_NPC + "slash_medium" : 3,
      GOBLIN_OBJ "well" : 1,
    ]) );
  }

int GuildCheck() {
  object who = this_player();
  
  if (who->GetGuild() != "horde" && !creatorp(who)) {
    who->eventPrint("Somehow you just can't muster the courage to enter that tent.");
    return 0;
  }
  return 1;
}
