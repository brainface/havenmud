#include <lib.h>
#include "../haven.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the Imperial Road");
  SetObviousExits("east, west");
  SetDayLong("The road leads to the east and west here, with "
            "traffic moving both ways in a steady stream.  The "
            "crowds seem to be quickly moving about their business, "
            "with no one stopping for long periods of time.  To the "
            "north is the Haven Town bank, where monetary security "
            "is insured for the citizens of the town.  Off to the "
            "south is the inn known as \"Ruperts Hole\", which is "
            "one of the finer places in town.");
  SetNightLong("The road leads to the east and west from here, and "
               "even at this hour of night the traffic moves along "
               "at a steady pace.  To the north is the Haven Bank, "
               "which is the financial mecca of the city.  To the "
               "south is \"Ruperts Hole\", one of the finest houses "
               "of dining and lodging in the known world.");
  SetItems( ([ 
             ({ "inn","ruperts hole","ruperts","hole" }) :
                   "This is Ruperts Hole, you could <enter> it.",
              ({ "bank","haven bank","haven town bank" }) :
                   "This is the Haven Bank, perhaps you should <enter> it."
               ]) );
  SetEnters( ([
               ({ "inn","ruperts","ruperts hole","hole" }) :
                  H_ROOM + "/ruperts/inn",
               ({ "bank","haven bank","haven town bank" }) :
                  H_ROOM + "/misc_buildings/bank" ]) );
  SetExits( ([
              "west" : H_ROOM + "imperial_road/ir3",
              "east" : H_ROOM + "imperial_road/ir5" ]) );
  }
