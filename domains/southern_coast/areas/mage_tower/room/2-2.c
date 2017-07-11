#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;

string SearchFloor();
int BeenKeyed;
static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  BeenKeyed = 0;
  SetClimate("indoors");
  SetShort("a curve in the hallway");
  SetExits( ([
    "north" : "2-3",
    "west"  : "2-1",
    ]) );
  SetSmell( ([
    "default" : "A faintly rancid smell drifts in the room.",
    ]) );
  SetListen( ([
    "default" : "A soft gurgle comes from the west.",
    ]) );
  SetLong("The hallway curves around here, leading to the north "
          "and west.  To the west the hallway leads in a straight "
          "path across the face of the tower, while to the north "
          "the hallway curves in towards the center of the tower. "
        "The floor here appears to be made of the same loose "
          "stonework as the lower level.");
  SetInventory( ([
    ]) );
  SetItems( ([
    ({ "floor", "stonework" }) : "The floor tiles appear to "
                       "be made of a loose stonework.",
    ]) );
  SetSearch("floor", (: SearchFloor :) );
}

string SearchFloor() {
  if (BeenKeyed) {
    message("action", "The floor looks like someone has "
          "already moved tiles around.",
        this_player() );
    return "";
   }
    if (random(100) < this_player()->GetStatLevel("wisdom")) {
    new(TOWER_OBJ "key33")->eventMove(this_player());
    message("action", "You find a key under a loose tile.",
    this_player() );
  }
  send_messages("search", 
    "$agent_name $agent_verb around on the floor.",
    this_player(), 0, this_object() );
  return "";
}
