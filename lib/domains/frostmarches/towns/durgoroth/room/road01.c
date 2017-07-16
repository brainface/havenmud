#include <lib.h>
#include <domains.h>
#include "../durgoroth.h"
inherit LIB_ROOM;

int PreExit();

static void create() {
  ::create();
  SetClimate("sub-arctic"); 
  SetShort("inside the Ruins of Durgoroth");
  SetTown("Durgoroth");
  SetExits( ([
    "north" : DURG_ROOM "road02",
    ]) );
  AddExit("south",FROSTMARCHES_AREAS + "outpost/room/north_gate",(: PreExit :) );
  SetSmell( ([
    "default" : "The smells of copper blood and rotting meat ruin the air.",
    ]) );
  SetListen( ([
    "default" : "Quiet rustles of movement mix with the occasional scream.",
    ]) );
  SetDayLong(
    "By day, the ruins of Durgoroth appear much as they did before the sack. "
    "Walls rise along the road and the wreckage of a huge iron gate lie "
    "discarded by the roadside. A broken path leads north into the city, "
    "and a cold, lonely road heads south away from this fallen jewel."
    );
  SetNightLong(
    "By night, the ruins of Durgoroth give a haunted appearance of fallen "
    "might and painful collapse. The walls of the city rise by the side of the "
    "road, but the once-mighty iron gates of Durgoroth lie wasted and ruined "
    "by the roadside. A broken path leads north into the city while a cold, "
    "lonely road heads away from it."
    );
  SetItems( ([
    "ruins" : "The ruins of Durgoroth rise to the north.",
    ({ "wall", "walls" }) : "The walls of the city appear to be large and "
                            "unbroken, the gate having been breached long "
                            "before the walls ever were.",
    ({ "gate", "gates" }) : "The gates of the city lie discarded by the roadside.",
    "road" : "The Durgoroth Road continues to the south.",
    "path" : "A broken path leads north into Durgoroth.",
    ]) );
  SetItemAdjectives( ([
    "wall" : ({ "city", }),
    "gate" : ({ "huge", "iron", "once", "mighty" }),
    "path" : ({ "broken" }),
    "road" : ({ "cold", "lonely" }),
    ]) );
  SetInventory( ([
    ]) );
}

int PreExit() {
  if (this_player()->id("durg_wander")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}

