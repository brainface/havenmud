#include <lib.h>
#include <domains.h>
#include "../averath.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("along a road in the center of Averath");
  SetLong(
    "The paved road leads through the center of the city here, branching east "
    "west and north to other parts of Averath. Directly to the south lies the "
    "biggest building in the city, the Church of Aetarin. Above the door of "
    "the church is a huge stained-glass window depicting an armoured soldier "
    "with a raised broadsword. Along the paved road to the north lies the "
    "wharf, and eventually the ocean. The city seems very well maintained, "
    "with no sign of litter or disrepair."
  );
  SetItems( ([
    ({ "road", "stone", "stones" }) : "The stones are clean and unbroken.",
    ({ "city", "center", "Averath" }) : (: GetLong :),
    ({ "church", "building", "door" }) : "The Church of Aetarin is a grand "
    	"structure. By far the biggest building in the city, it is looked upon "
    	"with pride by the citizens of Averath. There is a large stained-glass "
    	"window above the door.",
    ({ "window" }) : "The beautiful stained-glass window above the door of "
    	"the church depicts an armoured soldier with a raised broadsword in "
    	"his hand.",
    ({ "wharf", "ocean" }) : "The wharf lies along the road to the north.",    
  ]) );
  SetItemAdjectives( ([
    "road" : ({ "paved" }),
    "building" : ({ "largest" }),
    "window" : ({ "stained", "glass", "stained-glass" }),
  ]) );
  SetInventory( ([    
  ]) );
  SetListen( ([
     "default" : "The sounds of city life surround the area.",
  ]) );
  SetSmell( ([
     "default" : "The scent of the sea drifts in from the north.",
  ]) );  
  SetExits( ([
    "north" : AVERATH_ROOM "road1",
    "west" : AVERATH_ROOM "road5",
    "east" : AVERATH_ROOM "road3",
  ]) );  
  SetEnters( ([
    "church" : AVERATH_ROOM "church",
  ]) );
}