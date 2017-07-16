// Modified by Dahaka
// Aug 2004

#include <lib.h>
#include <vendor_types.h>
#include "../drazh.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("rhiak");
  SetId( ({"rhiak","barkeep","skaven"}) );
  SetShort("Rhiak the barkeep");
  SetLong(
    "Rhiak is a smaller than average skaven with brown fur. His small "
    "frame is is wiry but strong, which wears many scars. Rhiak has a "
    "small glint in his eyes that keep his patron's honest."
      );
  SetRace("skaven");
  SetGender("male");
  SetClass("merchant");
  SetLevel(37);
  SetMorality(-1000);
  SetLocalCurrency("roni");
  SetCurrency("roni", 10 + random(400));
  SetMenuItems( ([
    "rot gut"  :  V_OBJ + "rot_gut",
    "gruel"    :  V_OBJ + "gruel",
    "dark ale" :  V_OBJ + "dark_ale",
    ]) );
}