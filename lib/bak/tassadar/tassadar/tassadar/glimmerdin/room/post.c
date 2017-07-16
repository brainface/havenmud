#include <lib.h>
#include <averath.h>
#include "../glim.h"
inherit LIB_POST_OFFICE;


static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(30);
  SetTown("Glimmerdin");
  SetShort("Post Office");
  SetLong("Dark wooden beams house a small courier operation in Glimmerdin. "
          "Long benches line either side of the room and behind a tall "
          "counter, a wooden sign dominates the back wall.  There is a "
          "fireplace in the corner, but no fire roars in it at the "
          "moment.  Upon the wooden counter, a leatherbound "
          "ledger records the traffic of this office.");
  SetItems( ([
       ({"post office"}) : (: GetLong :),
       ({"benches","bench"}) : "The benches look well-crafted but somewhat uncomfortable.",
       ({"tall counter", "counter"}) : "Upon the bare counter sits a leger and some ink.",
       ({"glass jar", "jar", "black ink","ink"}) :  "Black ink has so stained the glass jar, "
            "it is impossible to discern if there is any inside.",
       ({"leatherbound ledger", "ledger"}) : "The thick ledger has fine, ivory pages.  Delicate "
            "handwriting records the sender, recipient and courier of each delivery.",
       ({"fireplace" }) : "Cinders lie in the foot of the fireplace.",
    ]) );
  SetSmell( ([
        "default" : "The earthy smell of wood permeates the room."
    ]) );
  SetExits( ([
      "out" : G_ROOM "office",
    ]) );
  SetInventory( ([
      AVERATH_OBJ + "sign.c" : 1,
    ]) );

}
