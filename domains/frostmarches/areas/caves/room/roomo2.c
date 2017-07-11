#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate ("underground");
    SetAmbientLight(10);
    SetDomain("FrostMarches");
    SetShort ("the southern end of a ravine");
    SetLong ("This is the south end of a wind worn ravine.  A light "
             "dusting of snow is on the ground, with small humanoid "
             "footprints in it.  Small tufts if hardy grass grow here, "
             "a bold attempt considering the conditions.  The ravine's "
             "walls are exceptionally jagged, and many stones look "
             "as if they are ready to fall.");
    SetItems( ([
       ({"walls", "wall", "jagged", "stone", "stones", "rock", "rocks"}) :
         "There are several rocks that have fallen from the ravines "
         "walls.",
       ({"footprints", "small footprints", "humanoid footprints",
         "ground", "snow", "footprint", "small footprint",
         "dusting", "light dusting", "light dusting of snow"}) :
         "There are small humanoid footprints in about an inch of "
         "dry powdery snow.",
       ({"grass", "hardy grass", "tufts", "tuft"}) :
         "This is the standarf hardy grass about six to eight inches tall.",
       ({"ravine", "wind worn ravine", "ice"}) :
         (: GetLong :),
            ]) );
    SetSmell( ([
       "default" :
           "The air is dry and there is no appreciable odor.",
       "grass"   :
           "Yep, smells like grass.",
       "snow" :
           "The snow has no appreciable odor.",
            ]) );
    SetListen( ([
       "default" :
          "The only thing heard is the wind blowing over the "
          "ravine.",
             ]) );
    SetExits( ([
       "north" : CAVES_ROOM + "roomo1",
            ]) );
    SetObviousExits ("north");
}
