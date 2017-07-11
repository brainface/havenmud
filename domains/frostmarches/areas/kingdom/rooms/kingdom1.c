/* A small part of the kingdom
    Elasandria 4/8/98
*/
#include <lib.h>
#include "../kingdom.h"
inherit LIB_FISHING;

static void create() {
  ::create();
  SetShort("a rocky shore");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetDayLong(
    "The forest comes to an abrupt halt as it meets the rocky "
    "shoreline of a hidden lake nestled at the base of the "
    "FrostMarches. The sunlight reflects and dances across the "
    "ripples of the water in brilliant specks of light. A few large "
    "rocks, half submerged, lie close to the shoreline."
  );
  SetNightLong(
    "The forest comes to an abrupt halt as it meets the rocky "
    "shoreline of a hidden lake nestled at the base of the Frost"
    "Marches. The moonlight reflects softly off of the still black "
    "water. The trees and rocks cast ominous shadows that remind "
    "unwary travellers of the dangers that lurk at night."
  ); 
  SetItems( ([
    ({"forest","tree","trees"}) : "The forest looks dense and "
      "intimidating in comparison to the tranquility of the lake.",
    ({"lake","water"}) : "This lake is a beautifully scenic vision " 
      "in its mirror-like clarity.",
    ({"mountain","mountains","FrostMarches"}) : "The mountains appear "
      "to stand guard over this peaceful little lake that is nestled "
      "between their bases.",
    ({"wave","waves","ripple","ripples"}) : "These small waves are "
    	"caused by the wind.",
    ({"shore","shoreline"}) : "The lakeshore is rocky due to the "
      "mountainous terrain.",
    ({"rock","rocks"}) : "These large rocks are perfect for sunning on.",
    ({"shadow","shadows"}) : "These shadows create perfect places for "
      "trouble to hide to catch the unwary.",
    ({"sunlight","moonlight","ray","rays"}) : "The rays shine down upon "
      "the lake.",
    "terrain" : "It is mountainous and rocky.",
    "light" : "Bright specks of light reflect off of the water.",
  ]) );
  SetSmell( ([
    "default" : "The smell of fresh air lingers in the air.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "frog" : 2, 
  ]) );
  SetExits( ([
    "south" : KINGDOM_ROOMS + "kingdom2",
    "east" : KINGDOM_ROOMS + "kingdom6",
    "southeast" : KINGDOM_ROOMS + "kingdom7",
  ]) );
  SetFish( ([
	"/std/fish/trout" : 30,
   ]) );
}
