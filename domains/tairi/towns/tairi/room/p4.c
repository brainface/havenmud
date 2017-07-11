#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("the entrance to the Grand Palace");
  SetExits( ([
    "out"  : "path10",
    "east" : "p2",
    ]) );
  SetLong("The grand entry chamber to the palace is a large "
          "affair with stylized drawings on the thin papery "
          "walls. The hall itself leads off to the east into "
          "the palace proper, while outside is the path leading "
          "back into the Tai mountain range.");
  SetItems( ([
    ({ "wall", "walls" }) :
       "The walls are covered with traditional Tai art.",
    ({ "art", "scene", "drawings", "drawing" }) : 
    	 "These are simple drawings of martial scenes.",
    ({ "chamber", "entrance", "affair", "entry", "palace" }) :
    	 (: GetLong :),
    ({ "path", "town", "tairi", "outside", "way" }) :
    	 "Outside is the path known as the Way of the Warrior, "
    	 "which leads back to the Tai mountain range.",
    ({ "range", "mountain", "mountains" }) :
    	 "The Tai mountain range is found by following the path "
    	 "outside.",
    ({ "hall" }) :
    	 "The hall of the Grand Palace leads into the palace proper.",
    ({ "proper" }) :
    	 "The palace proper is east down the hall of the Grand Palace.",
    ]) );
  SetItemAdjectives( ([
    "range"   : ({ "tai", "mountain" }),
    "wall"    : ({ "thin", "papery", "paper" }),
    "chamber" : ({ "grand", "entry", "large" }),
    "art"     : ({ "stylized", "simple", "martial" }),
    "proper"  : ({ "palace" }),
    ]) );
  SetInventory( ([
    ]) );
  SetSmell( ([
    "default" : "The scent of fresh flowers fills the palace.",
  ]) );
  SetListen( ([
    "default" : "The sounds of discussion waft in from the east.",
  ]) );
}
