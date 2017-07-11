
/* A room in the kingdom
   Elasandria 4/9/98
*/
#include <lib.h>
#include "../kingdom.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a dense forest");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetDayLong(
    "Dancing rays of sunlight filter throught the lush ceiling of "
    "leaves overhead. Soft, spongy moss in various shades of blues "
    "and greens blanket the trees and ground. The rumors of faerie "
    "mischief in the area may explain why the forest seems to "
    "constantly change like an illusion, easily confusing "
    "travellers."
  );
  SetNightLong(
    "Subtle rays of moonlight drift down through the ceiling of "
    "leaves overhead. The forest is enchantingly beautiful, "
    "seemingly glowing from an unnatural inner light source. The "
    "illusion-like way the forest seems to shift and change may "
    "be due to the mischief of faeries."
  );
  SetItems( ([
    ({"leaves","leaf","ceiling"}) : "The leaves are large and form a "
      "thick green ceiling above the forest floor.",
    ({"blanket","moss"}) : "The beautifully colored moss gives the "
      "forest a touch of cusiony comfort.",
    ({"tree","trees"}) : "The trees are obviously ancient due to "
      "the thick blanket of moss growing there.",
    ({"floor","ground"}) : "The ground is spongy to walk on due to "
      "the thick blanket of moss growing there.",
    ({"forest","area"}) : "The forest appears to have the uncanny "
      "ability to change and shift like an illusion.",
    "light" : "A mysterious light seems to come from within the trees, "
      "lighting the forest like a night-light.",
    ({"moonlight","sunlight","ray","rays"}) : "Rays gently shine down "
      "to the forest floor through the leaves overhead.",
  ]) );
  SetSmell( ([
    "default" : "A damp, earthy smell lingers here.",
  ]) );
  SetListen( ([
    "default" : "The sound of gently rustling leaves can be heard.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "wolverine" : 1,
  ]) );
  SetExits( ([
    "west" : KINGDOM_ROOMS + "kingdom7",
    "northwest" : KINGDOM_ROOMS + "kingdom6",
    "north" : KINGDOM_ROOMS + "kingdom3",
    "northeast" : KINGDOM_ROOMS + "kingdom4",
    "southeast" : KINGDOM_ROOMS + "kingdom14",
    "south" : KINGDOM_ROOMS + "kingdom13",
  ]) );
}
