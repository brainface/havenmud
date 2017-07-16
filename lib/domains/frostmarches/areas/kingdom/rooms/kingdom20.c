
/*  A room in the kingdom
    Elasandria 4/13/98
*/
#include <lib.h>
#include "../kingdom.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a dense forest");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetDayLong(
    "Bright rays of sunlight shine through the lush canopy of leaves "
    "overhead. Soft, spongy moss in various shades of blues and "
    "greens cover the trees and blanket the ground. The trees seem "
    "to shift and change as if they were an illusion."
  );
  SetNightLong(
    "Bright rays of moonlight shine through the lush canopy of "
    "leaves overhead. The forest seems to glow with a faint, inner "
    "light, hinting at enchantment. The trees seem to shift and  " 
    "change as if they were an illusion."
  );
  SetItems( ([
    ({"bright rays","ray","rays","sunlight","moonlight"}) : "The rays "
      "filter down through the thick canopy of leaves.",
    ({"lush canopy","canopy","leaf","leaves","ceiling"}) : "The leaves "
      "are large and form a thick green ceiling.",
    ({"soft moss","moss","blanket"}) : "The beautifully colored moss "
      "gives the forest a touch of cushiony comfort.",
    ({"ancient tree","tree","trees"}) : "The trees are obviously ancient "
      "due to their impressive size and are covered with moss.",
    ({"floor","ground"}) : "The ground is spongy to walk on due to the "
      "thick blanket of moss growing there.",
    ({"faint light","light"}) : "A mysterious light seems to come from "
      "within the trees, lighting the forest like a night-light.",
    ({"forest","area"}) : "The forest appears to have the uncanny ability "
      "to shift and change itself as if it were a mere illusion.",
  ]) );
  SetItemAdjectives( ([
    "faint light" : ({"mysterious","inner"}),
    "lush canopy" : ({"thick","green"}),
    "soft moss" : ({"spongy","green","blue"}),
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
    "south" : FROSTMARCHES_AREAS + "wood/rooms/wood1",
    "west" : KINGDOM_ROOMS + "kingdom19",
    "northwest" : KINGDOM_ROOMS + "kingdom14",
    "north" : KINGDOM_ROOMS + "kingdom15",
    "east" : KINGDOM_ROOMS + "kingdom21",
  ]) );
}
