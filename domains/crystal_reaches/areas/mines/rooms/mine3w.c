/*    /realms/haun/areas/mines/rooms/mine3w.c
 *    created on 12/20/98
 *    by Haun
 */

#include <lib.h>
#include "../mine1.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("underground");
    SetAmbientLight(15);
    SetShort("a dusty mine");
    SetLong("This part of the cave seems to have been mined for all of its"
      " worth.  There are huge gashes in the walls, where the picks and"
      " shovels have devoured them.  The cave is becoming brighter as"
      " the tunnel precedes to the faint light that is present to the"
      " west.  This cave is very dry, and there are sounds coming from"
      " the east and west. ");
    SetItems( ([
	"cave"  :  (: GetLong :), 
	"mine"  :  (: GetLong :),
	"caves"  :  (: GetLong :),
	"tunnel"  :  (: GetLong :), 
	({"wall", "ceiling", "earth", "walls"}) :
	"The walls of this cave are made of hard, solid rock."
	"It has a dull, gray color.  There are many marks on the walls, which appear"
	" to be from small mining tools.",
	({"gashes", "gash", "picks", "pick", "shovel", "shovels"})  :
	"The gashes on the wall are long, and deep into the hard rock.  These"
	" gashes appear to have been made my small mining tools, such as"
	" shovels, and picks.",
	({"light", "candle", "lantern"})  :
	"There is a flickering light that lies to the west.  It appears to"
	" come from a source, such as a candle or lantern.",
      ]) );

    SetItemAdjectives( ([
	"cave"    :  ({"dark", "damp", "gray"}),
	"earth"    :  ({"wet", "grey"}),
	"light"  :  ({"dim", "flickering"}),
	"pick"    :  ({"sharp", "small"}),
	"shovel"    :  ({"small", "sharp"}),
	"tunnel"    :  ({"dark", "gray"}),
	"wall"    :  ({"damp", "picked"}),
	"gashes"    :  ({"stale", "damp", "long", "deep", "huge"}),
      ]) );

    SetSmell( ([
	"default"  :  "The smell of stale water lingers in the air",
      ]) );

    SetListen( ([
    "default" : "The sounds of mining can constantly be heard from "
    "the east and west.",
      ]) );

    SetExits( ([
	"east"  :  M1_ROOM + "/mine3.c",
	"west"  :  M1_ROOM + "/mine4.c",
      ]) );
}
