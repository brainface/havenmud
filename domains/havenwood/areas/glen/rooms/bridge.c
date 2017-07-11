/* This file was updated on 01/15/99
* by Haun for mud-upkeep purposes.
*/
#include <lib.h>
#include "path.h"
inherit LIB_ROOM;
static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("HavenWood");
    SetShort("a well crafted wooden bridge");
    SetLong("Standing on the bridge, one can look over the edge and "
      "see the waters of the stream flowing slowly northward.  "
      "The bridge itself is of heavy timber.  A path extends "
      "from the bridge heading towards the east and west.  ");
    SetItems( ([
	({"well crafted wooden bridge","bridge"}) :
	"The bridge is made of heavy "
	"timber and clearly used often to cross the stream." ,
	({"heavy timber","timber"}) :
	"The timber is hewn from the ancient trees of "
	"the forest.",
	({"shallow stream","stream","water"}) :
	"The stream is rather shallow." ,
	({"well travelled dirt path","dirt path","path"}) :
	"It is a well travelled dirt path."]) );
    SetListen( (["default" : "A stream babbles softly below."]));
    SetSmell( ([ "default" : "The smell of aged lumber is in the air."]) );
    SetExits( ([ "east"  : GLEN + "/rooms/path3",
	"west"  : GLEN + "/rooms/path2"]));
}
