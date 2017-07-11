#include <lib.h>
#include <std.h>
#include "../parva.h"
inherit LIB_BARKEEP;

static void create() {
  ::create();
  SetKeyName("Ticket Agent");
  SetShort("Juan the Ticket Agent");
  SetId( ({ "juan", "agent" }) );
  SetGender("male");
  SetAdjectives( ({ "ticket" }) );
  SetRace("human");
  SetClass("merchant");
  SetLevel(1);
  SetMorality(15);
  SetLong("Juan the Ticket Agent has travelled over most of the "
          "known world.  He offers discount tickets to most of the "
          "exotic locations around the seas. Be sure to buy a return "
          "ticket!");
  SetMenuItems( ([
    "tairi ticket"   : PARVA_OBJ "ticket_tairi",
    "lisht ticket"   : PARVA_OBJ "ticket_lisht",
    "averath ticket" : PARVA_OBJ "ticket_averath",
    "parva ticket"   : PARVA_OBJ "ticket_parva",
    ]) );
  SetLocalCurrency("oros");
  SetLimit(1);
}
