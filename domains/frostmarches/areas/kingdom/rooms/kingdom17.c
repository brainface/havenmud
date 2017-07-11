
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
    "Dancing rays of sunlight filter through the canopy of leaves "
    "overhead down to the moist forest floor. Velvety softy moss in "
    "beautiful hues of green and blue blanket the trees and ground. "
    "The illusion like way the forest seems to shift and change "
    "could be a result of faerie mischief. A thick wall of greenery "
    "to the west looks intriguing."
  );
  SetNightLong(
    "Dancing rays of moonlight filter through the canopy of leaves "
    "overhead down to the moist forest floor. A strange, faint "
    "inner light seems to come from deep within the forest itself, " 
    "hinting of enchantment. The illusion like way the forest "
    "seems to shift and change could be a result of faerie "
    "mischief. A thick wall of greenery to the west looks "
    "intriguing."
  );
  SetItems( ([
    ({"moonlight","sunlight","ray","rays"}) : "These rays filter "
      "through the leafy ceiling down to the forest floor.",
    ({"canopy","ceiling","leaf","leaves"}) : "The leaves are large and "
      "form a thick green ceiling above the forest floor.",
    ({"blanket","moss"}) : "The beautifully colored moss gives the "
      "forest a touch of cusiony comfort.",
    ({"tree","trees"}) : "The trees are obviously ancient due to their "
      "impressive size and are covered by moss.",
    ({"floor","ground"}) : "The ground is spongy to walk on due to the "
      "thick blanket of moss growing there.",
    ({"forest","area"}) : "The forest appears to have the uncanny "
       "ability to change and shift itself as if it were an illusion.",
    ({"light","glow"}) : "A mysterious light seems to come from within "
       "trees, lighting the forest like a night-light.",
    ({"thick wall","wall","greenery"}) : "Upon closer inspection, the "
       "dense greenery looks passable.",
  ]) );
  SetSmell( ([
    "default" : "A damp, earthy smell lingers here.",
  ]) );
  SetListen( ([
    "default" : "The sound of gently rustling leaves can be heard.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "fox" : 1,
  ]) );
  SetExits( ([
    "east" : KINGDOM_ROOMS + "kingdom18",
    "northeast" : KINGDOM_ROOMS + "kingdom13",
    "west" : KINGDOM_ROOMS + "kingdom16",
  ]) );
}
