
/* A room in the kingdom
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
    "The forest meets the rocky shore of this quiet mountain lake. "
    "Brilliant specks of light reflect off of the water and little "
    "ripples dance across its surface. A few large rocks, half "
    "submerged, lie close to the shore."
  );
  SetNightLong(
    "The forest meets the rocky shore of this quiet mountain lake. "
    "The moon and stars shine softly down upon the shoreline, "
    "casting ominous shadows that remind the unwary of the dangers "
    "that lurk at night."
  );
  SetItems( ([
    ({"forest","tree","trees"}) : "The forest looks dense and "
      "intimidating in comparison to the tranquility of the lake.",
    ({"lake","water","surface"}) : "This lake is a beautifully scenic "
      "vision in its mirror-like clarity.",
    ({"shadow","shadows"}) : "These shadows create perfect places for "
      "trouble to hide to catch the unwary.",
    ({"mountain","mountains","FrostMarches"}) : "The mountains appear "
      "to stand guard over this peaceful little lake.",
    ({"rock","rocks"}) : "These large rocks are perfect for sunning on.",
    ({"wave","waves","ripple","ripples"}) : "These small waves are "
      "caused by the wind.",
    ({"shore","shoreline"}) : "The shoreline is rocky due to the "
      "mountainous terrain.",
    "terrain" : "It is mountainous and rocky.",
  ]) );
  SetSmell( ([
    "default" : "The smell of fresh air lingers here.",
  ]) );
  SetListen( ([
    "default" : "The sounds of waves gently lapping against the shore "
      "mingle with the rustling of waves.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "frog" : 2,
  ]) );
  SetExits( ([
    "west" : KINGDOM_ROOMS + "kingdom6",
    "east" : KINGDOM_ROOMS + "kingdom4",
    "south" : KINGDOM_ROOMS + "kingdom8",
    "southwest" : KINGDOM_ROOMS + "kingdom7",
  ]) );
}
