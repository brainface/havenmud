#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(50);
  SetShort("the Hall of Magicks");
  SetLong("Light flickers off the stone walls of this large hall.  On "
          "one of the walls hangs an ancient banner that draws the "
          "attention of any who enter. A haze hangs high in the rafters. "
          "All around the room are scrolls sitting on shelves of various "
          "size.");
  SetItems( ([
    "light" : "No discernable source can be found for the light, however "
              "shadows are cast about the room from the invisible source.",
    ({"stone walls","walls","stone","wall"}) :
              "The walls have been worn smooth almost glossy in appearance.",
    "floor" : "Depressions mar the floor where countless feet have tread.  "
              "Worn paths lead from the central depression to each of the "
              "exits.",
    ({"ancient banner", "banner"}) :
          "A dangerous energy radiates from the rune covered banner.",
    ({"runes","rune"}) : "As you stare at the runes, they seem to come "
              "together and form the words, 'Ware the non-arcane, they "
              "are jealous of our power and seek our death.'",
    "haze" : "The haze is not so much a mist as it is a distortion of "
             "visible light.",
    ({ "scroll", "scrolls" }) : "The scrolls are in positions all over "
             "the hall.  Some look valuable, some less so.",
    ({ "shelf", "shelves" }) : "The shelves serve primarily to hold scrolls.",
    ]) );
  SetSmell( ([
    "default" : "The room has a smoky smell of incense and oils.",
    ]) );
  SetListen( ([
    "default" : "Hushed whispers gently resonate within the hall.",
    ]) );
  SetInventory( ([ LLORYK + "npc/feckel" : 1,
                   LLORYK + "npc/gantius" : 1,
                   LLORYK + "npc/tandemor" : 1,
                   ]) );
  AddExit("out", LLORYK + "room/hb2");
}
