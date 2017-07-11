/* This file was updated on 01/15/99
* by Haun for mud-upkeep purposes.
*/
#include <lib.h>
#include "path.h"
inherit LIB_SENTIENT;
static void create() {
  sentient::create();
  SetKeyName("lumberjack");
  SetShort("a gelfling lumberjack");
  SetLong("This lumberjack is rather large for a gelfling and has "
          "a torso nearly as large as the trunks of the trees he "
          "brings crashing to the earth. "
          );
  SetId( ({ "gelfling","lumberjack","gelfling lumberjack"}) );
  
  SetRace("gelfling");
  SetClass("fighter");
  SetMorality(random(120)+350);
  SetLevel(random(4)+18);
  SetGender("male");
 
  SetCurrency("imperials",random(100)+80);
  SetInventory( ([
                   GLEN + "/wpn/woodaxe" : "wield axe",
                   GLEN + "/arm/workboots" : "wear boots"
              ]) );
  SetAction(10, ({ "The lumberjack takes a mighty chop at the "
                   "base of a tree.",
                   "!speak Tiiiiimmmmmmmmmbeeeeeeeeeerrrrr!"}));
}
