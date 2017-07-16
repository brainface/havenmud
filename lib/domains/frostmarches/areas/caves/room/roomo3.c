#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create () {
    room::create ();
    SetClimate ("underground");
    SetAmbientLight(10);
    SetDomain("FrostMarches");
    SetShort ("a ravine");
    SetLong("This is a wind torn ravine.  There are "
             "numerous footprints heading south through a little snow. "
             "There are small tufts of grass that are bent over here. "
             "A boulder is found here, apparently fallen from "
              "the upper reaches of the ravine.  There is a crude "
              "snowman sitting in the middle of the ravine.");
    SetItems( ([
      ({"snowman", "crude snowman", "middle"}) :
        "This is a poorly made snowman about three feet in height.",
      ({"footprints", "numerous footprints", "footprint",
        "small footprint", "small footprints"}) :
          "There are lots of small footprints heading south through "
          "about an inch of dry powder snow.",
      ({"snow", "dry powder snow", "dry snow", "powder snow"}) :
        "There is an inch of dry snow here.",
      ({"grass", "small tufts", "small tufts of grass", "tufts",
        "tuft", "bend over grass", "bent over tuft"}) :
          "This grass has been flattened by something. It is the standard "
          "hardy variety.",
      ({"ravine", "worn ravine", "ice"}) :
        "This ravine heads east, west and south. It has been worn by ice "
        "for a long, long time.",
      ({"boulder"}) :
        "The boulder is about two feet across and is covered in snow.",
            ]) );
    SetSmell( ([
      "default" :
         "There is a slight odor coming form the south.",
            ]) );
    SetListen( ([
      "default" :
        "There are some voices coming from the south.",
             ]) );
    SetExits( ([
      "east" : CAVES_ROOM + "roomo4",
      "west" : CAVES_ROOM + "roomo1",
      "south" : CAVES_ROOM + "roomce",
            ]) );
}
