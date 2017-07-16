#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;
int GuardTest(string);

static void create() {
  room::create();
  SetNightLight(10);
  SetShort("a clearing in the camp");
  SetExits( ([
    "north" : CAMP_ROOM + "/cl5",
    ]) );
  SetItems( ([
      "tent" : "This is a large tent of regal proportions.",
      ]) );
  AddEnter("tent",CAMP_TENT + "/leader", (: GuardTest :) );
  SetDayLong("The daylight shines on the clearing here, making this \n" 
             "area seem almost regal.  In the center of the clearing \n"
             "is a large tent which is larger than any other tent in \n"
             "the camp so far.");
  SetNightLong("The stars light this clearing with ease.  In the middle \n"
               "of the clearing is a large tent which is more regal than \n"
               "any of the others so far.  The path leads back off to the \n"
               "north from here, going back into the camp.");
  SetInventory( ([
     CAMP_NPC + "/bandit" : 2,
     CAMP_NPC + "/dog" : 2,
     ]) );
  }

int GuardTest(string dir) {
   object guard;
   object who;
   who = this_player();
  guard = present("bandit", this_object());
  if (this_player()->id("bandit")) return 1;
  if ( (guard) && (living(guard)) ) {
     guard->eventForce("speak You can't just go see the leader at your whim!");
    guard->eventForce("grin "+who->GetKeyName());
    return 0;
   }
   return 1;
  }
