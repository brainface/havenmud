
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
    "The rumors of faerie magic the the area may explain why the "
    "forest gives the illusion of constantly changing and shifting "
    "around. Sunlight filters haphazardly through the leafy ceiling "
    "overhead. Velvet-soft moss in various shades of greens and "
    "blues cover the trees and blanket the ground."
  );
  SetNightLong(
    "The rumors of faerie magic in the area may explain why the "
    "forest gives the illusion of constantly changing and "
    "shifting around. Moonlight filters through the leafy ceiling "
    "overhead in soft streaming rays. The forest seems to glow "
    "with a faint inner light, hinting of enchantment."
  );
  SetItems( ([
    ({"forest","area"}) : "The forest appears to have the uncanny "
      "ability to continuously shift around like an illusion.",
    ({"leaf","leaves","ceiling"}) : "The leaves are large and form a "
      "thick green ceiling above the forest floor.",
    ({"moss","blanket"}) : "The beautifully colored moss gives the "
      "forest a touch of cusiony comfort.",
    ({"tree","trees"}) : "The trees are obviously ancient due to "
       "their impressive size and are covered with moss.",
    ({"floor","ground"}) : "The ground is spongy to walk on due to "
      "the thick blanket of moss growing there.",
    ({"moonlight","sunlight","ray","rays"}) : "The rays filter down "
      "through the leafy ceiling to the forest floor.",
    "light" : "A mysterious light seems to come from within the trees, "
      "lighting the forest like a night-light.",
  ]) );
  SetSmell( ([
    "default" : "A damp, earthy smell lingers here.",
  ]) );
  SetListen( ([
    "default" : "The sound of gently rustling leaves can be heard.",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
    "northwest" : KINGDOM_ROOMS + "kingdom8",
    "northeast" : KINGDOM_ROOMS + "kingdom10",
    "east" : KINGDOM_ROOMS + "kingdom15",
    "west" : KINGDOM_ROOMS + "kingdom13",
    "south" : KINGDOM_ROOMS + "kingdom19",
    "southeast" : KINGDOM_ROOMS + "kingdom20",
    "southwest" : KINGDOM_ROOMS + "kingdom18",
  ]) );
}
