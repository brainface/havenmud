/* Create by Aramuuk. 1998 */
#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("a room in a large hut");
    SetLong("This is the back room of the large hut. "+
      "The walls are all made of stone and the roof made from rough hewn "+
      "planks. Unlike the outter room, this room is much smaller and "+
      "appears to be better kept. On the north wall is a wide pallet "+
      "covered in grass and skins. Along the walls hang various furs and "+
      "hides fashioned into crude clothing. In the center of the room is "+
      "a small fire pit.");
    SetItems( ([
	({ "wall","stone wall", "stone","walls","stone walls" }) : 
	"At first glance the walls look to "+
	"be made from stones haphazardously piled one on the other. However, "+
	"on closer inspection it can be seen that the walls are of exquisite "+
	"craftmenship.",
	({ "roof", "wood roof", "wood" }) : "The roof is made from close fitting, "+
	"roughly hewn planks. ",
	({ "planks", "rough planks", "rough hewn planks" }) : "The planks seem to "+
	"be honed from trees using only axes, but the quality is still quite high!",
	({ "pallet", "grass", "skins", "skins" }) : "The pallat appears to "+
	"be a bed and is thickly covered in fine skins and grasses.",
	({ "pit", "fire", "fire pit", "small pit", "small fire pit" }) : 
	"This is a small pit dug in the hard "+
	"ground and surrounded by large flat stones. A low fire burns in "+
	"the pit emitting a sweet smoke.",
      ]) );
    SetClimate("indoors");
    SetAmbientLight(25);
    SetExits( ([
	"south" : RMS+"chief",
      ]) );
    SetSmell( ([
	"default":"The fire smells very sweet, as if something had been added "+
	"to it to freshen the room." ,
      ]) );
    SetInventory( ([
    	NPC+"fleader" : 1,
			NPC+"guards" : 4,
      ]) );
  SetDomain("Valley");
}

