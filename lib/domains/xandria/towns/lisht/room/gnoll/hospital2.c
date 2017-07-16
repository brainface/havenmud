//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("a quiet hospital");
  SetLong(
    "This room of the temple is less ostentatious, kept clean of "
    "dirt and debris by careful physicians. The walls are painted "
    "with historical figures, doctors helping their patients and "
    "symbols of the goddess Selket. Simple cots line the floors, "
    "and physicians tend to the many patients that lie upon them "
    "as best they can. The hospital leads on to the west, and the "
    "hypostyle hall of the grand temple stands in the east. "
  );
  SetItems( ([
    ({ "wall", "walls", "figures", "symbols" }) :
        "The walls are decorated with charms and symbols to help ease "
        "the pain of those who come here, and keep their minds off "
        "of death.",
    ({ "cot", "cots" }) :
        "The cots are simple mattresses covered with white linen.",
    ({ "floor", "mosaic", "tiles" }) :
        "The floor is a whirl of designs and aestheically laid out scenes "
        "of Lisht, Xandria, and Selket herself.",
    ({ "carvings", "scorpions", "snakes" }) :
        "The carvings are fashioned of many materials and are very lifelike.",
  ]) );
  SetSmell( ([
    "default" : "The air smells of the dying.",
  ]) );
  SetListen( ([
  "default" : "Occasionally, the patients moan softly."
  ]) );
  SetInventory( ([
    LISHT_NPC "doctor" :1,
    LISHT_NPC "patient2" :3,
  ]) );
  SetExits( ([
    "east" : "hospital1",
  ]) );
}
