// Targoviste
// Laoise
// August 2004

#include <lib.h>
#include <domains.h>
#include "../targoviste.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetTown("Targoviste");
  SetShort("south transept of the cathedral of Aberach");
  SetLong(
    "A large slab of granite stone sits in the center of this rounded "
    "area, where the transept of the cathedral widens to form the base "
    "of the southern tower. Tall and elaborate windows are spaced along "
    "the curved wall. Narrow lines of metal form elaborate tracery "
    "patterns within the windows, which fade at their very apex in to "
    "the looming darkness of the southern tower. Although this area "
    "appears nearly regimentally clean, a faint miasma still seems to "
    "hang over the area, composed of equal parts death, pain and blood."
  );
  SetItems( ([ 
    ({ "slab", "granite", "table" }) :
    "Manicles are bolted to each corner of the "
    "heavy table and a pair of chains appear designed to be strapped "
    "across, from side to side. Crossing from corner to corner are a "
    "set of narrow channels, which meet in the center and form a hole "
    "which bores deep in to the center of the granite slab.",

  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A uncomfortable silence reigns.",
  ]) );
  SetSmell( ([
    "default" : "A sharp coppery smell pervades the area, nearly obscuring "
    "the musky smell of incense.",
  ]) );
  SetExits( ([ 
    "north": TARG_ROOM "church3",
  ]) );
}
