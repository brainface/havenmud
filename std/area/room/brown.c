#include <lib.h>
#include "../area.h"
#include <std.h>
string SearchMe();
inherit LIB_ROOM;
int BeenDone;

static void create() {
  room::create();
  BeenDone = 0;
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("inside the brown tent");
  SetExits( ([
     "out" : AREA_ROOM "room1",
       ]) );
  SetSearch( ([
       "default" : (: SearchMe :)
       ]) );
  SetLong("This tent seems to be a ragger mismatch of chaos and order. "
          "Lying on the floor are piles of garbage and discarded items, "
         "while the rest of the tent's living space seems to be a picture "
        "of organization. The light from outside gives this tent's "
        "interior a slightly brownish tint.");
  SetItems( ([
     ({ "pile", "piles" }) : "These piles are full of unwanted items.",
     ({ "item", "items" }) : "These discarded tools are just lying around, "
                             "and anything could be found with a good "
                            "search.",
     ]) );
 }

varargs void reset(int count) {
   room::reset();
  BeenDone =0;
  }
string SearchMe() {
  if (BeenDone) {
     message("other_action",
         this_player()->GetCapName() + " searches about the room.",
            this_object(), this_player() );
      return "It seems that a search has already been conducted here.";
         }
    new(STD_WEAPON + "dented_sword")->eventMove(this_object());
   message("other_action",
       this_player()->GetCapName() + " search around the room.",
         this_object(), this_player() );
  BeenDone = 1;
  return "You find a sword!";
   }
