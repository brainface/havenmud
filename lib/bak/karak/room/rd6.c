#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Ahriman's Passage");
  SetObviousExits("east");
/*
  SetDayLong("This intersection is lifeless and quiet compared to the "
             "rest of Ahriman's Passage east of here.  A thin "
             "cobbled street known as Marauder's Meander runs north "
             "and south from here.  A chill wind blows in from the "
             "cemetary to the west.");
*/
  SetDayLong(
    "This intersection is lifeless and quiet, compares to the "
    "rest of Ahriman's Passage. East of here the street widens "
    "as it reaches more populated areas. A  chill wind blows from the "
    "cemetery to the west.",
  );
  SetNightLong("This deserted intersection is both quiet and dark.  "
               "There are a few signs of life to the east, but the other "
               "directions just lead into darkness.  A bitterly cold breeze "
               "seems to be coming from the west.");
  SetItems( ([
    ({"street"}) : "The street is narrow here, but widens to the east as it "
    "reaches the more populated parts of Ahriman's Passage.",
    ({ "intersection","dunedain's passage","passage","marauder's meander",
       "meander" }) :
       (: GetLong() :),
    ({"cemetery", "graveyard"}) :
       "To the west, a dark and deserted cemetary stands."
  ]) );
  SetItemAdjectives( ([
    "cemetery" : ({"dark", "deserted"}),
    "street" : ({"narrow","main"}),
  ]) );
  SetExits( ([
    "east" : K_ROOM + "/rd5"
  ]) );
  SetEnters( ([
    ({ "graveyard","cemetary" }) : K_ROOM + "/grave"
  ]) );
}
