/* Averath Burrow Chamber
*  Created By: Ohtar
*/

#include <lib.h>
#include "../avb.h"
inherit LIB_ROOM;

string WebSearch();


static void create() {
   room::create();
   SetShort("inside a large burrow");
   SetDomain("Averath");
   SetLong("This room resembles that of a small chamber. There "
           "is a human-sized table in the middle of the room. Spread "
           "around the base of the table are pools of dried up "
           "blood and many bones. The walls here are not visible "
           "at all due to the massive amounts of thick spider "
           "webs all over them. A large door lies south, if opened, "
           "it would allow access back towards the opening of the "
           "burrow. ");
SetItems( ([
            ({"room", "chamber"}) : (:GetLong:),
            ({ "blood", "stains" }) :
                 "The blood on the wall looks as if it squirted onto "
                 "the wall and then was smeared in by something.",
            ({ "web", "spider webs", "webs", "spider web" }) :
                 "The spider webs are very thick and covering every "
                 "inch of the walls. Some are old and dingy looking as "
                 "others appear to be shiny and newer looking.",
            ({ "wall","walls" }) :
                 "The walls are completely covered in spider webbing.",
            ({ "bone", "bones" }) :
                   "The bones laying here are broken in pieces. Some "
                   "are slightly rotted away and have maggots crawling "
                   "inside them. Others appear to be rather fresh "
                   "looking and still have meat attached to them.",
            ({ "pools", "pool" }) :
                 "The blood pools are mostly dried up stains. ",
            ({ "table" }) :
                 "The table is made up of granite. It has two straps "
                 "across it. There are many blood stains all over "
                 "the top surface as well as sides and base. There are "
                 "dried up rags spread across the top of it. ",
            ({ "rags" }) :
                 "The rags are laying on the table in the perfect "
                 "shape of a human body. They do not appear to have "
                 "been disturbed for a very long time.", 
            ]) );
SetItemAdjectives( ([
          "table" : ({ "granite" }),
          "blood" : ({ "dried", "smeared", "squirted"}),
          "bones" : ({ "broken", "rotted", "fresh" }),         
          "wall"  : ({ "covered"}),
          "web"   : ({ "thick", "old", "dingy", "shiny", "newer"}),
                 ] ) );
SetSmell( ([
      "default" : "Smells of rotted flesh and dried blood fill the air. ",
          ]) );
SetExits( ([ "south" : AVB_BURROW + "burrow8",
        ]) );
SetObviousExits("south");
SetInventory( ([ AVB_NPC + "widow_queen" : 1,
            ]) );
SetDoor("south", AVB_OBJ "triangle_door");
  call_other( AVB_OBJ "circle_door", "SetClosed", 1);
  call_other( AVB_OBJ "circle_door", "SetLocked", 1);
SetSearch( ([ "webs" : (: WebSearch :),
         ]) );

}

string WebSearch() { 
  if (this_player()->GetInCombat()) return "You're a bit busy at the "
                                           "moment.";
  if (GetExit("north")) {
    return "The webs have already been searched to reveal an exit to the "
           "north.";
    }
  AddExit("north", AVB_BURROW + "chamber1");
  return "You find an exit to the North!";
  }
