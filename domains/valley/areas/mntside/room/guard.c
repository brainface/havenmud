/* Create by Aramuuk. 1998 */
#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("a small hut");
    SetLong("This is a small hut which appears to be a barracks of some kind. "+
      "The walls are all made of stone and the roof from rough hewn "+
      "planks. There are two sets of bunk bed, one against the east wall "+
      "and the other against the west wall. At the head and foot of each "+
      "bunk is an open cabinet with hooks from which clothes and weapons "+
      "can hang. In the center of the room is a small fire pit. Just to "+
      "the north of the firepit is a small, simple table surrounded by "+
      "four simple chairs.");
    SetItems( ([
	({ "table","chair","chairs" }) : "The table and chairs are made in a "+
	"a very utilitarian fashion from local hardwoods.",
	({ "wall","stone wall", "stone","walls","stone walls" }) : 
	"At first glance the walls look to "+
	"be made from stones haphazardously piled one on the other. However, "+
	"on closer inspection it can be seen that the walls are of exquisite "+
	"craftmenship.",
	({ "roof", "wood roof", "wood" }) : "The roof is made from close fitting, "+
	"roughly hewn planks. ",
	({ "planks", "rough planks", "rough hewn planks" }) : "The planks seem to "+
	"be honed from trees using only axes, but the quality is still quite high!",
	({ "bed", "bunk bed", "bunk beds", "beds" }) : 
	"Like all the furniture here the bunks are made in a very simple "+
	"fashion. They are made from native wood and the pallets are "+
	"covered with local grasses and animal skins.",
	({ "cabinet", "cabinets" }) : "The cabinets look, essentially, like a "+
	"box set up on it's long end. Small pegs have been fitted at the "+
	"upper end of the cabinet for clothes and weapons to be hung from.",
	({ "pit", "fire", "fire pit", "small pit", "small fire pit" }) : 
	"This is a small pit dug in the hard "+
	"ground and surrounded by large flat stones. A low fire burns in "+
	"the pit emitting a sweet smoke.",
      ]) );
    SetClimate("indoors");
    SetAmbientLight(25);
    SetExits( ([
	"out" : RMS+"mpath5",
      ]) );
    SetSmell( ([
	"default":"The fire smells very sweet, as if something had been added "+
	"to it to freshen the room." ,
      ]) );
    SetInventory( ([
	NPC+"guards" : random(4)+4,
      ]) );
  SetDomain("Valley");
}
