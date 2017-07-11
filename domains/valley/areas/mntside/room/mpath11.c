/* Create by Aramuuk. 1998 */                                                   
#include <lib.h>                                                                
#include <std.h>                                                                
#include "../path.h"                                                            
inherit LIB_ROOM;                                                               

static void create() {                                                          
    room::create();                                                             
    SetShort("the mountain path");                                              
    SetLong("This is path up the side of a mountain. The terrain around "+      
      "the path is rugged but will support some of the hardier plant life, "+
      "however, the ground here is quite barren of any plants. To the "+
      "north are five somewhat small huts clustered together. ");                                          
    SetItems( ([                                                                
	({ "path" }) : "A worn path on the edge of the mountain.",              
	({ "mountain" }) : "One of they mountains in the Crystal Reaches "+     
	"range. The snowcap is far above you.",                                 
	({ "structures","huts","small structures","structure","small structure",
	  "hut" }) : "There's a group of five stone huts just down "+
	"the path.",                                                                        
      ]) );                                                                     
    SetExits( ([                                                                
	"northwest" : RMS+"mpath10", 
	"north" : RMS+"center",                                            
	"east" : RMS+"mpath12",                                             
      ]) );                                                                     
    SetSmell( ([
	"default" : "The smoke coming from the huts scents the wind.",
      ]) );
  SetDomain("Valley");
    SetInventory( ([
        NPC+"guards" : random(2)+2,
      ]) );
    SetClimate("arid");   
}
