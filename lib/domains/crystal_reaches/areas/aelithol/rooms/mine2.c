#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(40);
  SetShort("in a mine");
  SetLong(
    "Mishapen stairs climb to the mouth of the tunnel "
    "that can barely be seen from here. Torches have been "
    "set on the walls to illuminate the mine. The walls "
    "have been cut and hammered in an irregular fashion, "
    "but the dark, smooth characteristics of the hillside's stone "
    "can still be easily seen. The tunnel leads to the east."
  );
  SetItems( ([
    ({"stairs", "stair"})  :
     "The stairs are misshapen but very large and shallow.",
    "stone"  :
     "The stone is a dark, cold and very damp.",
     ({"torches", "torch", "light"})  :
       "Torches have been lit to illuminate the mine.  They flicker "
       "as air from the interior of the mine rushes by.",
      "mouth"   :
       "The mouth of the tunnel can barely be seen at the top of the stairs.",
     ({"walls", "wall"})  :
      "The walls of the mine are made from a dark, cold stone that is "
      "very damp.",
     "tunnel"  :
      "The tunnel leads to the east.",
]) );
  SetItemAdjectives( ([
    "stair"  :  ({"misshapen", "stone", "large", "shallow"}),
    "stone"  :  ({"hillside", "damp", "dark", "cold"}),
    "torches"    :  "lit",
    "walls"    :  ({"dark", "cold", "damp", "wet"}),
    "tunnel"    :  "dark",
  ]) );
  SetSmell( ([
    "default"  :  "No smell lingers.",
  ]) );
  SetListen( ([
    "default"  :  "The rushing air dampens noise.",
  ]) );
  SetExits( ([
     "east"  :  ROOMS + "/mine3.c",
    "up"  :  ROOMS + "/mine.c",
  ]) );
}
