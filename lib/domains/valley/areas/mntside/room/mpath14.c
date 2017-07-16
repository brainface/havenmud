/* Create by Aramuuk. 1998 */                                                   
#include <lib.h>                                                                
#include <std.h>                                                                
#include "../path.h"                                                            
inherit LIB_ROOM;                                                               

static void create() {                                                          
    room::create();                                                             
    SetShort("the mountain path");                                              
    SetLong("This is a path up the side of a mountain. At this point on "+
      "the path the ground is rugged but can support plant life; grasses "+
      "and shrubs grow in plenty around the path. Further up the path "+
      "can be seen a pair of plateaus; one above the other.");                                          
    SetItems( ([                                                                
	({ "shrub", "shrubs" }) : "The shrubs are small and grow close to the "+
	"ground. Each branch has a lot of small, flat, thick leaves which "+    
	"appear very durable.",                                                 
	({ "grass", "grasses" }): "The grasses grow wherever "+       
	"they can find purchase in the rocky soil. Enough of the grasses "+     
	"put together would form a nice mattress.",                             

	({ "path" }) : "A worn path on the edge of the mountain.",              
	({ "mountain" }) : "One of they mountains in the Crystal Reaches "+     
	"range. The snowcap is far above you.",                                 
	({ "plateau","plateaus", }) : 
	"The plateau(s) are hidden from view at this point. All you can "+
	"tell is that there is a flattening of the mountain above you.",                                                                        
      ]) );                                                                     
    SetExits( ([                                                                
	"up" : RMS+"mpath13", 
	"down" : RMS+"mpath15",                                             
      ]) );                   
    SetClimate("arid");   
    SetInventory( ([
        NPC+"mdwarf" : random(3)+2,
        NPC+"fdwarf" : random(3)+2,
      ]) );
  SetDomain("Valley");
} 
