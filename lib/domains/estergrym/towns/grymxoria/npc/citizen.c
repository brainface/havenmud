#include <lib.h>
#include "../grymxoria.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("citizen");
  SetShort("a Grymxoria citizen");
  SetId( ({ "citizen", "nosferatu", "grym_npc" }) );
  SetAdjectives( ({ "grymxoria" }) );
  SetLong("This is an average Grymxoria citizen.");
  SetRace("nosferatu");
  SetMorality(-1000);
  SetClass("rogue");
  SetLevel(random(6)+10);
  if(random(10) > 4) {
     SetGender("male");
  }
  else {
     SetGender("female");
  }
  SetCurrency("bloodgems", random(600)+500 );
  SetWander(22);
 }

