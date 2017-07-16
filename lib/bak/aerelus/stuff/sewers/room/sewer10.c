// Averath Sewers
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../sewers.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(10);
  SetClimate("indoors");
  SetShort("in a cave below the sewers");
  SetLong(
    "Far below the city, this cave rarely sees visitors from the ouside "
    "world. It is very dark and damp, with water dripping from the roof of "
    "the cave, slowly eroding the rocky ground. The cave widens to the south, "
    "while it seems possible to climb through an iron grate above. Scattered "
    "throughout the cave are the skeletal remains of small rodents who were "
    "unfortunate enough to find their way down here."
  );
  SetItems( ([
  ({ "cave" }) : (: GetLong :),
  ({ "city", "world" }) : "The cave is so far underground that any signs of "
    "the outside world are not visible from here.",
  ({ "roof" }) : "Water slowly drips from the jagged roof of the cave.",
  ({ "ground" }) : "The dripping water has eroded the ground in places, "
    "leaving small dents in the surface.",
  ({ "grate" }) : "There is an iron gate above, leading back to the sewer "
    "system.",
  ({ "remains", "rodents" }) : "These skeletal remains were once rats who "
    "were unfortunate enough to find their way down here. Some of the bones "
    "look like they have been chewed.",  
  ]) );
  SetItemAdjectives( ([
    "world" : ({ "outside" }),
    "roof" : ({ "jagged" }),
    "ground" : ({ "rocky" }),
    "grate" : ({ "iron" }),
    "remains" : ({ "skeletal" }),
    "rodents" : ({ "small" }),    
  ]) );
  SetInventory( ([        
  ]) );
  SetListen( ([
    "default" : "The sound of dripping water echos throughout the cave.",
  ]) );
  SetSmell( ([
    "default" : "Mould and damp combine to produce a less pleasant scent.",    
  ]) );
  SetExits( ([  
    "south" : SEWERS_ROOM "sewer11",    
  ]) );
  SetEnters( ([
    "grate" : SEWERS_ROOM "sewer9",
  ]) );
}