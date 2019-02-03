// Peat Bog
// Francis
// January 2005

#include <lib.h>
#include <domains.h>
#include "../bog.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(40);
  SetClimate("sub-arctic");
  SetShort("within a cold peatbog");
  SetLong(
    "Large skeletal black spruce trees protrude from soil " 
    "which is covered by thick peat moss. It reeks of decay"
    "and the ground is soft under foot. Rotting logs and "
    "uprooted trees lay within shallow puddles of black "
    "water and slowly rot away. A blanket of thick green "
    "peat moss covers the soft soil. A deteriorated wall of "
    "stone juts upward to the south."
  );
  SetItems( ([
    ({"trees","tree"}) : "Large skeletal black spruce trees are " 
      "the dominant deciduous tree within the peatbog.",
    ({"soil","mud"}) : "The soil is very soft and muddy, it is " 
      "coated with detritus.",
    ({"moss"}) : "Green peat moss covers everything within the " 
      "immediate area.",
    ({"logs","log"}) : "Rotting black spruce trees lay uprooted on " 
      "the ground and are covered in peat moss.",
    ({"water","puddles"}) : "Small cavities filled with black " 
      "stagnent water.",
    ({"detritus"}) : "The detritus is made up of dead leaves and " 
      "rotting log debris.",
    ({"wall"}) : "This wall of stone is so deteriorated that its "
    	"previous shape is suggested only by a single tooth of stone "
    	"jutting towards the sky.",
  ]) );
  SetItemAdjectives( ([
    "trees" : ({"large","skeletal","black","spruce"}),
    "soil" : ({"soft"}),
    "moss" : ({"thick","peat","green"}),
    "logs" : ({"rotting"}),
    "water" : ({"black","shallow"}),
    "puddles" : ({"black","shallow"}),
    "wall" : ({ "stone", "deteriorated", "jutting" }),
  ]) );
  SetListen( ([
    "default" : "The buzzing sound of insects is immense.",
  ]) );
  SetSmell( ([
    "default" : "The reek of decay is nauseating to the senses.",
  ]) );
  SetInventory( ([
    BOG_NPC + "dragonfly" :3,
    BOG_ITEM + "branch" :1,
  ]) );
  SetExits( ([
    "south" : BOG_ROOM "bog2",
  ]) );
}
