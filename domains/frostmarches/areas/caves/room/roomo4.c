#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("underground");
    SetAmbientLight(10);
    SetDomain("FrostMarches");
    SetShort("a ravine");
    SetLong("This is a wind torn ravine that travels to the west. There "
            "are a few footprints heading west in the snow. The occasional "
            "patch of hardy grass grows here.  There is a small evergreen "
            "growing on the upper edge of the ravine.");
    SetItems( ([
      ({"grass", "tufts", "tuft", "typical grass", "typical hardy grass"
        "hardy grass", "patches", "patch"}) :
        "This is a typical hardy grass, six to eight inches tall.",
      ({"snow", "footprints", "few footprints", "footprint",
        "powder snow", "powdery snow"}) :
        "There are footprints in about an inch of powdered snow heading "
        "to the west.",
      ({"ravine", "wind torn ravine", "ice"}) :
        "This is a ravine that has been worn by the wind and broken by "
        "the ice for a long, long time.",
      ({"evergreen", "small evergreen", "edge", "small pine", "pine", "tree"}) :
        "This is a small pine tree growing out of the side of the ravine, "
        "it is sheltered from the wind in its current location.",
           ]) );
    SetSmell( ([
      "default" :
        "The air is dry and smells relativly clean.",
      ({"evergreen", "small evergreen", "pine tree", "small pine tree"}) :
        "This tree smells like, well, pine.",
            ]) );
    SetListen( ([
      "default" :
        "The only thing heard is the wind blowing over the ravine.",
             ]) );
    SetExits( ([
      "west" : CAVES_ROOM + "roomo3",
            ]) );
    SetObviousExits("west");
}
