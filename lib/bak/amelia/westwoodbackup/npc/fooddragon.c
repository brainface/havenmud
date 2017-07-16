#include <lib.h>
inherit LIB_BARKEEP;
#include "../westwood.h"

static void create()
{
  barkeep::create();
  SetShort("a food selling faerie dragon");
  SetLong("This is a pretty faerie dragon named Docyle.  She is nothing "
    "more than a small lizard with butterfly wings.  Her body is "
    "%^RED%^red %^RESET%^ in hue and she has a tail as long.  Her wings "
    "are a powdery %^BLUE%^blue%^RESET%^ color and she has a wingspan "
    "of about three feet.");
  SetRace("faerie dragon");
  SetGender("female");
  SetKeyName("Docyle, a food selling dragon");
  SetId(({"faerie dragon", "dragon", "docyle"}));
  SetMenuItems( ([
    "green lichen" : W_OBJ + "glichen",
    "red lichen" : W_OBJ + "rlichen",
    "fenfir bark" : W_OBJ + "fbark",
    "fenfir leaf" : W_OBJ + "fleaf",
  ]) );
  SetMorality(2500);
  SetInvis(1);
}
