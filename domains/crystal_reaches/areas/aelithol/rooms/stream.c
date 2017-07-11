#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("near a stream");
    SetDomain("Crystal Reaches");
    SetLong(
      "A small stream winds its way between two hills of wheat. "
      "Green plants have grown to be tall and nearly conceal the stream's "
      "very existance. Houses and large farms "
      "have been built throughout this region and faint smoke "
      "rises from their individual chimneys into the cold sky. "
      "The many fields of wheat go in all directions from here."
    );
    SetItems( ([
      ({"pasture", "pastures"})  :
      "The pastures are green and the grass is kept short by "
      "the presence of various grazing animals.",
      "wheat"  :
      "Golden wheat waves gently in the breeze.",
      ({"animal", "animals"})  :
      "Grazing animals that live in the pastures keep the plant "
      "growth to minimum.",
      "smoke"  :
      "Smoke rises up from distant chimneys.",
      ({"hill", "hills"})  :
      "Two hills covered in wheat hide the stream from distant observers.",
      ({"houses", "house", "farm", "farms"})  :
      "Houses and large farms are spread throughout this area.",
      ({"chimney", "chimneys"})   :
      "Even though the chimneys cannot be seen at this distance, "
      "the smoke shows them to be present.",
      ({"fence", "fences"})  :
      "Fences surround the pastures and confine the animals.",
      ({"wave", "waves"})  :
      "Waves made by the wheat moving in the wind go "
      "across the fields.",
      ({"fields", "field"})  :
      "Vast fields of wheat wave gently in the breeze and can be seen "
      "expanding out to the west.",
      "stream"  :
       "The stream flows swiftly through plants that nearly conceal the "
       "streams existance.",
       ({"plant", "plants"})  :
       "Green plants grow near the stream and have come to conceal the "
       "stream in their great number.",
    ]) );
    SetItemAdjectives( ([
      "wheat"    :  ({"golden", "waving"}),
      "chimney"  :  "distant",
      "house"   :  ({"distant", "large"}),
      "animal"   :  "grazing",
      "smoke"   :   "rising",
      "wave"    :  "small",
      "field"    :  ({"vast", "wheat"}),
      "pasture"    :  ({"green", "grazing"}),
      "stream"    :  ({"swift", "concealed"}),
      "plant"    :  ({"green", "tall"}),
    ]) );
    SetSmell( ([
      "default"  :  "Neaby plants exude a pleasant scent.",
    ]) );
    SetListen( ([
      "default"  :  "A village can be heard to the southwest.",
    ]) );
    SetExits( ([
      "east"  :  ROOMS + "/field2.c",
      "southwest"  :  ROOMS + "/village.c",
    ]) );
}
