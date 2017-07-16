/* Create by Aramuuk. 1998 */                                                   
#include <lib.h>                                                                
#include <std.h>                                                                
#include "../path.h"                                                            
inherit LIB_ROOM;                                                               

static void create() {                                                          
    room::create();                                                             
    SetShort("the mountain path");                                              
    SetLong("This is a path up the side of a mountain. At this point on "+
      "the path the ground is rugged but can support plant life, however, "+
      "the ground is devoid of plant life. A bit further up the path can "+
      "be seen a small cluster of structures.");                                          
    SetItems( ([                                                                
	({ "path" }) : "A worn path on the edge of the mountain.",              
	({ "mountain" }) : "One of they mountains in the Crystal Reaches "+     
	"range. The snowcap is far above you.",                                 
	({ "structures","huts","small structures","structure","small structure",
	  "hut" }) : "There's a small group of stone huts further up "+
	"the path.",                                                                        
      ]) );                                                                     
    SetExits( ([                                                                
	"west" : RMS+"mpath12", 
	"down" : RMS+"mpath14",                                             
      ]) );                   
    SetClimate("arid");   
     SetInventory( ([
        NPC+"guards" : random(2)+2,
      ]) );
  SetDomain("Valley");
} 
