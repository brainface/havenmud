
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetObviousExits("northeast, west");
  SetShort("near a tall, black tower");
  SetLong(
          "The tower rounds out to a flat surface forming "
          "almost a front wall. The mountains border off any travel "
          "to the south and southeast bending slightly around the "
          "tower. Black fog lingers about heavily limiting "
		  "view of the surrounding area.");
  SetExits( ([
            "northeast"      : TOWER_ROOMS "tout01",
            "west"           : TOWER_ROOMS "tout04",   
           ]) );
  SetInventory(([ TOWER_NPC "udeer" : 1 ]));
  SetSmell( ([
            "default" : "A hazy fog wisps around from the mountaintop.",
           ]) );
  SetListen( ([
            "default" : "Silence looms over the barren field."
           ]) );
  SetRadiantLight(5);
  SetItems( ([
     "mountains" : "The Estergrym Mountains block off much travel "
                    "due to the sudden steep drops in them. A tower "
                    "rests in the center of all these walls. ",
     "wall"      : "The tower wall is made of perfectly cut black "
                    "stone slabs. No windows or openings to the "
                    "tower can be seen.",
     "fog"       : "A black fog looms about dampening the view.",
    ({ "ground", "floor" }) : "The ground is barren and lifeless. "
                               "Packed soil is all that remains from "
                               "the fog blocking out the sunlight.",
    ({ "tower"}) : "The tower is warped and has been "
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
