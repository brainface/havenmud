#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetShort("in front of the tower");
  SetLong(
          "This section of the canyon shows a heavy wooden "
          "door to the warped black tower. A heavy fog wisps "
          "about bluring vision somewhat. The tower has been "
          "built overlooking this small canyon. Two torches "
          "can be seen on both sides of the door.");
  SetExits( ([
            "northwest"      : TOWER_ROOMS "tout05",
            "east"           : TOWER_ROOMS "tout03",
           ]) );
  SetInventory( ([
             TOWER_NPC "mummy2" : 2,
				   ]) );
  SetSmell( ([
            "default" : "A hazy fog wisps around from the mountaintop.",
           ]) );
  SetListen( ([
            "default" : "Silence looms over this barren field."
           ]) );
  SetRadiantLight(5);
  SetItems( ([
     "torches"   : "Two torches float next to the door on their own "
                   "with no support.",
     "torch"     : "It is made of wood and burns in a black flame.",
     "mountains" : "The Estergrym Mountains block off much travel "
                    "due to the sudden steep drops in them. A tower "
                    "rests in the center of all these walls. ",
     "wall"      : "The tower wall is made of perfectly cut black "
                    "stone slabs. A door can be seen to the north.",
     "fog"       : "A black fog looms about dampening the view.",
    ({ "ground", "floor" }) : "The ground is barren and lifeless. "
                               "Packed soil is all that remains from "
                               "the fog blocking out the sunlight.",
    "tower" : "The tower is warped and has been "
              "constructed to be swayed and "
              "twisted. A black magic hue can "
              "be seen from just gazing at the "
              "tower itself. A door rests in "
              "the tower with an uninviting "
              "look.",
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
 SetEnters( ([
    "tower" : TOWER_ROOMS "twer01",
           ]) );
  SetDoor( "tower", TOWER_OBJ "door");
}

