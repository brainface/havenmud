#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("underground");
    SetAmbientLight(10);
    SetDomain("FrostMarches");
    SetShort("a small wind torn ravine");
    SetLong("This is a ravine that has been worn down from wind over the "
            "ages.  There is a light dusting of snow with small humanoid "
            "footprints in it. Small tufts of hardy grass attempt to grow "
            "here and there, a bold attempt for the conditions.");
    SetItems( ([
            ({"footprints", "small footprints", "humanoid footprints",
              "snow", "footprint", "small footprint", "light dusting",
              "light dusting of snow"}) :
              "There are small humanoid footprints in about an inch of "
              "dry powdery snow.",
            ({"grass", "tufts of grass", "tufts", "tuft", "hardy grass"}) :
              "This is the standard hardy grass, six to eigth inches long.",
            ({"wind worn ravine", "worn ravine", "ravine", "jagged ravine",
              "ravines"}) :
              "This is a small jagged ravine running south and east "
              "that has been fractured by ice and worn by the wind over "
              "the years.",
            ]) );
    SetSmell( ([
                "default" :
                  "The air is dry and has no appreciable odor.",
                "grass" :
                  "Yep, smells like grass",
             ]) );
    SetListen( ([
                 "default" :
                   "The only thing heard is the wind blowing over the ravine."
             ]) );
    SetExits( ([
       "west" : "/domains/frostmarches/virtual/frostmarchrd/0,35",
       "south" : CAVES_ROOM + "roomo2",
       "east"  : CAVES_ROOM + "roomo3",
             ]) );
}
