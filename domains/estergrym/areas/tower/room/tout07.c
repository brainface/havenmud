
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetObviousExits("south");
  SetShort("a dead end");
  SetLong(
          "The mountain base comes from the southwest and wraps "
          "around to the east. The tower has been embeded into "
          "the mountain preventing any passage further around "
          "this canyon. A pit in the ground has been made from "
          "a living force.");
  SetExits( ([
            "south"      : TOWER_ROOMS "tout06",
           ]) );
  SetSmell( ([
            "default" : "A hazy fog wisps around from the mountaintop.",
           ]) );
  SetListen( ([
            "default" : "Silence looms over the barren field."
           ]) );
  SetRadiantLight(5);
  SetInventory(([ TOWER_NPC "ubear" : 1]));
  SetItems( ([
     "pit"       : "This pit in the ground looks like a great "
                   "resting place for a large beast.",
     "mountains" : "The Estergrym mountains block off much travel "
                    "due to the sudden steep drops in them. A tower "
                    "rests in the center of all these walls. ",
     "wall"      : "The tower wall is made of perfectly cut black "
                    "stone slabs. No windows or openings to the "
                    "tower can be seen.",
     "fog"       : "A black fog looms about dampening the view.",
    ({ "ground", "floor" }) : "The ground is barren and lifeless. "
                               "Packed soil is all that remains from "
                               "the fog blocking out the sunlight.",
    ({ "tower" }) : "The tower is warped and has been "
                    "constructed to be swayed and "
                    "twisted. A black magic hue can "
                    "be seen from just gazing at the "
                    "tower itself.",
	"soil" : "The brown soil is packed down into the ground.",
	"stone": "The stone slabs create the tower wall.",

				  ]) );
  SetItemAdjectives( ([
    "soil" : ({ "brown","packed" }),
    "tower" : ({ "warped","black","twisted" }),
    "fog" : ({ "black"}),
    "wall" : ({ "tower" }),
    "stone" : ({ "slabs" }),
  ]) ); 
}