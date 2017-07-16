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
  SetShort("inside the belfry");
  SetLong(
    "The view from the top of the belfry is rather pleasant. The entire "
    "monastery is visible in all it's splendor. The main worship hall "
    "looks especially stunning, while the garden is a welcome change of "
    "color to the tones of the desert. The bell is attached to the roof of "
    "the building and could be operated from below, if there were a rope. "
    "The stone staircase leads back down to the entrance to the belfry."
  );
  SetItems( ([
  ({ "belfry" }) : (: GetLong :),
  ({ "bell" }) :
    "The bell hangs from the roof. ",
  ({ "staircase" }) :
    "The stone staircase leads down to the belfry entrance. ",
  ({ "view" }) :
    "The entire monastery is visible in all it's splendour. The main "
    "worship hall looks especially stunning, while the garden is a "
    "welcome change of color to the tones of the desert.",
  ({ "hall" }) :
    "The main worship hall is an impressive building.",
  ({ "garden", "tones" }) :
    "The garden looks very pretty, a welcome change from the desert.",
  ]) );
  SetItemAdjectives( ([
    "staircase" : ({ "stone" }),
    "hall" : ({ "worship", "main", "stunning" }),
    "view" : ({ "pleasant" }),
  ]) );
  SetInventory( ([
    AREA_NPC "bat" : 5,
  ]) );
  SetListen( ([
    "default" : "The sounds of deep chanting can be heard.",
  ]) );
  SetSmell( ([
    "default" : "The belfry smells a little damp. ",
  ]) );
  SetExits( ([
    "down" : AREA_ROOM "belfry",
  ]) );
}
