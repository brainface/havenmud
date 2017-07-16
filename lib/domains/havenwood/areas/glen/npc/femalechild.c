/* This file was updated on 01/15/99
* by Haun for mud-upkeep purposes.
*/
#include <lib.h>
#include "path.h"
inherit LIB_SENTIENT;
static void create() {
  sentient::create();
  SetKeyName("female gelfling child");
  SetShort("a female gelfling child");
  SetLong("The female gelfling child stares up playfully.  "
          "She doesn't mind playing with the male children, "
          "but wishes there were nicer people to play with. ");
  SetId( ({ "gelfling", "child", "female" }) );
  SetAdjectives( ({ "female", "gelfling", "child" }) );
  
  SetRace("gelfling");
  SetClass("fighter");
  SetMorality(random(150)+300);
  SetLevel(random(2)+2);
  SetGender("female");
  
  SetCurrency("imperials",random(3)+4);
  SetInventory( ([
                   GLEN + "/wpn/shortstick" : "wield stick",
              ]) );
  SetAction(25, ({ "The child swings her stick absent-mindedly.",
                   "The female child asks you if you'd like to play." }));
}


/* Approved by Duuktsaryth on Wed Sep 24 13:10:57 1997. */
