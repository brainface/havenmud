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
    SetShort("an area of flattened grass");
    SetLong("The grass here has been crushed flat and various "
      "children's toys lie strewn about.  A stream flows "
      "quietly by to the east, and the dense forest closes "
      "off any travel to either the north or the west."
    );
    SetItems( ([ ({"well trampled grass","trampled grass","grass"}) :
	"The grass is well trampled from the constant "
	"play of gelfling children." ,
	({"shallow stream","stream"}) :
	"The stream is uncrossable at this point. " ,
	({"toys for children","toy","toy for children","toys"}) :
	"The children's toys are rough looking and "
	"appear to be handmade.  None of them would "
	"be worth your time or effort to pick up.",
	({"gelfling children","children"}) :
	"If they're not here, they must be off "
	"playing somewhere else.",
	({"dense forest","forest"}) :
	"The forest encircles one to the northwest."
      ]) );
    SetExits( ([ "south" : GLEN + "/rooms/path2"]));
    SetInventory(([GLEN + "/npc/malechild": (random(2)+1)]) );
SetInventory(([GLEN + "/npc/femalechild": (random(2)+1)]) );
}
