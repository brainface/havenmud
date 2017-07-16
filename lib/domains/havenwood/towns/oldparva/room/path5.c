#include <lib.h>
#include "parva.h"
#include <domains.h>

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetShort("in Parva");
   SetDomain("HavenWood");
   SetLong(
    "This small path runs through Parva. To the north is a "
    "large building with steam rising from its roof. A nice house "
    "is to the south, and the path leads off to the east and west."
  );
   SetItems( ([
    ({ "Parva","parva","town" }) :
    (: GetLong :),
    ({ "dirty path","path","dust","dirt" }) :
    "The path is simple dirt; a good deal "
    "is dry enough to fill the air with "
    "dust.",
    ({"building","bathhouse","wadlows"}) :
    "To the north is a large building with steam rising "
    "from its roof. A sign above the door reads \"Wadlow's "
    "Bathhouse.\"",
    ({ "nice house","house" }) :
    "There is a nice house to the south.  It looks "
    "clean and safe.",
           ]) );
  SetItemAdjectives( ([
    "path" : ({ "dirty","dusty" }),
    "building" : ({"large", "steaming","bathhouse", "wadlow's"}),
    "house" : ({ "nice","safe","clean" }),
                    ]) );
   SetListen( ([
                 "default" : "Waves crash in the distance.",
           ]) );
   SetSmell( ([
                "default" : "The salt smells of the ocean drift through.",
           ]) );
   SetExits( ([
                "east"  : P_ROOM + "/path4",
                "west"  : P_ROOM + "/path6",
          //      "north" : P_ROOM + "/path8",
           ]) );
   SetEnters( ([
                 "house" : P_ROOM + "/healhut",
                 "building" : HAVENWOOD_AREAS "bathhouse/room/entrance",
            ]) );
}
