#include <lib.h>
#include <daemons.h>
#include <domains.h>
#include <std.h>
#include "../parva.h"
inherit LIB_FERRYCAPTAIN;

void crumpleTicket();

static void create() {
  ::create();
  SetKeyName("charter captain");
  SetLimit(1);
  SetShort("a drunken charter boat captain");
  SetId( ({ "chartercaptain", "captain" }) );
  SetAdjectives( ({ "drunken", "charter", "boat" }) );
  SetRace("human");
  SetClass("sailor");
  SetLevel(160);
  SetGender("male");
  SetLong("The ferry boat captain looks like some more respectable captain of "
    "a finer vessel kicked him off at this port for a litany of sins probably "
    "including mutiny and refusing to put down the grog.");
  SetFirstCommands(({
    "board first ferry",
  }));
  SetAction(5, ({
    "!say Feel like I've been eat'n by ah pack ah wolves, an' shit right off "
      "a cliff.",
    "!say Fuck I'm too sober for this job.",
    "!say Dolphins are the assholes of the sea, you know that?",
    "!say You better godsdamned appreciate what I do.",
    "!say Give me grog, you lilly-livered landlubber!",
    "!yell Come at us, pirates! We're waiting for you!",
    "!yell HEY, KYLIN NAVY! I HEARD YOUR SHIPS ARE EMPTY CASKS, AND YOUR WOMEN "
      "ALL HAVE TUSKS!",
     "!board first ferry",
     // gets him back on his boat if he's on a dock, and his ship wasn't
     // there to begin with.
  }) );
  SetInventory( ([
    PARVA_OBJ "ferrypants" : "wear breeches",
    PARVA_OBJ "bandana" : "wear bandana",
    STD_PIERCE "gaff_hook" : "wield hook",
  ]) );
}

int eventReceiveObject(object ticket) {
  string destination;
  string dock;

  if ( destination = ticket->GetProperty("parva_charter_ticket") ) {
    eventForce("speak So you'd like to go to " + capitalize(destination) +
      ",eh?");
    eventForce("speak You've paid for the service, so let's go. And don't be "
      "expecting me to bring you home if you didn't buy a return ticket.");
    dock = SAILING_D->GetTownDock(destination);
    SetShipWanderPath(dock, dock);
    SetShipWander(1);
    ticket->eventDestruct();
    //call_out( (: crumpleTicket :), 0);
    return 1;
  }
  return ::eventReceiveObject(ticket);
}

void CheckReturnPath() {
  SetWander(0);
  SetAction(10, ({ "!board first ferry" }) );
  SetShipWander(0);
}

