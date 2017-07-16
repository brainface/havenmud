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
    "The ground here is covered by a thick slime, making it difficult "
    "to maintain a solid foothold. Fallen rocks lie scattered throughout, "
    "giving the impression that too much movement here may prove fatal. "
    "Footprints in the slime lead in many directions, suggesting that there "
    "is something living down here. The cave extends south, though grows "
    "narrower to the north."
  );
  SetItems( ([
  ({ "cave" }) : (: GetLong :),
  ({ "ground" }) : "The ground is covered in a layer of thick slime. It is "
    "very slippery.",
  ({ "slime" }) : "Covering most of the ground, this slime is very slippery.",
  ({ "rocks" }) : "These rocks must have fallen from the the roof of the "
    "cave. They are scattered throughout.",
  ({ "footprints" }) : "The footprints seem to lead in many directions. "
    "Since there are so many, it is hard to determine whether they were made "
    "by only one creature.",
  ]) );
  SetItemAdjectives( ([    
    "roof" : ({ "jagged" }),
    "ground" : ({ "rocky", "slippery" }),
    "slime" : ({ "thick" }),
    "rocks" : ({ "fallen" }),
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
    "south" : SEWERS_ROOM "sewer12",    
    "north" : SEWERS_ROOM "sewer10",
  ]) );  
}