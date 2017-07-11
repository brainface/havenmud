/*    /realms/haun/areas/mines/rooms/start2.c
 *    created on 12/20/98
 *    by Haun
 */

#include <lib.h>
#include "../mine1.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("a dusty crossing");
    SetDomain("Crystal Reaches");
    SetLong("This small path appears to be a junction point for some smaller,"

      " less defined paths that run into it.  There is foliage surrounding"
      " this path on all sides, but fainly through the green hues,"
      " three paths, heading in multiple directions can be seen."
      "  These paths appear to have had little traffic in the past,"
      " and are barely noticeable because of this.  A much larger path"
      " leads north, toward Glimmerdin Road.");
    SetItems( ([
	"paths"  :  (: GetLong :),
	"junction"  :  (: GetLong :),
	"point"  :  (: GetLong :),
	({"foliage", "plant", "plants", "hues", "hue"}) :
	"There is foliage of many different hues scattered all about the path."
	"  Most of this covers the paths that lead to the east, west, and"
	" southeast.",
	({"glimmerdin", "glimmerdin road", "road", "Glimmerdin Road"}) :
	" Glimmerdin Road lies to the north of this path.  It is a wide road, that"
	" leads to the town of Glimmerdin.",

      ]) );

    SetItemAdjectives( ([
	"paths"    :  ({"dusty", "small"}),
	"junction"    :  ({"dusty", "small"}),
	"point"  :  ({"dusty", "small", "junction"}),
	"foliage"    :  ({"green", "large", "small"}),
      ]) );
    SetInventory( ([M1_NPC + "/cgoat"  :  1]) ); 

    SetSmell( ([

	"default"  :  "The smell of flowers flutter all about.",
      ]) );

    SetListen( ([
	"default"  :  "The screaming sounds of nature are present.",
      ]) );

    SetExits( ([
	"north"  :  M1_ROOM + "/start.c",
	"west"  :  M1_ROOM + "/start2w.c",
	"east"  :  M1_ROOM + "/start2e.c",
	"southeast"  :  M1_ROOM + "/start3.c",
      ]) );
}
