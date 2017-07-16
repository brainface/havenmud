// SetItems/Adj added by Aless 2011

#include <lib.h>
#include "../../haven.h"
inherit LIB_CHAPEL;

static void create() {
  ::create();

  SetShort("a small holy grove");
  SetDayLong(
    "During the day, this grove is a pleasant reminder that elves "
    "have great history as woodland creatures. The trees rise into "
    "the distant sky, obviously well-tended trees of great importance "
    "to the local elves. A small footpath leads back south to the "
    "Galleon's Passage. This area would serve as a holy site for "
    "the few elves that still practice the Old Ways."
    );
  SetNightLong(
    "During the night, this grove is a shadowy reminder that elves "
    "have ancient ties to the woods. The trees rise into "
    "the dark sky, their stature bearing the weight the history of "
    "the Elves. A small footpath leads back south to the "
    "Galleon's Passage. This area would serve as a holy site for "
    "the few elves that still practice the Old Ways."
    );
  SetListen("The quiet rustle of the trees is a calming reminder of wilder days.");
  SetSmell("The floor of the grove is well tended and lacks the smell of rot.");
  SetReligion( ({ "Kylin" }) );
  SetItems( ([
    ({ "grove", "area", "site", "holy site", "woods" }) : ( :GetLong: ),
    ({ "tree", "trees" }) : "Great trees rise into the distant sky, with giant "
       "trunks and large healthy leaves, they are obviously nurtured with "
       "great love.",
    ({ "footpath", "path", "passage" }) : "A small tidy footpath leads from "
       "the grove back towards the south.",
    ({ "leaf", "leaves" }) : "Each leaf is vibrant and healthy, large testaments "
       "to the care and devotion of the elves.",
    ]) );
  SetItemAdjectives( ([
    "tree" : ({ "great", "giant", "nurtured", "loved", "well-tended" }),
    "path" : ({ "small", "tidy" }),
    "leaf" : ({ "large", "vibrant", "healthy" }),
    ]) );
  SetInventory( ([
    H_NPC"istil"      : 1,
    H_NPC "metadruid" : 1,
    ]) );  
  SetExits( ([
    "south" : H_ROOM "galleons_passage/gp5",
    ]) );

}
