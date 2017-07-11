
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
  SetLong(
    "Sunlight filters haphazardly through the lush ceiling of leaves "
    "overhead. Soft, spongy moss in various shades of blues and greens "
    "cover the trees and blanket the ground. The rumors of faerie "
    "mischief in the area may explain why the forest seems to constantly "
    "shift."
  );
  SetNightLong(
    "Moonlight filters haphazardly through the lush ceiling of "
    "leaves overhead. The forest seems to glow with a fain inner "
    "light, hinting at enchantment. The rumors of faerie mischief "
    "in the area may explain why the forest seems to constantly shift."
  );
  SetItems( ([
    ({"ceiling","green ceiling","leaf","leaves"}) : "The leaves are "        
      "large and form a thick green ceiling above the forest floor.",
    ({"blanket","moss"}) : "The beautifully colored moss gives the "
      "forest a touch of cusiony comfort.",
    ({"tree","trees"}) : "The trees are obviously ancient due to their "
      "impressive size and are covered by moss.",
    ({"floor","ground"}) : "The ground is spongy to walk on due to the "
      "thick blanket of moss growing there.",
    ({"forest","area"}) : "The forest appears to have the uncanny "
      "ability to shift and change like an illusion.",
    "light" : "A mysterious light seems to come from within the trees "
      "lighting the forest like a night light.",
  ]) );
  SetSmell( ([
    "default" : "A damp, earthy smell lingers here.",
  ]) );
  SetListen( ([
    "default" : "The sound of gently rustling leaves can be heard.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "satyr" : 1,
  ]) );
  SetExits( ([
    "north" : KINGDOM_ROOMS + "kingdom1",
    "northeast" : KINGDOM_ROOMS + "kingdom6",
    "east" : KINGDOM_ROOMS + "kingdom7",
  ]) );
}
