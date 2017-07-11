/*    Updated on 1/16/99
 *    by Haun for MUD_Upkeep purposes.
*/
#include <lib.h>
#include "path.h"
inherit LIB_ROOM;
static void create() {
    room::create();
    SetClimate("indoors");
    SetDomain("HavenWood");
    SetAmbientLight(30);    
    SetShort("inside a rundown shack");
    SetProperty("no bump",1);
    SetLong("The inside of the shack is very dimly lit and its "
      "contents are covered with a thick blanket of dust.  "
      "There is a straw mattress lying in one corner and "
      "a heavy looking table cluttered with items takes up "
      "most of the rest of the room.  There appears to be "
      "nothing else of any value in the shack.");
    SetItems( ([({"rundown shack","shack"}) : 
	"The shack is built of wood and seems about ready "
	"to collapse." ,
	({"contents"}) :
	"Not much here besides a mattress and table. ",
	({"thick blanket of dust","blanket of dust","dust","blanket"}) 
	:
	"The dust covers almost everything. ",
	({"wood"}) :
	"The wood is old and splintered.",
	({"straw mattress","mattress"}) :
	"The mattress is old and has straw sticking out "
	"of it all over the place",
	({"straw"}) :
	"The straw is used as stuffing in the mattress.",
	({"heavy looking table","heavy table","table"}) :
	"It is covered with books.",
	({"books","book","items"}) :
	"They are of beautiful colors and are covered with "
	"ornate designs.  It seems to be written in some "
	"unfamiliar writing.",
	({"beautiful colors","colors","ornate designs","designs"}) :
	"They appear to be very mystic.",
	({"unfamiliar writing","writing"}) :
	"The writing may be the script of a sorcerer." 
      ]) );
    SetListen( (["default" : "The shack is deathly silent."]));
    SetSmell(  (["default" : "A musty but acrid smell fills the shack"]));
    SetExits( ([ "out" : GLEN + "/rooms/path8"]));
    SetObviousExits("out");
    SetInventory(([GLEN + "/npc/sorcerer2": 1]) );
}
