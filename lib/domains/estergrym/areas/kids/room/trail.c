//Samah@Haven
//20040911
#include "../clearing.h"
#include <lib.h>
#include <std.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an overgrown trail");
  SetDayLong(
     "The trail is all but covered by brambles "
     "and bushes that threaten to obscure its path  "
     "completely.  Ahead, a small break in "
     "the foliage provides a glimpse into a small clearing.  "
     "To either side of the narrow path, the brambles serve as a "
     "natural barrier barring entrance into the clearing." 
  );
  SetNightLong(
     "Dark shadows fill the area as moonlight filters "
     "through the thick and vicious brambles that line the sides "
     "of the path.  Ahead, a small clearing is barely visible "
     "in the gloomy night.  Farther down the path, a small gap "
     "in the brambles seems to be the only way to continue "
     "into the thorny patch."
  );
  SetItems( ([ 
     ({ "trail", "path" }):
     "The trail is nearly completely consumed by the "
     "dense brambles that surround it.  However, a small "
     "set of tracks can be seen in the dirt.",
     ({ "brambles", "bramble", "bushes", "bush"," foliage","patch"
     "barrier"
     }):
     "The brambles are sharp and threaten to snag any "
     "loose articles of clothing that may drift too near.",
     ({ "clearing" }):
     "The clearing lays just to the east and appears to be "
     "the only way through the brambles.",
     ({ "tracks", "footprints" }):
     "The tracks appear to be the footprints of a small "
     "animal or perhaps a child.",
     ({ "shadow","shadows" }):
     "The dark shadows filter through the sharp brambles, causing "
     "irregular shapes to dance across the path.",
     ({ "break","gap" }):
     "The natural break in the brambles creates a gap in the "
     "dense barrier, allowing access deeper into the foliage.",
     ({ "shapes","shape" }):
     "The dark shapes dance across the path, as the wind moves the the "
     "brambles to and fro."
  ]) );
  SetItemAdjectives( ([
     "trail" : ({ "small", "covered", "obscured","narrow" }),
     "brambles" : ({ "thorny", "dense", "sharp","thick","vicious" }),
     "clearing" : ({ "small" }),
     "tracks" : ({ "small" }),
     "break" : ({ "natural","small" }),
     "shadow" : ({ "dark" }),
     "shapes" : ({ "irregular","dark" }),
  ]) );
  SetSmell( ([
     "default" : "The smell of fresh sap fills the air",
  ]) );
  SetListen( ([
     "default" : "The sounds of crying children can be heard in the air",
  ]) );
  SetExits( ([
     "east"      : CLEAR_ROOM "clearing1",
     "southwest" : "/domains/estergrym/virtual/northroad/0,0",
  ]) );
}


/** Approved by Laoise at Sat Sep 11 20:24:24 2004. **/