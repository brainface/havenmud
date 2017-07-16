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
    "The buildings in this part of the city are very well decorated. Each of "
    "them have been painted white, with dark wooden support beams contrasting "
    "the brightness. The owners of the buildings have spared no expense "
    "on decoration, with window boxes filled with vibrant flowers at every "
    "window. There are two official-looking buildings here which aren't so "
    "well decorated, the local post office and what appears to be a bank. The "
    "paved road leads east and west through the city."
  );
  SetItems( ([
   ({ "road", "stone", "stones" }) : "The stones are clean and unbroken.",
   ({ "city" }) : (: GetLong :),
   ({ "buildings", "building" }) : "The buildings are all very well "
     "decorated, with the exception of the post office and bank, which look "
     "rather official.",
   ({ "beams" }) : "The dark wooden beams, which support the buildings, "
     "also add to their visual appeal.",
   ({ "decoration", "boxes", "flowers", "window", "windows" }) : "There are "
     "window boxes at each window containing beautiful flowers, native to "
     "the island.",
   ({ "office" }) : "The post office looks very official-looking, and can "
     "can be entered from here.",
   ({ "bank" }) : "The First Averath Bank, an official-looking building, can "
   	"be entered from here.",
  ]) );
  SetItemAdjectives( ([
    "road" : ({ "paved" }),
    "building" : ({ "official-looking" }),
    "buildings" : ({ "official-looking" }),
    "beams" : ({ "dark", "wooden", "support" }),
    "boxes" : ({ "window" }),
    "flowers" : ({ "vibrant", "beautiful" }),
    "office" : ({ "post" }),
  ]) );
  SetInventory( ([
  ]) );
  SetListen( ([
     "default" : "This part of the city is pleasantly quiet.",
  ]) );
  SetSmell( ([
     "flowers" : "The flowers smell wonderful!",
     "default" : "The smell of the flowers is almost overpowering.",
  ]) );  
  SetExits( ([    
    "west" : AVERATH_ROOM "road6",
    "east" : AVERATH_ROOM "road2",
  ]) );  
  SetEnters( ([
    "bank" : AVERATH_ROOM "bank",
    "office" : AVERATH_ROOM "office",
  ]) );
}