
/* A small room in the kingdom
   Elasandria 4/9/98
*/
#include <lib.h>
#include "../kingdom.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a rocky shore");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetDayLong(
    "The FrostMarches hover protectively over one side of this small "
    "lake. On the other side, the forest comes to an abrupt halt as "
    "it meets the rocky shoreline of the lake. A few large rocks, "
    "half submerged, lie close to the shore."
  );
  SetNightLong(
    "The FrostMarches hover protectively over one side of this "
    "small lake. On the other side, the forest comes to an abrupt "
    "halt as it meets the rocky shoreline of the lake. The "
    "moonlight reflects softly off of the still black water."
  );
  SetItems( ([
    ({"forest","tree","trees"}) : "The forest looks dense and "
      "intimidating in comparison to the tranquility of the lake.",
    ({"lake","water"}) : "This lake is a beautifully scenic vision in "
      "its mirror-like clairity.",
    ({"moonlight","light"}) : "The moonlight casts a soft light upon "
      "the lake.",
    ({"mountain","mountains","FrostMarches"}) : "The mountains appear "
      "to stand guard over this peaceful little lake.",
    ({"rock","rocks"}) : "These large rocks are perfect for sunning on.",
    ({"wave","waves","ripple","ripples"}) : "These small waves are "
      "caused by the wind.",
    ({"shore","shoreline"}) : "The shore is rocky due to the mountainous "
      "terrain.",
    "terrain" : "It is mountainous and rocky.",
  ]) );
  SetSmell( ([
    "default" : "The smell of fresh air lingers here.",
  ]) );
  SetListen( ([
    "default" : "The sounds of the waves gently lapping against the "
       "shore mingle with the rustling of waves.",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
    "west" : KINGDOM_ROOMS + "kingdom3",
    "southwest" : KINGDOM_ROOMS + "kingdom8",
  ]) );
}
