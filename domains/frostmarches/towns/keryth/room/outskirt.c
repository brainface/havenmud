//coded by Syra 11/97
//taken over by Zedd 12/98

#include <lib.h>
#include "../keryth.h"

#define FROST 0

inherit LIB_ROOM;

int PreFrost();

static void create() {
  room::create();
  SetShort("along a path");
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetLong("A range of mountains, known as the Frost Mountains, "
          "stand ominously before you to the north, while to "
          "the southwest is the comfort of the town of Keryth. "
          "Many travelers who have dared to voyage into the "
          "Frost Mountains have perished.");
  SetItems( ([
    ({ "arctic path", "path" }) : (:GetLong:),
    ({ "frost mountains", "rock", "mountain range", "range", "mountains",
       "mountain" }) :
       "Made of nothing except rock and snow, the Frost mountains are "
       "unforgiving to travelers.",
    ({ "great big snowdrifts", "great big snowdrift", "big snowdrifts",
       "big snowdrift","snowdrift", "snowdrifts", "drift", "drifts",
       "snow" }) :
       "The snow on the mountains is blown into great big snowdrifts."
  ]) );
  SetExits( ([ 
    "southwest" : K_ROOM + "/road3",
    "west"      : K_ROOM + "/wharf",
     ]) );
  AddExit("north","/domains/frostmarches/areas/frost_mt/room/mt1", (: PreFrost :));
  SetListen( ([ "default" : "All is silent." ]) );
}

int PreFrost() {
  if (this_player()->GetProperty("KerythWander")) return 0;
  if (FROST && !creatorp(this_player())) {
    message("my_action",
      "Deep fallen snow blocks your way into the Frost Mountains",
      this_player() );
    return 0;
  }
  return 1;
}
