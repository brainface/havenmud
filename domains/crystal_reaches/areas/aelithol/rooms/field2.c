#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("among some fields");
    SetDomain("Crystal Reaches");
    SetLong(
      "Some of the adjacent fields have been turned into grazing "
      "lands. Various animals look like dots on the distant hills "
      "as they graze. The pastures are green and the grass is "
      "kept short by the consistant grazing of animals. The wheat "
      "fields are fenced off from the animals in order to prevent "
      "the animals from destroying the fields."
    );
    SetItems( ([
      ({"pasture", "pastures"})  :
      "The pastures are green and the grass is kept short by "
      "the presence of various grazing animals.",
      "wheat"  :
      "Golden wheat waves gently in the breeze.",
      ({"hill", "hills"})  :
      "The hills have been covered with pastures and fields.",
      ({"animal", "animals", "dots", "dot"})  :
      "Grazing animals that live in the pastures keep the plant "
      "growth to minimum.",
      ({"fence", "fences"})  :
      "Fences surround the pastures and confine the animals.",
      "grass"  :
      "The grass is kept short by grazing animals.",
      ({"houses", "house"})  :
      "The occasional house that belongs to a farmer can be seen "
      "on the hills.",
      ({"wave", "waves"})  :
      "Waves made by the wheat moving in the wind go across "
      "the fields.",
     ({"fields", "field"})  :
      "Vast fields of wheat wave gently in the breeze and can be seen "
      "expanding out to the west.",
    ]) );
    SetInventory(([
        NPCS + "/cow" : 1 
    ]));

    SetItemAdjectives( ([
      "wheat"    :  ({"golden", "waving"}),
      "wave"    :  "small",
      "houses"    :  ({"farming", "distant"}),
      "grass"    :   ({"short", "green"}),
      "field"    :  ({"vast", "wheat"}),
      "animal"    :  ({"grazing"}),
      "pastures"    :  ({"green", "grazing"}),
    ]) );
    SetSmell( ([
      "default"  :  "The pastures give the area an organic scent.",
    ]) );
    SetListen( ([
      "default"  :  "The sounds of livestock come from the pastures.",
    ]) );
    SetExits( ([
      "east"  :  ROOMS + "/field.c",
      "west"  :  ROOMS + "/stream.c",
    ]) );
}
