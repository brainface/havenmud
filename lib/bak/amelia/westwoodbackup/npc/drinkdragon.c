#include <lib.h>
inherit LIB_BARKEEP;
#include "../westwood.h"

static void create()
{
  barkeep::create();
  SetShort("a drink selling faerie dragon");
  SetLong("This is a pretty faerie dragon named Zurny.  She is nothing "
    "more than a small lizard with butterfly wings.  Her body is "
    "%^BLUE%^blue%^RESET%^ in hue and about a foot long with a tail "
    "as long as her body.  Her wings are a powdery "
    "%^YELLOW%^yellow%^RESET%^ color and she has a wingspan of about "
    "three feet.");
  SetRace("faerie dragon");
  SetGender("female");
  SetKeyName("Zurny, the drink selling faerie dragon");
  SetId(({"faerie dragon", "dragon", "zurny"}));
  SetMenuItems( ([
    "honey suckle" : W_OBJ + "hsuckle",
    "leaf dew" : W_OBJ + "ldew",
    "fenfir sap" : W_OBJ + "fsap",
  ]) );
  SetMorality(2500);
  SetInvis(1);
}
