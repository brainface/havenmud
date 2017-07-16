#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  ::create();
  SetShort("Teras' bedroom");
  SetLong("The unrelieved monotone of the grey walls surrounds on every "
          "side, unbroken, a testament to tedium. The room is completely "
          "empty, except for one item: a bed.  As compared to the other "
          "parts of Teras' laboratory, this bedroom is free from all "
          "clutter; it is exquisitely clean.  Its bareness signifies that "
          "the room is for one purpose and one purpose only: sleep. The "
          "laboratory is nearby, opening up to the north of the bedroom.");
  SetSmell( ([
    "default" :
      "Somehow, this room is completely absent of any odors."
  ]) );
  SetListen( ([
    "default" :
      "Not a thing can be heard."
  ]) );
  SetClimate("indoors");
  SetItems( ([
    ({"teras bedroom, bedroom, room"}) :
      (: GetLong() :),
    ({"grey walls","grey wall","bare walls","bare wall","walls","wall"}) :
      "The walls are completely bare.",
    ({"neatly made bed","neat bed","bed","center of the room","center"}) :
      "The bed is neatly made and sits in the center of the room",
    ({"teras laboratory","teras lab","nearby laboratory", "nearby lab",
      "laboratory","lab","north"}) :
      "The laboratory opens to the north.",
  ]) );
  SetAmbientLight(38);
  SetExits( ([
    "north" : L_ROOM "/south_lab",
  ]) );
}
