
/* A room in the kingdom
   Elasandria 4/10/98
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
    "The forest seems to be an illusion with the peculiar way it "
    "appears to constantly change. Sunlight filters through the "
    "leafy ceiling overhead to shine down upon the forest floor. "
    "Soft, spongy moss of various shades of blues and greens "
    "cover the ground."
  );
  SetNightLong(
    "The forest seems to be an illusion with the peculiar way it "
    "appears to constantly change. Moonlight filters through the "
    "leafy ceiling overhead to shine down upon the forest floor. "
    "A most peculiar glow, seeming to come from within the "
    "trees, lights the forest."
  );
  SetItems( ([
    ({"moonlight","sunlight","ray","rays"}) : "These rays filter "
      "through the leafy ceiling to shine on the forest floor.",
    ({"moss","blanket"}) : "The beautifully colered moss gives the "
      "forest a touch of a touch of cushiony comfort.",
    ({"tree","trees"}) : "The trees are obviously ancient due "
      "to their impressive size and are covered with moss.",
    ({"floor","ground"}) : "The ground is spongy to walk on due to "
      "the thick blanket of moss growing there.",
    ({"forest","area"}) : "The forest appears to have the uncanny "
      "ability to change and shift as if it were an illusion.",
    ({"light","glow"}) : "A mysterious light seems to come from "
      "within the tree, lighting the forest like a night-light.",
    ({"ceiling","leaf","leaves"}) : "The leaves are large and form a "
      "thick green ceiling above the forest floor.",
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
    "west" : KINGDOM_ROOMS + "kingdom17",
    "north" : KINGDOM_ROOMS + "kingdom13",
    "northeast" : KINGDOM_ROOMS + "kingdom14",
    "east" : KINGDOM_ROOMS + "kingdom19",
  ]) );
}
