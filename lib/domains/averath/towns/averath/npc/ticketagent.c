#include <lib.h>
#include <std.h>
#include "../averath.h"
inherit LIB_BARKEEP;

static void create() {
  ::create();
  SetKeyName("Ticket Agent");
  SetShort("Jean the Ticket Agent");
  SetId( ({ "jean", "agent" }) );
  SetGender("male");
  SetAdjectives( ({ "ticket" }) );
  SetRace("human");
  SetClass("merchant");
  SetLevel(1);
  SetMorality(15);
  SetLong("Jean the Ticket Agent has travelled over most of the "
          "known world.  He offers discount tickets to most of the "
          "exotic locations around the seas. Be sure to buy a return "
          "ticket!");
  SetMenuItems( ([
    "tairi ticket"   : AVERATH_OBJ "ticket_tairi",
    "haven ticket"   : AVERATH_OBJ "ticket_haven",
    "averath ticket" : AVERATH_OBJ "ticket_averath",
    "parva ticket"   : AVERATH_OBJ "ticket_parva",
    ]) );
  SetLocalCurrency("ducats");
  SetLimit(1);
}
