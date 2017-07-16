
#include "../glim.h"
#include <domains.h>
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(45);
  SetShort("an annex of the Kylin Church");
  SetLong("This is an annex of the Kylin Church of Glistendin. "
    "It seems rather small, but enough to house a single healer. "
    "Though mundane and rather unremarkable, every stone "
    "surface seems to radiate a holy aura that brings comfort "
    "to those who have answered to call of their people and been "
    "wounded in battle. A staircase leads up to the church of "
    "Kylin.");
   SetItems( ([
    ({"stair", "stairs", "staircase", "church of kylin", "church"}) : 
      "A stone staircase leads back up to the Church of Kylin.",
    ({"surface", "surfaces", "stone surface", "stone surfaces"}) :
      "Every stone surface seems to hold the blessing of the dwarven "
      "gods.",
    ]) );
    SetExits( ([
    "up" : AVERATH_ISLAND "-8,-4,0",
          ]) );
  SetListen( ([
    "default" : "It is completely silent.",
    ]) );
  SetSmell( ([
    "default" : "The scent of herbs livens the room.",
    ]) );
  SetInventory( ([
    G_NPC "healer" : 1,
   ]) );
}
