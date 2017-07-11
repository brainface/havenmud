#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("along the Via Circuses");
	SetExits( ([
          "east" : ROME_ROOM "rd07",
          "west" : ROME_ROOM "rd09",
          "south" : ROME_ROOM "rd11",
	  ]) );
  SetLong("The Via Circuses continues to the east and west. "
          "Off to the south is the Colosseum of Sanctum, a massive "
          "building where, years ago, gladiators fought and died "
          "for the amusement of the citizens of Sanctum. Though that "
          "practice has been banned, the Colosseum still serves as "
          "a training ground for all forms of physical combat. "
          "The Colosseum rises into the sky, a massive multi-level "
          "structure which is a marvel of Imperial building and "
          "engineering talents.");
	SetItems( ([
    ({ "colosseum" }) : "The colosseum is a huge, multi level structure "
                "that towers into the sky.  Its oval shape is perfect for "
                "use as an arena, which it formerly was.",
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the east and west.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
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
}	           
