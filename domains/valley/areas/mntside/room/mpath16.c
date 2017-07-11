/* Create by Aramuuk. 1998 */                                                   
#include <lib.h>                                                                
#include <std.h>                                                                
#include "../path.h"                                                            
inherit LIB_ROOM;                                                               

static void create() {                                                          
    room::create();                                                             
    SetShort("the mountain path");                                              
    SetLong("This is the start of a path climbing the mountain. Around "+
      "the path the ground is rugged but can support plant life; grasses "+
      "and shrubs grow in plenty around the path. Just down the mountain "+
      "is a shale slide.");                                          
    SetItems( ([         
	({ "shale", "shale slide", "slide" }) : "A pile of loose shale "+
	"which has slid down the mountainside from somewhere above. It "+
	"looks as if one could climb it and gain access to the woods "+
	"below.",                                                       
	({ "path" }) : "A worn path up the side of a mountain.",              
	({ "mountain" }) : "One of they mountains in the Crystal Reaches "+     
	"range. The snowcap is far above you.",                                 
	({ "shrub", "shrubs" }) : "The shrubs are small and grow close to the "+
	"ground. Each branch has a lot of small, flat, thick leaves which "+    
	"appear very durable.",                                                 
	({ "grass", "grasses" }): "The grasses grow wherever "+       
	"they can find purchase in the rocky soil. Enough of the grasses "+     
	"put together would form a nice mattress.",                             
      ]) );                                                                     
    SetExits( ([                                                                
	"up" : RMS+"mpath15", 
	"down" : RMS + "path8",
      ]) );                  
    SetClimate("arid"); 
    SetInventory( ([
        NPC+"mdwarf" : random(3)+2,
        NPC+"fdwarf" : random(3)+2,
      ]) );  
  SetDomain("Valley");
} 

