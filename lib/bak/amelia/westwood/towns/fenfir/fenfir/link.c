#include <lib.h>
inherit LIB_ROOM;
#include "../fenfir.h"
 
static void create() {
  room::create();
  SetDomain("WestWood");
  SetShort("a small mountain pass");
  SetLong("This small mountain pass is large enough to allow people to "
    "get through and see what is on the other side.  There is a lush "
    "forest of fenfir trees growing north of here and the quiet "
    "of the road to the south.  The mountains here are foreboding "
    "and seem to angle in to close the pass but have failed in doing "
    "so.");
  SetItems( ([
    ({"pass"}) : (:GetLong:),
    ({"tree","trees","fenfir"}) : "The fenfir trees here are large, "
      "standing defiantly amongst the mountains.  The leaves here "
      "are light green and almost as tall as a halfling.",
    ({"mountain","mountains"}) : "The mountains crowd over this road "
      "seemingly trying to close this pass.  They are formed from "
      "a white rock and stand very tall.",
    ({"forest"}) : "The forest is very lush, standing in the midst of "
      "the mountains.  It lies to the north awaiting to be discovered.",
  ]) );
  SetItemAdjectives( ([
    "pass" : ({"small","mountain"}),
    "tree" : ({"fenfir"}),
    "mountain" : ({"foreboding"}),
  ]) );
  SetExits( ([
    "north" : "0,0",
    "south" : "/domains/westwood/virtual/transit/50,0",
  ]) );
  SetClimate("temperate");
  SetSmell( ([
    "default" : "The smell of a lush forest of fenfir drifts about in the air.",
  ]) );
  SetListen( ([
    "default" : "The mountain pass is silent.",
  ]) );
}
