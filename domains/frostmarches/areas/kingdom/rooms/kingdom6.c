/* a room in the kingdom
   Elasandria 4/8/98
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
    "The forest comes to an abrupt halt as it meets the rocky "
    "shoreline of a hidden lake nestled at the base of the "
    "FrostMarches. The sunlight reflects and dances across the "
    "ripples of the water in brilliant specks of light. A few large "
    "rocks, half submerged, lie close to the shore."
  );
  SetNightLong(
    "The forest comes to an abrupt halt as it meets the rocky "
    "shoreline of a hidden lake nestled at the base of the "
    "FrostMarches. The moonlight reflects softly off of the still "
    "black water. The trees and rocks cast ominous shadows that "
    "remind the unwary of the dangers that lurk at night."
  );
  SetItems( ([
    ({"forest","tree","trees"}) : "The forest looks dense and "
      "intimidating in comparison to the tranquility of the lake.",
    ({"lake","water"}) : "This lake is a beautifully scenic vision in "
      "its mirror-like clarity.",
    ({"mountain","mountains","FrostMarches"}) : "The mountains appear "
      "to stand guard over this peaceful little lake that is nestled "
      "between their bases.",
    ({"ripple","ripples","wave","waves"}) : "These small waves are caused "
      "by the wind.",
    ({"shore","shoreline"}) : "The shoreline is rocky due to the "
      "mountainous terrain.",
    ({"rock","rocks"}) : "These large rocks are perfect for sunning on.",
    ({"shadow","shadows"}) : "These shadows create perfect places for "
      "trouble to hide to catch the unwary.",
    ({"ray","rays","moonlight","sunlight"}) : "These rays reflect off of "
      "the water.",
    "terrain" : "It is mountainous and rocky.",
    "light" : "Bright specks of light reflect off the water.",
  ]) );
  SetSmell( ([
    "default" : "The smell of fresh air lingers in the air."
  ]) );
  SetListen( ([
    "default" : "The sounds of the waves gently lapping against the shore "
      "mingle with the rustling of leaves.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "nymph" : 2,
  ]) );
  SetExits( ([
    "east" : KINGDOM_ROOMS + "kingdom3",
    "west" : KINGDOM_ROOMS + "kingdom1",
    "south" : KINGDOM_ROOMS + "kingdom7",
    "southeast" : KINGDOM_ROOMS + "kingdom8",
    "southwest" : KINGDOM_ROOMS + "kingdom2",
  ]) );
}
