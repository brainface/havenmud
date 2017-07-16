
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;
string BushSearch();


static void create() {
  ::create();
  SetClimate("arid");
  SetObviousExits("southeast");
  SetShort("along the mountainside");
  SetLong(
          "The mountains and tower block off any travel but to "
          "the southeast toward the front of the tower. Parched "
          "and dry the ground has almost broken to a rough sand. "
          "Toward the northeast is a bush which has no foliage "
          "or leaves on its dried twigs.");
  SetExits( ([
            "southeast"      : TOWER_ROOMS "tout04",
           ]) );
  SetInventory(([ TOWER_NPC "udeer" : 1]));
  SetSmell( ([
            "default" : "A hazy fog wisps around from the mountaintop.",
           ]) );
  SetListen( ([
            "default" : "Silence looms over the barren field."
           ]) );
  SetRadiantLight(10);
  SetItems( ([
     "bush"   : "A dried bush grows to the northeast. Upon closer "
                "look something appears through the dried twigs.",
     "mountains" : "The Estergrym Mountains block off much travel "
                    "due to the sudden steep drops in them. A tower "
                    "rests in the center of all these walls. ",
     "wall"      : "The tower wall is made of perfectly cut black "
                    "stone slabs. No windows or openings to the "
                    "tower can be seen.",
     "fog"       : "A black fog looms about dampening the view.",
    ({ "ground", "floor" }) : "The ground is barren and lifeless. "
                               "Packed soil is all that remains from "
                               "the fog blocking out the sunlight. "
							   "It is very dry and has started to erode "
							   "into a sand.",
    ({ "tower" }) : "The tower is warped and has been "
                    "constructed to be swayed and "
                    "twisted. A black magic hue can "
                    "be seen from just gazing at the "
                    "tower itself.",
	"soil" : "The brown soil is packed down into the ground.",
	"stone": "The stone slabs create the tower wall.",
    "something" : "Appears to be something past the bush.",
              ]) );
  SetItemAdjectives( ([
    "soil" : ({ "brown","packed" }),
    "tower" : ({ "warped","black","twisted" }),
    "fog" : ({ "black"}),
    "wall" : ({ "tower" }),
    "stone" : ({ "slabs" }),
   "bush" : ({ "dried" }),
  ]) ); 
  SetSearch( ([
             "bush"      : (: BushSearch :),
			 "dried bush" : (: BushSearch :),
             ]) );
}
  string BushSearch() {
  if (GetExit("northeast")) {
    return "The bush has been trampled already leaving a narrow "
           "passage to the northeast.";
  }
  AddExit("northeast", TOWER_ROOMS + "tout06");
  SetObviousExits("southeast, northeast");
  return "The bush breaks from dehydration revealing a passage "
          "northeast!";
  }

