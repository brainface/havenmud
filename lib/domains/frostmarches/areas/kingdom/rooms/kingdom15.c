
/* A room in the kingdom
   Elasandria 4/13/98
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
    "Sunlight filters haphazardly through the lush ceiling of leaves "
    "overhead. Soft, spongy moss in beautiful hues of blue and green "
    "cover the trees and blanket the ground. The trees give the "
    "impression of being an illusion by constantly shifting and "
    "changing."
  );
  SetNightLong(
    "Moonlight filters haphazardly through the lush ceiling of "
    "leaves overhead. The forest seems to glow with a faint inner "
    "light, hinting of enchantment. The trees give the impression "
    "of being an illusion by constantly shifting and changing."
  );
  SetItems( ([
    ({"moonlight","sunlight","ray","rays"}) : "Rays shine through the "
      "green canopy of leaves to fall on the forest floor.",
    ({"lush ceiling","ceiling","leaf","leaves","canopy"}) : "The leaves "
      "are large and form a thick green ceiling.",
    ({"soft moss","moss","blanket"}) : "The beautifully colored moss "
      "gives the forest a touch of cushiony comfort.",
    ({"ancient tree","tree","trees"}) : "The trees are obviously "
      "ancient due to their impressive size and are covered with moss.",
    ({"floor","ground"}) : "The ground is spongy to walk on due to the "
      "thick blanket of moss growing there.",
    ({"faint light","light"}) : "A mysterious light seems to come from "
      "within the trees, lighting the forest like a night-light.",
    ({"forest","area"}) : "The forest appears to have the uncanny ability "
      "to constantly change its appearance as if it were a mere illusion.",
  ]) );
  SetItemAdjectives( ([
    "soft moss" : ({"spongy","green","blue"}),
    "lush ceiling" : ({"thick","green"}),
    "faint light" : ({"mysterious","inner"}),
    "floor" : ({"forest","cushiony"}),
  ]) );
  SetSmell( ([
    "default" : "A damp, earthy smell lingers here.",
  ]) );
  SetListen( ([
    "default" : "The sound of gently rustling leaves can be heard.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "wolverine" : 2,
  ]) );
  SetExits( ([
    "south" : KINGDOM_ROOMS + "kingdom20",
    "north" : KINGDOM_ROOMS + "kingdom10",
    "west" : KINGDOM_ROOMS + "kingdom14",
    "southwest" : KINGDOM_ROOMS + "kingdom19",
    "southeast" : KINGDOM_ROOMS + "kingdom21",
  ]) );
}
