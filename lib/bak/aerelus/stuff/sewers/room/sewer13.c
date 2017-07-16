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
    "The cave ends here to the east, though there appears to be a small hole "
    "that someone small enough could slip through. The slime covering the "
    "ground makes it very hard to keep a balance here. Footprints in the "
    "slime seem to stay clear of the hole in the eastern wall for some "
    "reason, though lead west."    
  );
  SetItems( ([
  ({ "cave" }) : (: GetLong :),
  ({ "ground" }) : "The ground is covered in a layer of thick slime. It is "
    "very slippery.",
  ({ "slime" }) : "Covering most of the ground, this slime is very slippery.",  
  ({ "footprints" }) : "The footprints seem to lead in many directions. "
    "Since there are so many, it is hard to determine whether they were made "
    "by only one creature.",
  ({ "hole" }) : "The hole looks big enough to fit through.",
  ({ "wall" }) : "There appears to be a small hole in the eastern wall, "
    "leading to another part of the caves.",  
  ]) );
  SetItemAdjectives( ([    
    "ground" : ({ "rocky", "slippery" }),
    "slime" : ({ "thick" }),
    "hole" : ({ "small" }),
    "wall" : ({ "eastern" }),
  ]) );
  SetInventory( ([   
    SEWERS_NPC "worm" : 1,
    SEWERS_NPC "undeadbandit" : 2,     
  ]) );
  SetListen( ([
    "default" : "The sound of dripping water echos throughout the cave.",
  ]) );
  SetSmell( ([
    "default" : "Mould and damp combine to produce a less pleasant scent.",    
  ]) );
  SetExits( ([  
    "west" : SEWERS_ROOM "sewer12",
  ]) );  
  SetEnters( ([
    "hole" : SEWERS_ROOM "sewer14",
  ]) );
}