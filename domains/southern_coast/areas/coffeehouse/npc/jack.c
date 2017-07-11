#include <lib.h>
#include <domains.h>
#include "../inns.h"
inherit LIB_BARKEEP;

static void create()
{
  barkeep::create();
  SetKeyName("Jack");
  SetShort("Old Jack, the owner of the Weary Traveler");
  SetId( ({"jack","barkeep","old jack","bartender","owner"}) );
  SetLong("Old Jack has been tending this bar for as long "
          "as anyone cares to remember.  He's aquired countless "
          "wrinkles and a few scars over the years; rumors say "
          "he was once a great warrior.");
  SetRace("human");
  SetGender("male");
  SetClass("fighter");
  SetSkill("melee combat",1,1);
  SetLevel(44);
  SetMenuItems( ([
                  "beer" : I_OBJ + "/wtbeer",
                  "stew" : I_OBJ + "/wtstew",
                  "bread" : I_OBJ + "/wtbread"
              ]) );
  SetLocalCurrency("imperials");
}
