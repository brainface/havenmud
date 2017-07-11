#include <lib.h>
#include "../camp.h"
#include <domains.h>
#define WORLD  SOUTHERN_COAST_VIRTUAL "havenroad/22,0"
inherit LIB_ROOM;

int NPCCHECK();

static void create() {
  room::create();
  SetNightLight(10);
  SetShort("a clearing near a camp");
  SetObviousExits("north, south");
  SetExits( ([
           "south" : CAMP_ROOM + "/cl2",
            ]) );
  AddExit("north", WORLD, (: NPCCHECK :) );            
  SetDayLong("The clearing is littered with small amounts of trash, all \n"
             "of which leads this place to have a nearly sinister feel, \n"
             "as if the residents have little regard for their surroundings \n"
             "and couldn't care less about the appearance.  A small path \n"
             "leads off to the north, which seems to lead to a cobblestone \n"
             "road of some type.  Off to the south is another clearing.");
  SetNightLong("The clearing sparkles in the starlight, with reflections \n"
               "bouncing off of small pieces of trash and refuse left \n"
               "by the inhabitants.  There is a small path which leads to \n"
               "a cobblestone path off to the north, while to the south is \n"
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

int NPCCHECK() {
  if (this_player()->id("bandit_camp")) {
    if (this_player()->GetOwner() == "") return 0;
    }
  return 1;
}
