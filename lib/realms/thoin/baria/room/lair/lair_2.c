// 
// Summary: caves for draconians
// Created by: Rhakz@Haven -- Angel Cazares
// For Baria
// Date: 29/01/99
//
#include <lib.h>
#include "../../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an intersection inside the lair");
  SetClimate("underground");
  SetAmbientLight(20);
  SetTown("Baria");
  SetLong(
          "Here is were two tunnels intersect, one running north to "
          "south and the other running east to west. A few torches "
          "hanging from the walls make this place brighter. A closed "
          "door can be seen far to the west and another one far to "
          "the east, yet one more is seen far to the north."
         );
  SetItems( ([
              ({"tunnels","tunnel"}) : (: GetLong :),
              ({"torch","torches"}) : "These torches add more light to "
                                      "this area.",
              ({"wall","walls"}) : "The walls are very smooth and "
                                   "somehow damp. Torches hang from "
                                   "them.",
              ({"door","doors"}) : "A closed door stands far to the "
                                   "east, another one far to the west "
                                   "and yet another one to the north.",
              ({"ground","floor"}) : "The floor is very smooth and damp.",
              ({"ceiling"}) : "The ceiling is low and damp."
          ]) );
  SetItemAdjectives( ([
                       "door" : ({"closed"}),
                       "wall" : ({"smooth","damp"}),
                       "door" : ({"closed"}),
                       "floor" : ({"smooth","damp"}),
                       "ceiling" : ({"low","damp"})
                   ]) );
  SetInventory( ([
              ]) );
  SetSmell("default", "The smell of fresh water and moisture is here.");
  SetListen("default", "There is a loud sound of flowing water.");
  SetExits( ([
              "south" : BARIA_LAIR + "lair_1",
              "north" : BARIA_LAIR + "lair_3",
              "west" : BARIA_LAIR + "lair_ew2",
              "east" : BARIA_LAIR + "lair_ew3"
          ]) );
}
