#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Circuses");
	SetExits( ([
          "east" : ROME_ROOM "rd09",
	  ]) );
  SetLong("The Via Circuses dead-ends here, heading only back "
          "off to the east. Off to the southeast is the Sanctum "
          "Colosseum, the entrace of which lies to the east. "
          "The stones of the road are less firmly entrenched here, "
          "as if this section of town is used less frequently. "
          "There is a small building marked with a heart lying "
          "to the north.");
	SetItems( ([
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the east and west.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
     ({ "building", "hospice" }) : "This building is the local hospice.",
    ]) );
  SetItemAdjectives( ([
    "stone" : ({ "piece", "of", "pieces" }),
    ]) );
  SetInventory( ([
    ]) );
  SetSmell( ([
    "default" : "The smells of urban life taint the air.",
    ]) );
  SetListen( ([
    "default" : "The sounds of the city are alive and vibrant.",
    ]) );
  SetEnters( ([
    "building" : ROME_ROOM "hospice",
    ]) );
}	           
