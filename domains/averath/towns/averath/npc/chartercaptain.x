
#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();
  SetKeyName("charter captain");
  SetLimit(1);
  SetShort("a charter boat captain");
  SetId( ({ "chartercaptain", "captain" }) );
  SetAdjectives( ({ "charter", "boat" }) );
  SetRace("human");
  SetBaseLanguage("Avera");
  SetClass("sailor");
  SetLevel(45);
  SetGender("male");
  SetLong("The ferry boat captain looks perfectly bored in his work.  So bored that "
          "sympathy for him comes fast and hard to anyone who views his plight.");
  SetFirstCommands("board ferry");
}

int eventReceiveObject(object ticket) {
  string destination;
  string dock;
  if (destination = ticket->GetProperty("averath_charter_ticket")) {
    eventForce("speak So you'd like to go to " + capitalize(destination) + ", eh?");
    eventForce("speak You've paid for the service, so let's go. And don't be expecting me to "
               "bring you home if you didn't buy a return ticket."
               );
    dock = SAILING_D->GetTownDock(destination);
    SetShipWanderPath(dock, dock);
    SetShipWander(1); 
    ticket->eventDestruct();
    return 1;
  }
  return ::eventReceiveObject(ticket);
}

void CheckReturnPath() {
  SetWander(0);
  SetShipWander(0);
}
