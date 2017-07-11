/*  Main Path through the goblin village.
 *  Connects the village to the roads.
 */
#include <domains.h>
#include <lib.h>
#define ROAD_PATH  SOUTHERN_COAST_VIRTUAL "havenroad/-32,0"
#include "../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a grassy plain leading to Kresh");
  SetExits( ([
      "east" : GOBLIN_ROOM + "e_1",
     "south" : GOBLIN_ROOM + "m_2",
    ]) );
  AddExit("north", ROAD_PATH);
  SetInventory( ([
      GOBLIN_NPC + "little" : 2,
      ]) );
  SetLong(
    "A large and open grassy plain extends to the south. Around here, the plain "
    "seems to have be become home to a small tent village of nomads. A path leads "
    "back to the Imperial Road to the north. To the east lies a rather durable "
    "looking tent that seems to have a significant traffic to it. Campfires "
    "and other village staples are scattered around the grass with almost "
    "complete abandon."
    );
  SetItems( ([
    "tent" : "The tent lies farther off to the east.",
    ({ "fire", "campfire", "fires", "campfires" }) : "The campfires are in "
             "all varieties from new to obviously old.",
    ]) );
  SetSmell( ([
    "default" : "The village smells of campfires mixed with horsedung.",
    ]) );
  SetListen( ([
    "default" : "Random grunting carries on the rare burst of wind.",
    ]) );             
}
