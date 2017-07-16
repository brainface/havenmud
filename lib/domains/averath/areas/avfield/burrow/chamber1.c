/* Averath Burrow Hidden Room
*  Created By: Ohtar
*/

#include <lib.h>
#include "../avb.h"
inherit LIB_ROOM;

int BeenDone;
int DoSearch();


static void create() {
   room::create();
   SetShort("a dark hidden room");
   SetDomain("Averath");
  SetClimate("underground");
   SetLong("This room is rather small and dark. The floors are "
           "covered with blood. Everything else here is very "
           "bare. However, in one corner there is a large pile "
           "of humanoid bones. The only exit from this foul "
           "room is back south. ");
   SetItems( ([
            ({"room"}) : (:GetLong:),
            ({ "blood" }) :
                 "The blood on the floors looks to have run from "
                 "the bones in the corner. It is mostly dried up. ",
            ({ "wall","walls" }) :
                 "The walls are completely bare.",
            ({ "bone", "bones" }) :
                   "The bones laying in the corner are broken in "
                   "pieces. Some are slightly rotted away and "
                   "have maggots crawling inside them. Others "
                   "appear to be rather fresh looking and still "
                   "have meat attached to them. One of the bones "
                   "appears to be a partly decayed hand that "
                   "is sticking out of the pile. "
                   "sticking out of the middle of the pile.",
            ({ "hand" }) : 
                "The partly decayed hand is still intact enough "
                "to remaind closed. ",
            ]) );
SetItemAdjectives( ([
          "hand"  : ({ "decayed" }),
          "blood" : ({ "dried"}),
          "bones" : ({ "broken", "rotted", "fresh" }),         
          "wall"  : ({ "bare"}),
                 ] ) );
SetSearch( (["hand" : (: DoSearch :) ]) );
SetSmell( ([
      "default" : "The putrid smell of rotted flesh erodes the air. ",
          ]) );
SetExits( ([ "south" : AVB_BURROW + "chamber",
        ]) );
}


varargs void reset(int count) {
   room::reset();
  BeenDone = 0;
  }
int DoSearch() {
  if (BeenDone) {
      message("blah", "You don't find a thing.", this_player());
      return;
         }
    new(AVB_OBJ + "/mnpscroll")->eventMove(this_player());
  message("blah", "You find a scroll!", this_player());
  BeenDone = 1;
}
