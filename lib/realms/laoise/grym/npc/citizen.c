#include <lib.h>
#include "../grymxoria.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("citizen");
  SetShort("A Grymxoria citizen");
  SetId( ({ "grymxoria citizen", "citizen", "nosferatu" }) );
  SetLong("This is an average Grymxoria citizen.");
  SetRace("nosferatu");
  if(random(10) > 4) {
     SetGender("male");
  }
  else {
     SetGender("female");
  }
  SetClass("valkyr");
  SetLevel(random(6)+5);
  SetCurrency("bloodgems", random(600)+500 );
  SetWander(22);
}

