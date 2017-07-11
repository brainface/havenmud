#include <lib.h>
#include "../rome.h"
#include <domains.h>
inherit LIB_ROOM;
int Wander();

static void create() {
	::create();
  SetShort("the Eastern Entrance to Sanctum");
	SetExits( ([
          "west" : ROME_ROOM "rd04",
          "north": "/domains/peninsula/areas/grove/room/entrance",
	  ]) );
  AddExit("east", INNERSEA_VIRTUAL "ocean/-26,-7", (: Wander :) );
  SetLong(
    "The road ends here at the eastern edge of town. Paved "
    "stone leads back to the west, into the heart of the city. "
    "To the east the road ends abruptly and only the vastness of "
    "the Blood Sea is visible. To the north lies a small wooded "
    "grove."
  );
	SetItems( ([
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the west.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
    ({"ocean", "sea"}) : "Immediately east of here the road ends and the "
    "Blood Sea begins.",
    "wall" : "The wall is large and clearly impassable.",
    ]) );
  SetItemAdjectives( ([
    "stone" : ({ "piece", "of", "pieces" }),
    "ocean" : ({"Blood", "blood", "large", "vast","east"}),
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

int Wander() {
  if (this_player()->id("wander")) return 0;
  return 1;
}
