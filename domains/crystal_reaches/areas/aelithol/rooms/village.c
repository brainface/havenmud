#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("a halfling village");
    SetDomain("Crystal Reaches");
    SetLong(
      "Hidden between many ancient hills, some halfling farmers "
      "have chosen to live among each other. Their fields and "
      "pastures stretch away into the distance, but they have "
      "made their burrows in close proximity with each other. "
      "Many of the halflings congregate here, giving the area "
      "a happy feeling."
    );
    SetItems( ([
      ({"pasture", "pastures"})  :
      "The pastures are green and the grass is kept short by "
      "the presence of various grazing animals.",
      "wheat"  :
      "Golden wheat waves gently in the breeze.",
      ({"burrow", "burrows"})  :
      "Halflings have dug burrows here.  Their little round doors "
      "can be seen protruding the hillsides everywhere.",
      ({"fields", "field"})  :
      "Vast fields of wheat wave gently in the breeze and can be seen "
      "expanding out in the distance.",
      ({"animal", "animals"})  :
      "Grazing animals that live in the pastures keep the plant "
      "growth to minimum.",
      ({"fence", "fences"})  :
      "Fences surround the pastures and confine the animals.",
      "grass"  :
      "The grass is kept short by grazing animals.",
      ({"hill", "hills"})  :
      "The halflings have made burrows in the ancient hills.",
    ]) );
    SetItemAdjectives( ([
      "wheat"    :  ({"golden", "waving"}),
      "burrow"  :  ({"hillside", "underground"}),
      "field"    :  ({"vast", "wheat"}),
      "pasture"    :  ({"green", "grazing"}),
      "hill"    :  ({"ancient", "steep"}),
      "grass"    :   ({"short", "green"}),
      "animal"    :  ({"grazing"}),
    ]) );
    SetSmell( ([
      "default"  :  "The aroma of food comes from all directions.",
    ]) );
    SetListen( ([
      "default"  :  "The air is filled with aimless chatter.",
    ]) );
    SetInventory(([
       NPCS + "/half" : 4 
    ]));
    SetExits( ([
      "northeast"  :  ROOMS + "/stream.c",
      "northwest"  :  ROOMS + "/village2.c",
    ]) );
}
