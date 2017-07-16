/*    /realms/haun/areas/mines/rooms/mine5.c
 *    created on 12/20/98
 *    by Haun
 */

#include <lib.h>
#include "../mine1.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(15);
    SetClimate("underground");
    SetShort("a dark mine end");
    SetLong("Here the mine ends abruptly.  The rockface at the end of this"
      " tunnel is very jagged and irregular.  Shadows loom in the corners"
      " strangely.  The rockface is covered with marks and indentations"
      " from recent mining work.  The only exit is to the south, which"
      " will lead out of the mine.");
    SetItems( ([
	"cave"  :  (: GetLong :),
	"caves"  :  (: GetLong :),
	"tunnel"  :  (: GetLong :),
	"mine"  :  (: GetLong :),
	"corner"  :  (: GetLong :),
	({"wall", "ceiling", "earth", "walls", "rockface"}) :
	"The walls of this cave are made of hard, solid rock."
      "  It has a dull, gray color.  There are many marks on the walls, which appear"
	" to be from small mining tools.  The rockface in this room has many"
	" indentations where miners have performed their work.",
	({"mark", "marks", "indentation"})  :
	"There appears to be tool marks on the walls of the cave.  These"
	" marks are long, and seem to be dug deep into the cave wall.",
	({"shadow", "shadows"})  :
	"Shadows loom in the corners of the room, perhaps light that has escaped"
	" from the south.",

      ]) );

    SetItemAdjectives( ([
	"cave"    :  ({"dark", "damp", "gray"}),
	"caves"    :  ({"dark", "gray", "damp"}),
	"tunnel"  :  ({"dark", "gray", "damp"}),
	"mine"    :  ({"dark", "gray" "damp"}),
	"corner"    :  ({"damp", "dark", "gray"}),
	"mark"    :  ({"long", "deep"}),
	"walls"    :  ({"marked", "gray"}),
	"wall"    :  ({"marked", "gray"}),
	"shadow"    :  ({"looming"}),
      ]) );

    SetInventory( ([
	M1_NPC + "/miner4.c"  :  1,
      ]) ); 

    SetSmell( ([
	"default"  :  "The smell of stale water lingers in the air",
      ]) );

    SetListen( ([
	"default"  :  "The sound of hardworking miners is present.",
      ]) );

    SetExits( ([
	"south"  :  M1_ROOM + "/mine4.c",
      ]) );
}
