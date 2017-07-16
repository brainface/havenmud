
#include <lib.h>
#include "../master.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetRadiantLight(5);
  SetObviousExits("south");
  SetShort("in a room");
  SetLong(
          "You are in a void, luckily someone hung a "
		  "picture of Duuk on the wall.");
  SetExits( ([
//            "south"       : EXDIR "room01",
//            "north"       : EXDIR "room02",
           ]) );
  SetSmell( ([
            "default" : "There is no smell.",
           ]) );
  SetListen( ([
            "default" : "Silence."
           ]) );
  SetItems( ([
    ({ "ground", "floor" }) : ".",
	"": ".",
	"": ".",
	"": ".",
	"": ".",
	"": ".",
	]) );
   SetItemAdjectives( ([
    "" : ({ "","" }),
    "" : ({ "","" }),
    "" : ({ "","" }),
    "" : ({ "","" }),
    "" : ({ "","" }),
    "" : ({ "","" }),
  ]) ); 
}