#include <lib.h>
#include <domains.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("the HavenWood");
   SetDomain("HavenWood");
   SetShort("a small wooded path");
  SetListen( ([
    "default" : "Small animals can be heard rustling in the brush.",
    ]) );
  SetSmell( ([
    "default" : "The air smells of pine."
    ]) );
  SetLong("This section of the woods seems to follow a path leading "
    "eastward. Although to the west the forest seems unnerving and "
    "eerie, the area to the east looks rather friendly. "
    "The brush seems to be home to many creatures in this part of the "
    "HavenWood, as many rustling branches can be seen as one walks through "
    "the area.");
   SetItems( ([
                ({ "HavenWood path","path" }) :
                   (: GetLong :),
                ({ "HavenWood","woods","havenwood","wood","forest" }) :
                   "The woods split into two sections at this point.  "
                   "To the east are calming, beautiful woods, while to "
                   "the west, the woods are angry and hateful.",
    ({"brush", "bushes" "bush", "branches", "branch"}) : "The brush rustles "
        "with the movement of small creatures.",
           ]) );
   SetItemAdjectives( ([
                         "path" : ({ "havenwood","small","wooden" }),
                         "woods" : ({ "haven","angry","hateful",
                                      "calming","beautiful" }),
                    ]) );
   SetExits( ([
                "west" : HWD_ROOM + "/wood1",
                "east" : HAVENWOOD_TOWNS "havenwood/room/gelf1",
          ]) );
}
