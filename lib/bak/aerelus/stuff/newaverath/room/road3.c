// Aerelus
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
    "This paved road leads through the city of Averath. The entire city looks "
    "well maintained, with no litter or disrepair in sight. A small building "
    "to the north appears to be a local store, selling all kinds of goods. "
    "Near the side of the road there is a heavy iron grate which provides "
    "access to the city's sewer system. A small path leads southeast from "
    "here to what appears to be the local market."
  );
  SetItems( ([
    ({ "road", "stone", "stones" }) : "The stones are clean and unbroken.",
    ({ "city", "center", "Averath" }) : (: GetLong :),
    ({ "building", "store" }) : "This small building appears to be a store.",
    ({ "goods" }) : "There are all kinds of goods for sale inside the store.",
    ({ "grate" }) : "The heavy iron grate appears to have been left open by "
      "a careless worker. It looks big enough to enter.",
  ]) );
  SetItemAdjectives( ([
    "road" : ({ "paved" }),
    "building" : ({ "small" }),
    "grate" : ({ "heavy", "iron" }),
  ]) );
  SetInventory( ([    
  ]) );
  SetListen( ([
     "default" : "The sounds of city life surround the area.",
  ]) );
  SetSmell( ([
     "default" : "A faint yet unpleasant smell of sewage rises from the grate.",
  ]) );  
  SetExits( ([    
    "west" : AVERATH_ROOM "road2",
    "east" : AVERATH_ROOM "road4",
    "southeast" : AVERATH_ROOM "market",
  ]) );    
  SetEnters( ([
    "store" : AVERATH_ROOM "store",
    "grate" : AVERATH_DIR "../sewers/room/sewer1",
  ]) );
}