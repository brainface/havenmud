/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: cave.c
// Author: Derek Noble
// Sage: dylanthalus@haven
// Creation Date: Sept 17th, 1998
// Abstract: A dark cave, home of the Jidoor Necromancer Hima
// Revision History: Originaly Created by Zaxan@Haven
//             Sept 18th, 98 Vortex exit changed to not allow guards to 
//                           to enter it and therefore prevent them exiting
//                           the city.
//             November 2n, 1998 - Hima moved out.
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_ROOM;

#define VORTEX "/domains/planes/castles/first/entrance"

int PreEnter(string dir);
void eventDoSomething();
void eventDoSpark();
void eventDoWind();
void eventDoDrip();

static void create() {
   room::create();
   SetTown("Jidoor");
   SetClimate("indoors");
   SetAmbientLight(20);
   SetShort("A damp and dark cave");
   SetLong("This large cave holds a pure sense of undeath. Just "
           "outside of here to the south, a beautiful glade sits, "
           "while to the north, a swirling vortex seems to enter into "
           "the lower planes. Small lanterns hanging from the "
           "ceiling provide a small amount of light, barely enough "
           "to see. Small amounts of water trickle down the walls here,"
           " creating large stalagtites on the ceiling and walls.");
   SetTouch( ([ 
      "default" : "This cave feels damp and uncomfortable.",
   ]) );
   SetItems( ([ 
      ({ "large cave", "cave" }) : 
         (: GetLong :),
      ({ "beautiful glade", "glade" }) : 
         "This beautiful glade sits just outside of this cave. It is a "
         "complete reversal of the atmosphere here.",
      ({ "swirling vortex", "vortex", "gateway" }) : 
         "This swirling vortex gives off a gentle %^MAGENTA%^purple%^RESET%^ "
         "glow. It looks like some sort of gateway.",
      ({ "small lanterns", "lanterns", "lantern" }) : 
         "These small lanterns are providing the minimal amount of "
         "light in the room.",
      ({ "walls", "wall" }) : 
         "A small amount of water is trickling down these walls.",
      ({ "ceiling" }) : 
         "This ceiling is covered with large stalagtites.",
      ({ "small amounts of water", "amounts of water", "amount of water", 
         "water" }) : 
         "This water is slowly trickling down the walls.",
      ({ "large stalagtites", "stalagtites", "stalagtite" }) : 
         "These large stalagtites are hanging from the ceiling and walls. "
         "They have a slight yellow color to them.",
   ]) );
   SetItemAdjectives( ([
      "cave" : ({ "large" }),
      "glade" : ({ "beautiful" }),
      "vortex" : ({ "swirling" }),
      "lanterns" : ({ "small" }),
      "amounts of water" : ({ "small" }),
      "stalagtites" : ({ "large" }),
   ]) );
   AddEnter("vortex", VORTEX, (: PreEnter :));
   SetExits( ([ 
      "out" : JID_ROOM "/glade",
   ]) );
   call_out( (: eventDoSomething :), 300);
}

void eventDoSomething() {
   int x = random(3)+1;

   switch(x) {
      case 1 :
         eventDoSpark();
         break;
      case 2 :
        eventDoWind();
        break;
      case 3 :
        eventDoDrip();
        break;
   }
}

void eventDoSpark() {
   message("system","The large vortex sparks and flickers.",
           this_object());
   call_out( (: eventDoSomething :), 500);
}

void eventDoWind() {
   object array people = ({ });

   people = filter(all_inventory(), (: playerp :));
   message("system","A swift wind comes out of the vortex and "
           "rushes through the cave.",this_object());
   foreach(object person in people) {
      person->eventForce("shiver");
   }
   call_out( (: eventDoSomething :), 500);
}

void eventDoDrip() {
   message("system","A small drop of water falls on your head.",
           this_object());
   call_out( (: eventDoSomething :), 500);
}


int PreEnter(string dir)
{
  if(this_player()->id("jid_protect")) { return 0; }

  else if (this_player()->GetLevel() < 50  && userp(this_player()) && !creatorp(this_player())) {
    send_messages("",
      "The wind coming from the vortex %^BOLD%^WHITE%^surges%^RESET%^ as $agent_name tries to enter.",
      this_player(), 0, environment(this_player()) );
    this_player()->eventPrint("You must be level 50 or more to enter the vortex.");
    return 0;
  }
  else return 1;
}
