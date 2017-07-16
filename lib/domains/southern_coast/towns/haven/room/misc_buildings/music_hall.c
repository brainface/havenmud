#include <lib.h>
#include <std.h>
#include "../../haven.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Hall of Musicians");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetInventory( ([
    STD_NPC + "minstrel" : 1,
    H_NPC   + "bard" : 1,
    H_NPC   + "bard_trainer" : 1,
    ]) );
  SetExits( ([
    "out" : H_ROOM "imperial_road/ir5",
    ]) );
  SetListen("Cheerful music echoes to the vaulted ceiling.");
  SetLong(
    "The Hall of Musicians is a large hall filled to capacity with seating "
    "for performances. A large stage sits at the north end of the Hall, and "
    "overhead a giant glass chandelier casts a magical glow down upon the "
    "hall. Vases sit in recessed sections of wall filled with freshly cut "
    "flowers."
    );
  SetItems( ([
    ({ "seat", "seats", "seating" }) : "The rosewood seats appear to be "
                                       "moderately comfortable.",
    ({ "chandelier" }) : "The chandelier is gigantic and glows with a magical light.",
    ({ "vase", "vases" }) : "The vases are filled with freshly cut flowers.",
    ({ "flower", "flowers" }) : "The flowers are freshly cut.",
    ({ "stage" }) : "This large wooden stage sits at the north end of the "
    "Hall of Musicians.",
    ]) );
  SetItemAdjectives( ([
    "chandelier" : ({ "giant", "magic", "gigantic", "magical", "glass" }),
    "flower"     : ({ "fresh", "freshly", "cut" }),
    "stage" : ({ "large", "wooden", "north", "performance" }),
    ]) );
  SetSmell( ([
    "default" : "Fresh cut flowers make the Hall of Musicians smell wonderful.",
    "flower"  : "The flowers are freshly cut and smell wonderful.",
    ]) );
}
  
