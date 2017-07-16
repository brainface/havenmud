#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;
int Searched;
string eventSearchSlab();

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  Searched = 0;
  SetClimate("indoors");
  SetShort("an empty room");
  SetExits( ([
    "north" : TOWER_ROOM "1-5",
    ]) );
  SetInventory( ([
    TOWER_NPC "spectre" : 1,
    ]) );
  SetLong("The hallway ends here in a room with no furnishings. "
          "Back to the north the hallway begins to curve towards "
          "the center of the tower. The floor here is made of loose "
          "slabs of stone. The coating of dust which is all consuming "
          "seems to hardly bother this area at all.");
  SetItems( ([
    "dust" : "There is very little dust here.",
   ({ "slab", "slabs", "stone" }) : "The loose slabs of stone look "
           "like they would well be worth a more careful look.",
    ]) );
  SetItemAdjectives( ([
    "slab" : "loose",
    ]) );
  SetSearch("slab", (: eventSearchSlab :) );
}

string eventSearchSlab() {
  if (Searched) {
   /*  send_messages( ({ "search", "find" }),
      "$agent_name $agent_verb near the floor and $agent_name "
      "$agent_verb nothing interesting.",
      this_player(), 0, this_object() );
      */
	return "You search the floor and find nothing interesting."; 
    }
  message("action", this_player()->GetCapName() + " searches "
                    "near the floor and looks interested in "
                    "something.", this_object(), this_player() );
  Searched = 1;                    
  return "You move a slab over to the side, and beneath it is written \"This tower is cursed.  Flee for your life.\" ";
}
