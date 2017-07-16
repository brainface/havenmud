/* Create by Aramuuk. 1998 */
#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
  SetDomain("Valley");
    SetShort("a small round hut");
    SetLong("This is a small round hut. In the center of the hut burns a "+
      "large blue fire. Painted on the walls are pictographs of strange "+
      "rituals surrounded by enigmatic symbols. There is nothing else of "+
      "note in the room. ");
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
	({ "pit", "fire", "fire pit", "blue fire", "large blue fire" }) : 
	"The fire pit appears to be much to small to contain anything which "+
	"could generate the fire which burns within. The blue flames seem "+
	"to shoot right out of the ground and nearly touch the roof! The "+
	"fire emits a strange acrid smoke.",
	({ "pictographs", "symbols", "strange symbols" }) :
	"The pictographs depict acts of sacrifice and contain much sexual "+
	"innuendo. The symbols which surround each pictograph are "+
	"indecipherable to you.",
      ]) );
    SetClimate("indoors");
    SetAmbientLight(23);
    SetExits( ([
	"out" : RMS+"mpath5",
      ]) );
    SetListen( ([ 
	"default" : "A strange chanting or humming sounds assaults your "+
	"ears making you feel quite uncomfortable.",
      ]) );
    SetSmell( ([
	"default":"The fire smells of an odd mixture of herbs, sulfur, and "+
	"other various magical compounds." ,
      ]) );
    SetInventory( ([
	NPC+"cedar" : 1,
      ]) );
}
