/*    /realms/haun/areas/mines/rooms/mine4.c
 *    created on 12/20/98
 *    by Haun
 */

#include <lib.h>
#include "../mine1.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("underground");
    SetAmbientLight(20);
    SetShort("a large corner");
    SetLong("The cave here turns a huge corner, ending up pointing to the"
      " north. It seems to have a few small marks located on the cave's"
      " walls, which are the result of miners that have been picking"
      " and shoveling in the area. The cave here is very dry, and the"
      " only sound that is present is of miners that fill these caves."
      "  Torches are hanging all around the room, helping light the"
      " miners work.");
    SetItems( ([
	"cave"  :  (: GetLong :),
	"caves"  :  (: GetLong :),
	"tunnel"  :  (: GetLong :),
	"mine"  :  (: GetLong :),
	"corner"  :  (: GetLong :),
	({"wall", "ceiling", "earth", "walls", "rock"}) :
	"The walls of this cave are made of hard, solid rock."
	"It has a dull, gray color.  There are many marks on the walls, which appear"
	" to be from small mining tools.",
	({"mark", "marks"})  :
	"There appears to be tool marks on the walls of the cave.  These"
	" marks are long, and seem to be dug deep into the cave wall.",
	({"torch", "torches", "gust"})  :
	"There are multiple torches hanging from the wall, whose purpose is to light"
	" the miners work, so that they can see what they are doing.",
      ]) );

    SetItemAdjectives( ([
	"cave"    :  ({"dark", "damp", "gray"}),
	"caves"    :  ({"dark", "gray", "damp"}),
	"tunnel"  :  ({"dark", "gray", "damp"}),
	"mine"    :  ({"dark", "gray" "damp"}),
	"corner"    :  ({"damp", "dark", "gray"}),
	"mark"    :  ({"long", "deep", "small", "tool"}),
	"wall"    :  ({"marked", "gray", "hard", "rock"}),
	"torch"    :  ({"lit", "large"}),
      ]) );

    SetInventory( ([
	M1_NPC + "/miner2.c"  :  3,
	M1_NPC + "/miner3.c"  :  2,
	M1_OBJ + "/torch.c"  :  2,
      ]) ); 

    SetSmell( ([
	"default"  :  "The smell of stale water lingers in the air",
      ]) );

    SetListen( ([
	"default"  :  "The sound of hardworking miners is present.",
      ]) );

    SetExits( ([
	"east"  :  M1_ROOM + "/mine3w.c",
	"north"  :  M1_ROOM + "/mine5.c",
      ]) );
}
