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
    SetShort("west of a bridge");
    SetLong("The path here cuts through knee high grass heading "
      "towards the bridge to the east and the entrance to "
      "the glen to the west.  It seems that the glen is a "
      "very popular place for the local clan of gelfling to "
      "get together.  ");
    SetItems( ([
	({"wooden bridge","bridge"}) :
	"The bridge to the east spans the stream "
	"to make it easier to cross." ,
	({"knee high grass","grass"}) :
	"The grass along the path is almost knee high." ,
	({"shallow stream","stream"}) :
	"The stream flows slowly under the bridge "
	"to the east." ,
	({"dirt strip","dirt path","path"}) :
	"The path is little more than a dirt strip "
	"worn through the grass due to travel." ,
	({"forest glen","glen"}) :
	"The glen is an open area in the middle of the "
	"forest.",
	({"barely visible forest","forest"}) :
	"The forest is barely visible across the glen."
      ]) );
    SetListen( ([ "default" : "The noises of children playing come "
	"from the north."]));
    SetExits( ([ "east"  : GLEN + "/rooms/bridge" ,
	"west"  : GLEN + "/rooms/path1" ,
	"north" : GLEN + "/rooms/path4" ,
	"south" : GLEN + "/rooms/path5"]));
}
