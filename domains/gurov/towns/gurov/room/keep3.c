#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "east" : GUROV_ROOM "keep2",
    ]) );
  SetInventory( ([
    GUROV_NPC "prince" : 1,
    GUROV_NPC "prince_guard" : 2,
    ]) );
  SetShort("the Throne Room of the Prince of Gurov");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong(
    "The Prince's Throne room is opulent and yet spartan at the same "
    "time. Gilded tapestries show the history of the Prince's ancestors, "
    "and murals depicting battles long past are painted on full walls. "
    "The walls themselves seem to be made of the same grey stone that is "
    "so prevalent throughout the town, and the floor is merely a well-"
    "swept version of the same stone. Off to the east, the hall opens "
    "into a main reception hall for visitors to the keep."
    );
  SetListen("A magical source of music plays martial themes in the background.");
  SetSmell("The throne room is remarkably free of dust.");
  SetItems( ([
    ({ "tapestry", "tapestries" }) : "The tapestries show the history of the "
          "Princes of Gurov.",
    ({ "mural", "murals" }) : "The murals are pictures that depict scenes of "
          "battle from long ago.",
    ]) );
}