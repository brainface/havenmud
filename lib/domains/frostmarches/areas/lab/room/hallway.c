#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  ::create();
  SetShort("a hallway");
  SetLong("The details of this hallway are hard to distinguish as it is "
          "characterized by a strange lack of light. The candles that line "
          "the walls seem to be giving off more than enough light and yet the "
          "hallway maintains a darkened aura. It is as if the numerous "
          "shadows the candles cast on the ground actively seek to reduce the "
          "ambience around them. A number of lab benches can be made out in "
          "the light coming from the east. The hallway leads westward to a "
          "foyer.");
  SetSmell( ([
    "default" : "A pungent odor floats in from the east."
  ]) );
  SetListen( ([
    "default" :
      "The scurry of little critters is very obvious in the otherwise "
      "dead silence of the hallway."
  ]) );
  SetClimate("indoors");
  SetItems( ([
    ({"details","hallway"}) :
      (: GetLong() :),
    ({"candle","candles","wall","walls"}) :
      "The walls are lined by a number of candles that do a strangely poor "
      "job of lighting the hallway.",
    ({"numerous shadows","shadows","shadow","ground"}) :
      "The light of the candles cast numerous shadows on the ground.",
    ({"bedroom","passage to the south","passage","south"}) :
      "The bedroom to the south is not very clearly visible from here.",
    ({"foyer","westward"}) :
      "The foyer to the west is not very clearly visible from here.",
    ({"laboratory benches","lab benches","benches",
      "light from the east","east","eastward"}) :
      "The lab benches to the east are not very clearly visible from here.",
  ]) );
  SetAmbientLight(27);
  SetExits( ([
    "east" : L_ROOM "/south_lab",
    "west" : L_ROOM "/foyer",
  ]) );
  SetInventory( ([
    L_NPC "/rat" : random(1) + 1,
    L_NPC "/roach" : random(1) + 1,
  ]) );
}
