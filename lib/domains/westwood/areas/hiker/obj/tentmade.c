#include <lib.h>
#include <damage_types.h>
inherit LIB_SHIP;
#include "../hiker.h"

void desttent();
void aboutcollapse();
int SetCountDown(int countDown);
int GetCountDown();
int tentlast = 190+random(100);

static void create() {
   vehicle::create();
   SetKeyName("tent");
   SetShort("a grey-brown tent");
   SetId( ({ "tent" }) );
   SetAdjectives( ({ "grey","brown","grey-brown","made" }) );
   SetLong("This grey-brown tent is all ready for people to step inside "
           "and rest.  The material looks durable, even though it is a "
           "textile, and the atmosphere is calm.");
   SetPreventGet("The tent is too large and unwieldly for such an "
                 "action.");
   set_heart_beat(2);
   SetProperty("no attack",1);
   SetProperty("no bump",1);
   SetProperty("no steal",1);
}

void
 heart_beat() {
   tentlast--;
   if(tentlast == 10) {
      aboutcollapse();
   }
   if(!(tentlast)) {
      desttent();
   }
}

void aboutcollapse() {
   message("tent message","The tent wobbles about unsteadily.",
      ({ this_object(),environment(this_object()) }));
   return;
}

void desttent() {
   object blahtent;
   foreach(object blah in all_inventory(this_object())) {
      blah->eventmove(environment(this_object()));
      blah->eventReceiveDamage(0, BLUNT, 25+random(50));
   }
   message("tent message","The tent has collapsed!",({ this_object(),
      environment(this_object()) }));
   environment(this_object())->RemoveProperty("hiker_tent_here");

   blahtent = new(H_OBJ + "/tentbad");
   blahtent->eventMove(environment(this_object()));
   eventDestruct();
   return;
}
int SetCountDown(int countDown) {
   return (tentlast = countDown);
}
 
int GetCountDown() {
   return tentlast;
}


void init() {
   ::init();
   add_action("quit","quit");
}

int quit() {
   message("blah","Don't quit here.",this_player());
   return 1;
}
