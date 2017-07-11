//coded by Syra 1/98
//taken over by Zedd 12/98

#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("The Arctic Grapes Tavern");
  SetTown("Keryth");
  SetClimate("indoors");
  SetAmbientLight(55);
  SetLong("The Arctic Grapes Tavern is a small pub for the residents "
          "of Keryth. Its comfortable atmosphere is complimented by "
          "darkly stained captains chairs that line the wooden bar. "
          "Near the door, there a trail of snow that has been tracked "
          "in from outside.");
  SetItems( ([
    ({ "arctic grapes tavern", "grapes tavern", "arctic tavern", "tavern",
       "pub" }) :
       (:GetLong:),
    ({ "trail of snow", "snow", "trail" }) : 
       "A trail of snow that was tracked in from outside leads from the "
       "door towards the bar.  It must have been recently made, because it "
       "has not melted yet.",
    ({ "polished wooden bar", "wooden bar", "bar" }) :
       "A polished wooden bar sits to one side of the room, with a row of "
       "chairs in front of it.",
    ({ "darkly stained captains chairs", "darkly stained chairs",
       "dark chairs", "stained chairs", "captains chairs", "chairs",
       "stained captains chairs", "darkly stained captains chair",
       "dark chair", "stained chair", "captains chair", "chair", "bar stools",
       "bar stool", "stool", "stools" }) :
       "The stained bar stools are lined up against the bar.",
    ({ "heavy door", "door" }) :
       "A heavy door blocks the outside world from inside the tavern."
  ]) );
  SetExits( ([ "out" : K_ROOM + "/road3" ]) );
  SetListen( ([
    "default" : "The hustle and bustle of business fill the air."
  ]) );
  SetInventory( ([
//    "/std/npc/slinger" : 1,
    K_NPC + "/smithy" : 1,
    K_NPC + "/barkeep" : 1
  ]) );
}
