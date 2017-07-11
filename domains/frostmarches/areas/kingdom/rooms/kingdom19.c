
/* A room in the kingdom
   Elasandria 4/13/98
*/
#include <lib.h>
#include "../kingdom.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a dense wood");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetDayLong(
    "Dancing rays of sunlight filter through the leafy canopy above "
    "to fall upon the cushiony forest floor. Soft, spongy moss "
    "in various shades of blues and greens blanket the ground and "
    "trees. The rumors of faerie mischief in the area may explain "
    "why the forest seems to constantly change and shift."
  );
  SetNightLong(
    "Dancing rays of moonlight filter through the leafy canopy "
    "above to fall softly upon the ground. The forest seems to "
    "glow with a faint inner light, hinting at enchantment. The "
    "rumors of faerie mischief in the area may explain why the "
    "forest seems to constantly shift and change."
  );
  SetItems( ([
    ({"dancing rays","ray","rays","sunlight","moonlight"}) : "The rays "
      "shine down upon the cushiony ground.",
    ({"floor","ground"}) : "The ground is spongy to walk on due to "
      "the thick blanket of moss growing there.",
    ({"soft moss","moss","blanket"}) : "The beautifully colored moss "
      "gives the forest a touch of cusiony comfort.",
    ({"forest","area"}) : "The forest appears to have the uncanny "
      "ability to constantly change as if it were an illusion.",
    ({"faint light","light"}) : "A mysterious light seems to come from "
      "within the trees, lighting the forest like a night-light.",
    ({"ancient tree","tree","trees"}) : "The trees are obviously " 
      "ancient due to their impressive size and are covered by moss.",
    ({"leafy canopy","canopy","leaf","leaves","ceiling"}) : "The leaves "
      "are large and form a thick green ceiling above the forest floor.",
  ]) );
  SetItemAdjectives( ([
    "floor" : ({"forest","cushiony"}),
    "faint light" : "inner",
    "soft moss" : ({"spongy","blue","green"}),
  ]) );
  SetSmell( ([
    "default" : "A damp, earthy smell lingers here.",
  ]) );
  SetListen( ([
    "default" : "The sound of gently rustling leaves can be heard.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "hunter" : 1,
  ]) );
  SetExits( ([
    "west" : KINGDOM_ROOMS + "kingdom18",
    "northwest" : KINGDOM_ROOMS + "kingdom13",
    "north" : KINGDOM_ROOMS + "kingdom14",
    "northeast" : KINGDOM_ROOMS + "kingdom15",
    "east" : KINGDOM_ROOMS + "kingdom20",
  ]) );
}
