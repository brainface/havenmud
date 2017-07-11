#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetNightLight(10);
  SetObviousExits("northwest, northeast");
  SetExits( ([
       "northeast" : CAMP_ROOM + "/cl5",
       "northwest" : CAMP_ROOM + "/cl2",
         ]) );
  SetShort("a clearing in the camp");
  SetInventory( ([
       CAMP_NPC + "/slash_bandit" : 2,
       CAMP_NPC + "/dog" : 2,
    ]) );
  SetDayLong("The clearing seems to be less of a clearing and more \n"
            "of a path between to larger clearings.  The path continues \n"
           "off to the northeast and northwest.");
  SetNightLong("The stars light up this path brightly.  This small \n"
               "clearing seems to be more of a trail than a true clearing. \n"
               "The path continues to the northwest and northeast.");
 }
