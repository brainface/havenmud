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
  SetShort("inside the cave wall");
  SetLong(
    "Inside the cave wall, this hole looks quite homely. There are ancient, "
    "faded tapestries on the walls, one of which depicting a grand castle. "
    "In the middle of the cavern, there is a solitary wooden chair, lined "
    "with tattered purple velvet. A hole in the western wall leads back to the "
    "cave."
  );
  SetItems( ([
  ({ "cave" }) : (: GetLong :),
  ({ "hole" }) : "The hole looks big enough to fit through.",
  ({ "wall" }) : "There appears to be a small hole in the western wall, "
    "leading to another part of the caves.",
  ({ "tapestries", "castle" }) : "The tapestries are all faded and worn, "
    "though the image of a grand castle is still visible on one of them.",
  ({ "chair" }) : "The wooden chair sits alone in the center of the area. It "
    "is lined with purple velvet, which has become faded and tattered over "
    "time.",  
  ]) );
  SetItemAdjectives( ([    
    "hole" : ({ "small" }),
    "wall" : ({ "western" }),
    "tapestries" : ({ "ancient", "faded", "worn" }),
    "chair" : ({ "wooden", "solitary" }),
  ]) );
  SetInventory( ([  
    SEWERS_NPC "undead" : 1,      
  ]) );
  SetListen( ([
    "default" : "The sound of dripping water echos throughout the cave.",
  ]) );
  SetSmell( ([
    "default" : "Mould and damp combine to produce a less pleasant scent.",    
  ]) );
  SetExits( ([  
    "out" : SEWERS_ROOM "sewer13",
  ]) );  
  SetEnters( ([
    "hole" : SEWERS_ROOM "sewer13",
  ]) );
}