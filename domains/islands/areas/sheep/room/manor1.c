#include <lib.h>
#include "../sheep.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the manor house");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong(
   "The main entrance to the manor house is quiet and peaceful, with wood paneling along the wall "
   "that appears to be frequently dusted and polished. To the east the manor opens into what seems "
   "to be a small library or study. Outside the main doors lies the estate itself, with the livestock "
   "seemingly taking care of itself."
   );
  SetListen("The manor house is quiet and peaceful.");
  SetSmell("A faint scent of the polish used on the wood wafts on the air.");
  SetExits( ([
    "out" : SHEEP_ROOM "manor",
    "east": SHEEP_ROOM "manor2",    
  ]) );
}
