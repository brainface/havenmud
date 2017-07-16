#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
	::create();
  SetShort("in front of the Sanctum Colosseum");
  SetLong("SOUTH -> Colosseum");
	SetExits( ([
          "north" : ROME_ROOM "rd08",
	  ]) );
  SetLong("The Sanctum Colosseum rises from the ground as a challenge to "
          "the sky. It is a stone monster which quite simply dominates "
          "the surrounding area. To the north lies the Via Circuses, "
          "a road which leads back into the main centers of town. "
          "The shadow of the Colosseum gives this section of road "
          "a slight chill.");
	SetItems( ([
	  "road" : "The road is made of small to medium sized pieces of stone. "
	           "It continues to the east and west.",
    ({ "stone", "stones" }) : "The stones are normal, but well smoothed, "
             "pieces of rock layed out for ease of travel.",
    ({ "colosseum" }) : "The Colosseum of Sanctum is a monstrous affair "
        "of stone.  Though no games have been fought there in some time, "
        "it is still the greatest center of physical training in the Empire.",
    ]) );
  SetItemAdjectives( ([
    "stone" : ({ "piece", "of", "pieces" }),
    "colosseum" : ({ "sanctum" }),
    ]) );
  SetEnters( ([
    "colosseum" : ROME_ROOM "colosseum",
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
