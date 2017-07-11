/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: evoker.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Oct 23rd, 1998
// Abstract: This is the evoker section of the tower of the Great Library 
//           of Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

int BeenDone;
void DoSearch();
void eventStartChant();    /* Originally Coded by Zaxan@Haven */
void eventDarkenRoom();    /* Originally Coded by Zaxan@Haven */
void eventLightenRoom();   /* Originally Coded by Zaxan@Haven */
string GetBallDesc();      /* Originally Coded by Zaxan@Haven */

static void create() {
   room::create();
   SetAmbientLight(60);
   SetClimate("indoors");
   SetShort("the Evoker's Section of the Great Library of Jidoor");
   SetLong("This section of the tower is obviously for the study of the art "
           "of evokation. Paintings line the walls to decorate the area "
           "and a large marble staircase leads up into the tower and down "
           "to the main floor of the library. Tables, chairs and "
           "couches are placed about randomly for people to sit and study "
           "books lining various shelves in the room.");
   SetItems( ([
      ({ "building", "library", "library of jidoor","section","tower"}) : 
         (: GetLong :),
      ({"paintings","painting"}) : "One could spend hours here enjoying "
         "wonderous paintings of the library.  Several are abstract "
         "paintings and others depict landscapes, and still others are "
         "portraits of people.",
      ({"shelves","shelf","shelves of books"}) : "The shelves of this "
          "section match those of the rest of the library and are placed "
          "along the walls. A few added shelves rest in the center of "
          "the room.",
      ({"walls","wall" }) : "The circular walls of the tower are lined "
          "with shelves of books.",
      ({"floor","ceiling" }) : "The floor and ceiling are both made from "
          "a green marble that casts an eerie glow around the room.",
      ({"books","book"}) : "The books lining the shelves are all "
          "concerned with the study of evokation, the most fantastic and "
          "awe inspiring of the magical arts.",
      ({"chairs", "chair","table","tables","couches","couch"}) : "The "
          "various tables, chairs and couches are comfortable looking "
          "and suit the "
          "needs of anyone wishing to research the lore of the various"
          "books on the art of evokation.",
      ({"staircase","stairs"}) : "The staircase is literally huge and "
          "reflects the light in the room casting an erie but pleasant "
          "radiance.  It leads up into the tower as well down into the "
          "library.",
      ({ "floating balls", "balls", "ball" }) : 
         (: GetBallDesc :),
          ]) );
   SetItemAdjectives( ([
      "building" : ({ "beautiful" }),
      "library" : ({"beautiful","great" }),
      "staircase" : ({"large","marble"}),
      "shelves" : ({"various"}),
   ]) );
   SetSearch( (["books" : (: DoSearch :) ]) );
   SetExits( ([ 
      "down" : JID_ROOM "/library/tower",
      "up" : JID_ROOM "/library/enchanter",
   ]) );
  SetInventory( ([ JID_NPC "/warlad" : 1,
                   JID_NPC "/arpal" : 1,
              ]) );
  SetListen( ([ "default" : "The library is virtually noiseless."
           ]) );
  SetSmell( ([ "default" : "The library smells fresh and new, but the "
                  "smell of old books is heavy in the air." ]) );
   call_out( (: eventDarkenRoom :), 500 );
}

void eventDarkenRoom() {
   message("other_action","The floating balls suddenly fall "
           "to the ground and the room becomes dark.",this_object());
   SetAmbientLight(0);
   call_out( (: eventStartChant :), 10);
   return;
}

void eventStartChant() {
   if(present("warlad")) {
      message("other_action","Warlad closes his eyes and begins "
              "%^BLUE%^BOLD%^uttering an incantation%^RESET%^.",this_object());
      call_out( (: eventLightenRoom :), 5);
   }
   return;
}

void eventLightenRoom() {
   if(present("warlad")) {
      message("other_action","Warlad's magic creates many floating "
              "%^YELLOW%^balls of light%^RESET%^.",this_object());
      SetAmbientLight(60);
      call_out( (: eventDarkenRoom() :), 500);
   }
   return;
}

string GetBallDesc() {
   if(GetAmbientLight() == 0) {
      return "There are no balls here.";
   } else {
      return "These small floating balls provide light for the room. "
             "They don't look like very stable objects.";
   }
}

varargs void reset(int count) {
   room::reset();
  BeenDone =0;
  }
void DoSearch() {
  if (BeenDone) {
     message("other_action",
         this_player()->GetCapName() + " searches around.",
            this_object(), this_player() );
      message("blah", "You do not notice anything special.", this_player());
      return;
         }
    new(JID_OBJ + "/scroll1")->eventMove(this_player());
   message("other_action",
       this_player()->GetCapName() + " searches around.",
         this_object(), this_player() );
  BeenDone = 1;
  message("blah", "You find a scroll!", this_player());
   }
