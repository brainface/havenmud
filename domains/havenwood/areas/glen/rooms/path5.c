/*    Updated on 1/16/99
 *    by Haun for MUD_Upkeep purposes.
*/
#include <lib.h>
#include "path.h"
inherit LIB_ROOM;
static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("HavenWood");
    SetShort("near a stream");
    SetLong("Here the ground slopes gently towards a stream.  The bank "
      "of the stream is very muddy and full of footprints "
      "leading up to the edge of it.  Baskets sit around "
      "in the grass, and a rope has been run between two trees."
    );
    SetItems( ([ ({"tall green grass","green grass","tall grass","grass"}) :
	"The grass is tall and green ",
	({"muddy stream","stream"}) :
	"The stream is uncrossable at this point. " ,
	({"bank of the stream","muddy bank","bank","ground"}) :
	"It is muddy and slopes towards the stream. ",
	({"tiny gelfling footprints","gelfling footprints",
	  "footprints","footprint","gelfling footprint"}) :
	"They are tiny gelfling footprints.",
	({"whicker baskets","baskets","basket","baskets"}) :
	"They're made of whicker and used to hold"
	"freshly washed clothing.",
	({"clothes line","rope"}) :
	"It's used to hang clothes up to dry.",
	({"two trees","trees","tree"}) :
	"There is a rope ran between the trees."
      ]) );
    SetListen( (["default" : "The wind blows softly through the trees."]));
    SetSmell(  (["default" : "This area smells clean."]));
    SetExits( ([ "north" : GLEN + "/rooms/path2"]));
    SetInventory(([GLEN + "/npc/washwoman": 1]) );
}
