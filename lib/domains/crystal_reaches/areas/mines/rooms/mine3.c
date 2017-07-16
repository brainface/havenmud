/*    /realms/haun/areas/mines/rooms/mine3.c
 *    created on 12/20/98
 *    by Haun
 */

#include <lib.h>
#include "../mine1.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("underground");
    SetAmbientLight(12);
    SetShort("a dark corner");
    SetLong("Here the cave ends abruptly and turns a sharp curve to the"
      " west.  The cave is becoming dryer, with the only exception of a light"
      " mist that still overtakes the humid air.  A faint light is entering"
      " from the west, which is flickering constantly.  Here the cave's walls"
      " seem to be marked up violently by small tools.  There are large"
      " and small pieces of rock lying all around the floor of the cave,"
      " making a hazard on all who enter.");
    SetItems( ([
	"cave"  :  (: GetLong :),
	({"wall", "ceiling", "earth", "walls"}) :
	"The walls of this cave are made of hard, solid rock."
	"  It has a dull, gray color.  There are many marks on the walls, which appear"
	" to be from small mining tools.",
	({"light", "distance", "flicker"})  :
	"In the distance there is a faint light which seems to be flickering."
	"  The light is very dim and is barely enough light the tunnel.",
	({"tool", "tools"})  :
	"There appears to be tool marks on the walls of the cave.",
	({"air", "mist", "gust"})  :
	"A light mist lingers in the air.  Small gusts of the humid air are"
	" entering from the south.",
	({"pieces", "rocks", "hazard", "floor", "peices of rock"})  :
	"Small pieces of rock are littering the ground all about.  Most of these"
	" are large chunks, but there are some small fragments lying about.  These"
	" rocks seems to have been chipped from the walls of the cave.",
	({"curve", "curves"})  :
	"Here the cave turns sharply to the west.",
	({"holes", "cracks", "marks"})  :
	"The walls of this cave are full of stray marks that appear to have"
	" been derived from small hand tools that are used to mine this cave." ,
      ]) );

    SetItemAdjectives( ([
	"cave"    :  ({"dark", "damp", "gray"}),
	"earth"    :  ({"wet", "grey"}),
	"light"  :  ({"dim", "flickering"}),
	"curve"    :  ({"sharp"}),
	"mist"    :  ({"damp", "light"}),
	"flicker"    :  ({"constant", "dim"}),
	"wall"    :  ({"damp", "picked", "marked"}),
	"air"    :  ({"stale", "damp"}),
	"pieces"    :  ({"small", "large"}),
	"hazard"    :  ({"small", "large"}),
	"marks"    :  ({"large", "small"}),
      ]) );

    SetInventory( ([
	M1_NPC + "/miner1.c" : 2
      ]) ); 

    SetSmell( ([
	"default"  :  "The smell of stale water lingers in the air",
      ]) );

    SetListen( ([
	"default"  :  "The faint sound of dripping water is heard.",
      ]) );

    SetExits( ([
	"south"  :  M1_ROOM + "/mine1.c",
	"west"  :  M1_ROOM + "/mine3w.c",
      ]) );
}
