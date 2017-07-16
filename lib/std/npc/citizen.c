#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("citizen");
  SetShort("a citizen");
  SetShort("a common citizen");
  SetId( ({ "citizen" }) );
  SetAdjectives( ({ "common", "averath" }) );
  SetRace("human");
  SetClass("fighter");
  SetLevel(2);
  if(random(10) > 4) {
     SetGender("male");
  }
  else {
     SetGender("female");
  }
  SetLong("This is an average citizen.");
  SetCurrency("imperials", random(2)+1 );
  SetInventory( ([
    STD_FARMING "temperate/potato" : 1,
  ]) );
  SetWander(22);
 }

