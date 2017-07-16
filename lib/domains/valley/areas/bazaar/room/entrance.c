/* This is the first room of the Kailie Bazaar */
#include <lib.h>
#include "../bazaar.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("the Kailie Bazaar");
  SetLong("This is the entrance to a colorful carnival. " 
    "There are various discarded items littered along the "
     "sides of the road. To the west is a ticket booth "
     "and back to the east is the Jidoor bank. "
    "The sounds of laughter drift in from the bazaar.");
  SetExits( ([
    "west" : BAZAAR_ROOM "booth",
     "east" : "/domains/valley/towns/jidoor/room/road7",
  ]) );
  SetItems( ([
   ({ "discarded items", "items" }) : "Ticket stubs and half-eaten pieces of food are scattered along "
     "the sides of the road.",
   ({ "meat" }) : "It has already been chewed on.",
   ({ "bank" }) : "This stately building houses the Jidoor bank.",
   ({ "stubs" }) : "Halves of tickets are laying here.",
   ({ "food" }) : "Some partially eaten pieces of meat are tossed on the sides of the road.",
   ({ "booth" }): "The ticket booth is visible to the west.",
   ({ "road" }) : "The dirt road is littered with ticket stubs and discarded food.",
  ]) );
  SetItemAdjectives( ([
     "item" : ({ "various", "discarded" }),
     "bank" : ({ "jidoor" }),
   "meat" : ({ "partially", "eaten", "pieces of" }),
   "food" : ({ "pieces of", "half", "eaten" }),
   "stubs" : ({ "ticket" }),
     "booth" : ({ "ticket" }),
  ]) );
  SetSmell( ([
     "default" : "There is a smell of carnival food here."
  ]) );
  SetListen( ([
     "default" : "Laughter can be heard coming from the bazaar."
  ]) );
}


/* Approved by Duuktsaryth on Tue Nov 24 00:23:11 1998. */
