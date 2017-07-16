/*    Updated on 1/16/99
 *    by Haun for MUD_Upkeep purposes.
*/
#include <lib.h>
#include <domains.h>
#include "path.h"
inherit LIB_ROOM;
static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("HavenWood");
    SetShort("the glen");
    SetLong("Here the path seems to open into a large, grassy glen.  "
      "The ancient trees of the forest form a tight ring around "
      "the large open space.  While the glen is a display of "
      "natural beauty, it is clear from the path and the trampled "
      "nature of the grass that is well used for some purpose.  ");
    SetItems( ([
	({"green grass","grass","tall grass"}) :
	"The grass is very green and grows to almost "
	"knee high." ,
	({"natural beauty","beauty"}) : (: GetLong :) ,
	({"dirt path","path","dirt strip"}) :
	"The path is little more than a dirt strip "
	"worn through the grass due to travel." ,
	({"ancient trees","trees","ancient tree","tree"}) :
	"The trees form a protective barrier around "
	"the glen.",
	({"ancient forest","forest","dark forest"}) :
	"The ancient forest is dark in comparison to "
	"the open glen." ,
	({"large grassy glen","large glen","grassy glen",
	  "open glen"}) :
	"The glen is a large, grassy open space in the "
	"middle of the forest." ,
	({"tight ring","ring"}) :
	"The ring is made up of ancient trees." ,
	({"protective barrier","barrier"}) :
	"The protective barrier is made of up ancient "
	"trees.",
	({"large open space","open space","space"}) :
	"The open space is surrounded by trees."
      ]) );
    SetListen( (["default" : "Faint voices can be heard to the east."]));
    SetExits( ([ "east"  : GLEN + "/rooms/path2" ,
        "west" : HAVENWOOD_AREAS "wood/rooms/wood4",
       ]) );
}
