#include <lib.h>
#include "path.h"
inherit LIB_ROOM;

static void create() {
	   room::create();
    SetShort("a makeshift stable");
    SetLong("This room appears to have been converted from a storage "
          "room to a makeshift stable.  When the orcs attacked the keep, "
          "the humans were forced to flee indoors with their livestock.  "
          "Unfortunately, only a few animals survived the first raid."
          "  A hallway leads back towards the center of the keep.");
    SetItems( ([
          ({ "livestock", "animals" }) :
          "A few sheep, cows, pigs and horses that survived the orcish raid "
          "are penned up in here.",
          ({ "hallway", "hall" }) :
          "The dark hallway leads back towards the center of the keep.",
          ({ "makeshift stable", "stable", "room" }) :
          (: GetLong :),
           ]) );
    SetExits( ([
          "west" : BEORN_ROOM + "hall2.c",
           ]) );
    SetObviousExits("west");
    SetInventory( ([
          BEORN_NPC + "cow.c" : 1,
          BEORN_NPC + "farmhand.c" : 1,
          BEORN_NPC + "sheep.c" : 1,
            ]) );
    SetClimate("indoors");
    SetAmbientLight(50);
    SetSmell( ([
          "default" : "It smells of hay and animal excrement.",
]) );
    SetListen( ([
          "default" : "The animals are making noise which shatters the "
          "painful silence that fills the rest of the keep.",
]) );
}
