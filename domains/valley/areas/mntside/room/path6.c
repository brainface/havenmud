/* Create by Aramuuk. 1998 */                                                   
#include <lib.h>                                                                
#include <std.h>                                                                
#include "../path.h"                                                            
inherit LIB_ROOM;                                                               

static void create() {                                                          
    room::create();                                                             
    SetLong("This is a faint path running through the pine forest which "+
      "borders the Crystal Reaches. The woods are still present but have "+
      "thinned mostly to underbrush. At this point a slide of some sort "+
      "is visible ahead at the foot of the mountains.");                                         
    SetShort("On a shale slide");
    SetItems( ([                                                                
	({ "path" }) : "This is a slightly worn path through the woods. It "+
	"resembles an animal track.",                                                       
	({ "tree", "trees", "pine trees", "pines", "forest", "woods" }) :       
	"The trees in this part of the forest are mainly pine, with a few "+
	"birch and oaks thrown in.",                                                               
	({ "foothills", "foothill", "crystal reaches", "reaches", "mountain",
	  "mountains" }) :                                                                
	"The mountain is clearly visible at this point. There seems to be "+
	"a slide of some sort at it's foot.",                                         
	({ "underbrush" }) : "Small plants which grow close together and "+
	"even closer to the ground.",                                                                
	({ "foliage" }) : "The foliage has thinned enough to reveal most "+
	"of the mountains clearly.",                                                                    
      ]) );     
     SetInventory( ([
        NPC+"mdwarf" : random(2)+2,
        NPC+"fdwarf" : random(2)+2,
      ]) );                                                                
  SetDomain("Valley");
    SetClimate("temperate");    
    SetExits( ([                                                                
	"northwest"  : RMS+"path7",
	"southeast"  : RMS+"path5", 
      ]) );
} 
