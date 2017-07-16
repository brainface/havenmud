#include <lib.h>
#include "../herm.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("a small hermitage");
  SetLong("This small cottage is the home of a hermit."
          " The walls are devoid of decoration and the"
          " little furniture that there is appears to"
          " have been crafted by an unskilled hand."
          " Despite the rustic appearance, the cottage"
          " is very neat and orderly.");
  SetSmell( ([
          "default" : "A soft spicy odor resides here",
       ]) );
  SetListen( ([
          "default" : "Only ambient noises from outside"
          " penetrate the silence",
        ]) );
  SetExits( ([
           "out" : HERM_ROOM "outside",
           "south" : HERM_ROOM "vault",
        ]) );
}
