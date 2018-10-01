// by Dahaka
// Aug 2004

#include <lib.h>
#include <domains.h>
#include "../../drazh.h"

inherit LIB_ROOM;
string SearchMe();
int BeenDone;

static void create() {
  room::create();
  BeenDone = 0;
  SetTown("Drazh");
  SetClimate("underground");
  SetAmbientLight(10);
  SetShort("watchmen training hall");
  SetLong(
     "The many stone pillars around the hall support the high vaulted ceiling "
     "of this large rectangular stone chamber. Pieces of the ceiling are scattered "
     "throughout the stone hall. There are six pillars parallel to the south "
     "wall and two pillars on either side of the north wall, all which are "
     "supporting the ceiling of this large hall. Along the south wall, there "
     "are three doorways that are equally spaced along the wall. Hanging from "
     "the pillars are banners of red and black cloth."
     );
  SetItems( ([
     ({"pillars","pillar"}) :
     "Around the large stone hall are ten large stone pillars that are supporting "
     "the high vaulted ceiling. Six of the pillars are parallel to the south wall. "
     "The other two pairs are parallel to the north wall but are away from entrance "
     "to this stone hall.",
     ({"hall","ceiling","chamber"}) : (: GetLong :),
     ({"rubble","pieces","stone","floor"}) :
     "There are many pieces of the stone ceiling, scattered about the floor of "
     "this hall. There could be something hidden here.",
     ({"doorway","doorways","south wall"}) :
     "Along the south wall, there are three doorways equally spaced from each "
     "other. The middle doorway has a lot of debris and rubble blocking it. A "
     "dark thick cloth is draped across the west doorway. The east doorway "
     "leads into a small chamber.",
     ({"armoury","east doorway","east door","eastern doorway"}) :
     "This doorway leads into a small chamber that is off of the stone training "
     "hall.",
     ({"war room","west doorway","west door","western doorway"}) :
     "This doorway has a dark thick cloth draped across its threshold.",
     ({"middle doorway","middle door"}) :
     "This doorway is blocked by debris that had spilled forth from the inside.",
     ({"banners","banner","cloth"}) :
     "These red and black banners made from cloth, depict an equilateral "
     "triangle, consisting of three overlapping lines, with one of the "
     "points facing down hanging from the walls of the passageway.",
     ]) );
  SetItemAdjectives( ([
     "pillars" : ({"ten","large","stone","many"}),
     "hall"    : ({"large","stone","rectangular"}),
     "doorway" : ({"three"}),
     "banners" : ({"red","black","cloth"}) 
     ]) );
  SetListen( ([
     "default" : 
     "The ringing of steel hitting steel echos within the walls.",
     ]) );
  SetSmell( ([
     "default" : 
     "The stench of blood and sweat wafts through the air.",
     ]) );
  SetInventory( ([
     V_NPC + "recruit" : 3,
     V_NPC + "trainer" : 1,
     ]) );
  SetEnters( ([
     "war room" : V_ROOM + "misc/war_room",
     "armoury"  : V_ROOM + "misc/armoury"
     ]) );
  SetExits( ([
     "north" : V_ROOM + "main_road/d_road1",
     ]) );
  SetSearch( ([
     "default" : (: SearchMe :)
     ]) );
}

varargs void reset(int count) {
   room::reset();
   BeenDone = 0;
}


string SearchMe() {
   if (BeenDone) {
      message("other_action",
               this_player()->GetCapName() + " searches about the room.",
               this_object(), this_player() );
      return "It seems that a search has already been conducted here.";
   }
   new(V_OBJ + "newbie_axe")->eventMove(this_object());
   message("other_action",
           this_player()->GetCapName() + " search around the room.",
           this_object(), this_player() );
   BeenDone = 1;
   return "You find an axe!";
}