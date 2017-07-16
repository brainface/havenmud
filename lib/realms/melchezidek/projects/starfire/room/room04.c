#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../starfire.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(15);
  SetShort("the western wing in the temple");
  SetLong(
      "The dome of this alcove is painted in what once must have been a gloriously"
      " vibrant mural but now is faded to near indistinguishability. The remains of"
      " complex geometric designs allude to the background while a large skeletal"
      " wing structure is all that remains of the centerpiece of the mural. The walls"
      " of this alcove below the mural are the same yellow sandstone as seen throughout"
      " the temple. One can access the temple proper to the east."
      );
  SetItems( ([
	({ "dome", "mural", "alcove", "designs" }) :
 	  (: GetLong :),
        ({ "wing" }) :
          "Without other context, it's hard to gauge size of the skeletal wing, however,"
          " it does not take up a considerable amount of space in the dome. Before"
          " time had marred it, the detail must have been incredible as sharp lines"
          " denoting minor bones can still be seen even in its current state.",
        ({ "wall", "walls", "stone", "sandstone" }) :
          "The walls are made of yellow sandstone held together with yellow mortar.",
        ({ "temple" }) :
          "One can access the temple proper to the east.",
        ({ "sand", "floor", "pile", "piles" }) :
          "The floor is covered with a thin layer of sand. In some spots it has collected"
          " into small piles making it hard to determine any specifics about the"
          " underlying construction.",
	]) );
  SetItemAdjectives( ([
	"dome" : ({ "vibrant", "painted", "faded", "geometic" }),
        "wing" : ({ "skeletal" }),
        "wall" : ({ "yellow", "sandstone" }),
        "sand" : ({ "thin", "piled" }),
	]) );
  SetExits( ([
      "east"  : SF_ROOM "room03" 
      ]) );
  SetInventory( ([
      SF_OBJ "westlamp" : 1,
    ]) );
  }
