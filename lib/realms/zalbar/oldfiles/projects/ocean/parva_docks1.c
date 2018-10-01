#include <lib.h>
#include "../parva.h"
#include <domains.h>
#include "/domains/havenwood/areas/assassin_hall/assassin_hall.h"

#define GUILD "twilight"

inherit LIB_FISHING;

int PreExit(string dir);

static void create() {
   ::create();
   SetProperty("coastal", 1);
   SetShort("the docks at Parva");
   SetLong(
     "The wharfs stretch out to the west, protecting the city from the endless crash of the "
     "ocean waves. To the east the sea extends far into the distance, calling to the spirit "
     "of many in the city to explore. The docks are much sturdier than they appear, though "
     "they are designed in a free-floating fashion that occasionally causes the unwary "
     "landlubber to mistake his footing."
     );
   SetItems( ([
     ({ "wharf", "wharfs" }) : "The wharf is to the west.",
     ({ "sea", "ocean" }) : "The sea extends endlessly to the east.",
     ({ "dock", "docks" }) : "The docks are a free-floating but sturdy design.",
     ]) );
   SetItemAdjectives( ([
     ]) );
   SetListen("The waves rock against the docks and then crash noisily into the shore.");
   SetSmell( "Sea salt, gutted fish, and trash make the water stink pungently.");
   SetExits( ([
     "west" : PARVA_ROOM + "wharf3",
     "east" : INNERSEA_VIRTUAL "ocean/30,46",
     ]) );
   AddExit("down", AH_ROOM + "corridor1", (: PreExit :) );
   SetSpeed(8);
   SetFish( ([
     PARVA_OBJ + "fish_small" : 200,
     PARVA_OBJ + "fish_trash" : 20,
     ]) );
   SetChance(50);
   SetMaxFishing(5);
   SetInventory( ([
     PARVA_NPC + "fisherman" : 1,
     PARVA_OBJ + "yacht"     : 1,
     PARVA_OBJ + "ferry"     : 1,
     PARVA_NPC + "ferrycaptain" : 1,
     PARVA_NPC + "ticketagent" : 1,
     ]) );
}


int PreExit(string dir) {
  if ( (this_player()->GetGuild() == GUILD) || (creatorp(this_player()) ) )  return 1;
  message("my_action",
          "%^BLUE%^A wave crashes against the dock, swaying it violently "
          "and knocking you from your "
          "feet!%^RESET%^", this_player() );
  message("other_action", "%^BLUE%^A wave crashes against the dock, "
          "swaying it violently!%^RESET%^",
          this_object(), this_player());
  this_player()->eventCollapse();
  return 0;
}

string GetObviousExits() {
  if (this_player()->GetGuild() == GUILD) return ::GetObviousExits();
  return (implode(GetExits() - ({ "down" }), ", "));   
}

