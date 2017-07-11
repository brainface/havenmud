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
    SetShort("east of a bridge");
    SetLong("The grass here isn't as green as on the other side of "
      "the stream.  It appears to thin out as it approaches "
      "an earthen clearing to the east.  The bridge is still "
      "visible to the west, and one could clearly follow "
      "along the stream to the north or south.");
    SetItems( ([ ({ "wooden bridge","bridge"}) :
	"The bridge to the west spans the stream "
	"to make it easier to cross." ,
	({"thinning grass","grass"}) :
	"The grass isn't as green here, and there "
	"isn't nearly as much of it compared to "
	"the other side of the stream.  The "
	"grass over there, however, is thick and "
	"green and very healthy." ,
	({"shallow stream","stream"}) :
	"The stream flows slowly under the bridge "
	"to the west." ,
	({"dirt strip","dirt path","path"}) :
	"The path is little more than a dirt strip "
	"worn through the grass due to travel." ,
	({"earthen clearing","clearing"}) :
	"It is little more than well packed dirt.",
	({"well packed dirt","dirt"}) :
	"It's well packed dirt... what more can be "
	"expected?"
      ]) );
    SetListen( (["default" : "A dry, chopping sound comes from the south."]));
    SetExits( ([ "east"  : GLEN + "/rooms/path8" ,
	"west"  : GLEN + "/rooms/bridge" ,
	"north" : GLEN + "/rooms/path6" ,
	"south" : GLEN + "/rooms/path7"]));
}
