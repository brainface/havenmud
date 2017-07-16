#include <lib.h>
#include <domains.h>
#include "../averath.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("along a road in Averath");
  SetLong(
    "The road continues to the north, south, and east from here. To the west "
    "lies a small tavern. The view to the northeast is blocked by the "
    "shipping warehouse, but no entry can be seen from here. The paving "
    "stones of the road appear to be changed regularly, and the city has a "
    "well maintained look. It is apparent that the Grand Duchy of Averath is "
    "a prosperous land."
  );
  SetItems( ([
    "tavern" : "The tavern is clean and often busy.",
    ({ "road", "stone", "stones" }) : "The stones are clean and unbroken.",
    "warehouse" : "The warehouse is the shipping center of Averath.",
  ]) );
  SetItemAdjectives( ([
    "tavern" : ({ "clean", "small", "busy" }),
    "stone" : ({ "paving", "clean", "unbroken" }),
    "stones" : ({ "paving", "clean", "unbroken" }),
    "warehouse" : ({ "shipping" }),
  ]) );
  SetInventory( ([    
  ]) );
  SetListen( ([
     "default" : "Conversation seems to come from the south.",
  ]) );
  SetSmell( ([
     "default" : "The scent of the sea drifts in from the north.",
  ]) );  
  SetExits( ([
    "north" : AVERATH_ROOM "wharf",
    "south" : AVERATH_ROOM "road2",
  ]) );  
  SetEnters( ([
    "tavern" : AVERATH_ROOM "tavern",
  ]) );
}