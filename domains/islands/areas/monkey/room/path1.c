// Island
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../island.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("on an overgrown path");
  SetLong(
    "This overgrown path seems to have gone unused in many years. Covered by "
    "vines, the path certainly isn't easy to walk on. It appears to lead "
    "northeast, to the rock formations that surround most of the island, and "
    "south to more jungle. A trickling stream intersects the path, though "
    "there are a few stepping stones to allow crossing without getting wet."    
  );
  SetItems( ([
  ({ "jungle" }) : (: GetLong :),
  ({ "path", "vines" }) :
    "The path is overgrown with vines, making passage rather tricky.",
  ({ "formations" }) : 
    "The rock formations surround most of the island. The path here seems to "
    "lead to them.",
  ({ "stream" }) : 
    "The stream water looks fresh and inviting. There are some stepping "
    "stones in it, allowing people to cross.",
  ({ "stones" }) : 
    "These stepping stones have haven been eroded by the stream, making the "
    "tops of them flat and easy to step on.",
  ]) );
  SetItemAdjectives( ([
    "formations" : ({ "rock" }),
    "stones" : ({ "stepping" }),
    "stream" : ({ "trickling" }),
    "path" : ({ "overgrown", "unused" }),   
  ]) );  
  SetListen( ([
    "default" : "The stream makes a trickling noise as it flows.",
  ]) );
  SetSmell( ([
    "default" : "The air here is very warm and humid.",
  ]) );
  SetExits( ([
    "northeast" : ISLAND_ROOM "path2",
    "south" : ISLAND_ROOM "island1",    
  ]) );  
}
