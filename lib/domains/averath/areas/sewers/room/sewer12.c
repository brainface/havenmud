// Averath Sewers
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../sewers.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(10);
  SetClimate("underground");
  SetShort("in a cave below the sewers");
  SetLong(
    "The ground here is covered by a thick slime, making it difficult "
    "to maintain a solid foothold. Footprints in the slime lead in many "
    "directions, though the majority seem to head east. There are primitive "
    "carvings on the walls of the cave here, which appear to resemble a basic "
    "language."   
  );
  SetItems( ([
  ({ "cave" }) : (: GetLong :),
  ({ "ground" }) : "The ground is covered in a layer of thick slime. It is "
    "very slippery.",
  ({ "slime" }) : "Covering most of the ground, this slime is very slippery.",  
  ({ "footprints" }) : "The footprints seem to lead in many directions. "
    "Since there are so many, it is hard to determine whether they were made "
    "by only one creature.",
  ({ "carvings" }) : "Though unintelligable, the carvings seem to be written "
    "in a basic, yet unknown, language.",
  ]) );
  SetItemAdjectives( ([    
    "roof" : ({ "jagged" }),
    "ground" : ({ "rocky", "slippery" }),
    "slime" : ({ "thick" }),
    "carvings" : ({ "primitive" }),
  ]) );
  SetInventory( ([    
    SEWERS_NPC "worm" : 2,
    SEWERS_NPC "undeadbandit" : 1,    
  ]) );
  SetListen( ([
    "default" : "The sound of dripping water echos throughout the cave.",
  ]) );
  SetSmell( ([
    "default" : "Mould and damp combine to produce a less pleasant scent.",    
  ]) );
  SetExits( ([  
    "north" : SEWERS_ROOM "sewer11",    
    "east" : SEWERS_ROOM "sewer13",
  ]) );  
}
