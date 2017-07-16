#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("underground");
    SetAmbientLight(40);
    SetShort("just inside a mine");
    SetLong(
      "Mishapen stairs climb down into the depths "
      "of the mine.  From here, grasses can be seen just outside the "
      "tunnel.  Torches have been set on the walls to illuminate the "
      "mine.  The walls have been cut and hammered in an "
      "irregular fashion,  but the dark, smooth characteristics "
      "of the hillside's stone can still be easily seen.");
    SetItems( ([
      ({"stairs", "stair"})  :
      "The stairs are misshapen but very large and shallow.",
      "stone"  :
      "The stone is a dark, cold and very damp.",
      ({"torches", "torch", "light"})  :
      "Torches have been lit to illuminate the mine.  They flicker "
      "as air from the interior of the mine rushes by.",
      "mouth"   :
      "The mouth of the tunnel is the entrance to the mine.",
      ({"walls", "wall"})  :
      "The walls of the mine are made from a dark, cold stone that is "
      "very damp.",
      ({"grass", "grasses"})  :
      "Grasses can be seen outside the tunnel.",
    ]) );
    SetItemAdjectives( ([
      "stair"  :  ({"misshapen", "stone", "large", "shallow"}),
      "stone"  :  ({"hillside", "damp", "dark", "cold"}),
      "torches"    :  "lit",
      "walls"    :  ({"dark", "cold", "damp", "wet"}),
      "grass"    :  ({"waving", "brown", "tall"}),
    ]) );
    SetSmell( ([
      "default"  :  "No smell lingers.",
    ]) );
    SetListen( ([
      "default"  :  "The rushing air dampens noise.",
    ]) );
    SetExits( ([
      "out"  :  ROOMS + "/mouth.c",
      "down"  :  ROOMS + "/mine2.c",
    ]) );
}
