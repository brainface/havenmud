/* Create by Aramuuk. 1998 */
#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("a large hut");
    SetLong("This is a well constructed hut made from stone and wood. "+
      "The walls are all made of stone and the roof made from rough hewn "+
      "planks. Along the walls are piles of pelts and grasses, apparently "+
      "used for sitting. In the center of this room is a fairly large fire "+
      "pit with an empty spit placed over it.");
    SetItems( ([
	({ "wall","stone wall", "stone","walls","stone walls" }) : 
	"At first glance the walls look to "+
	"be made from stones haphazardously piled one on the other. However, on "+
	"closer inspection it can be seen that the walls are of exquisite "+
	"craftmenship.",
	({ "roof", "wood roof", "wood" }) : "The roof is made from close fitting, "+
	"roughly hewn planks. ",
	({ "planks", "rough planks", "rough hewn planks" }) : "The planks seem to "+
	"be hone from trees using only axes, but the quality is still quite high!",
	({ "spit" }) : "This is a long thing metal rod used for cooking meat over "+
	"the fire pit. At one end there is a handle for turning the meat. The "+
	"spit rests on two forked pieces of wood which are stuck in the ground "+
	"outside the fire pit.",
	({ "piles", "pelts", "piles of pelts", "grasses", "piles of grasses",
	  "piles of pelts and grasses" }) : "These piles of pelts and grasses make "+
	"fairly comfortable cushions and keep one off the cold, hard ground when "+
	"sitting around the fire pit.",
	({ "pit", "fire", "fire pit" }) : "This is a round pit dug in the hard "+
	"ground and surrounded by large flat stones. A low fire burns in the "+
	"pit emitting a sweet smoke.",
      ]) );
    SetClimate("indoors");
    SetAmbientLight(30);
    SetExits( ([
	"out"   : RMS+"mpath5",
	"north" : RMS+"chief2",
      ]) );
    SetSmell( ([
	"fire" : "The fire smells very sweet, as if something had been added to "+
	"it to freshen the room." ,
	"smoke" : "The fire smells very sweet, as if something had been added to "+
	"it to freshen the room." ,
	"habitation" : "The smell of dwarven sweat hangs heavy in the air.",
	"default" : "The room smells of smoke and strongly of habitation.",
      ]) );
    SetInventory( ([
	NPC+"leader" : 1,
	NPC+"guards" : 4,
      ]) );
  SetDomain("Valley");
}
