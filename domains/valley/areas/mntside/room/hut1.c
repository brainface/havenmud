/* Create by Aramuuk. 1998 */
#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("a small hut");
    SetLong("This is a small hut made of stone and wood. In the center "+
      "of the hut is a small fire pit. This room appears to be used "+
      "as a dwelling for a small group of people. There are two piles "+
      "of grass and pelts, and some small food storage containers. "+
      "Other than that there is nothing remarkable in the room.");
    SetItems( ([
	({ "pile", "piles", "grass", "pelt", "pelts" }) :
	"The grasses and pelts of various animals are piled into two "+
	"heaps which appear to be beds. Each pile looks as if it "+ 
	"is used frequently.",
	({ "container", "containers" }) : "The containers are small earthen "+
	"jars which can be used to store food. Some jars contain dried "+
	"plant foods (fruits, vegetables, greens, etc), others contain "+
	"dried animal flesh and still others contain water.",
	({ "wall","stone wall", "stone","walls","stone walls" }) : 
	"At first glance the walls look to "+
	"be made from stones haphazardously piled one on the other. However, "+
	"on closer inspection it can be seen that the walls are of exquisite "+
	"craftmenship.",
	({ "roof", "wood roof", "wood" }) : "The roof is made from close fitting, "+
	"roughly hewn planks. ",
	({ "planks", "rough planks", "rough hewn planks" }) : "The planks seem to "+
	"be honed from trees using only axes, but the quality is still quite high!",
	({ "pit", "fire", "fire pit", "small pit", "small fire pit" }) : 
	"This is a small pit dug in the hard "+
	"ground and surrounded by large flat stones. A low fire burns in "+
	"the pit emitting a sweet smoke.",
      ]) );
    SetClimate("indoors");
    SetAmbientLight(25);
    SetExits( ([
	"out" : RMS+"center",
      ]) );
    SetSmell( ([
	"default":"The fire smells very sweet, as if something had been added "+
	"to it to freshen the room." ,
      ]) );
    SetInventory( ([
	NPC+"mdwarf" : random(3)+3,
	NPC+"fdwarf" : random(3)+3,
      ]) );
  SetDomain("Valley");
}
