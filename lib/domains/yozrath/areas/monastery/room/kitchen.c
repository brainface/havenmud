// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include <domains.h>
#include "../monastery.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetShort("inside a small dining area and kitchen");
  SetLong(
    "Wooden tables are lined up in rows here with benches, clearly a "
    "place for the monks to have their meals. A small kitchen area is "
    "built into the eastern wall, where the meals are prepared. All manner "
    "of cooking utensils, pans and plates are stored on shelves. To the "
    "west, there is a stone archway that leads to the garden."
  );
  SetItems( ([
  ({ "tables", "benches" }) :
    "The tables and benches make a fine place for the monks to eat.",
  ({ "kitchen", "area", "wall" }) :
    "Meals for the monks are prepared in this kitchen area.",
  ({ "utensils", "pans", "plates", "shelves" }) :
    "Numerous cooking utensils are stacked on shelves for the preparation "
    "of meals.",
  ({ "archway" }) :
    "The stone archway to the west leads out to the garden.",
  ({ "garden" }) :
    "There is a beautiful garden beyond the western archway.",
  ]) );
  SetItemAdjectives( ([
    "tables" : ({ "wooden" }),
    "archway" : ({ "stone" }),
    "area" : ({ "small" }),
    "wall" : ({ "eastern" }),
    "utensils" : ({ "cooking" }),
  ]) );
  SetInventory( ([
    AREA_NPC "monk" : 1,
  ]) );
  SetInventory( ([
    AREA_NPC "cook" : 1,
  ]) );
  SetListen( ([
    "default" : "The sounds of deep chanting can be heard.",
  ]) );
  SetSmell( ([
    "default" : "The dining area smells of freshly baked bread and wine.",
  ]) );
  SetExits( ([
    "west" : AREA_ROOM "garden",
    "south" : AREA_ROOM "imam_room",
  ]) );
}
