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
  SetShort("north from the lair entrance");
  SetClimate("underground");
  SetAmbientLight(20);
  SetTown("Baria");
  SetLong(
          "North of the entrance to the draconian lair, the passage "
          "seems to get darker as it gets away from the entrance. "
          "The floor, walls and ceiling get damper as they go further "
          "north. Two torches hang at each side of the tunnel, giving "
          "some amount of light to the obscure caves."
         );
  SetItems( ([
              ({"passage","tunnel","lair"}) : (: GetLong :),
              ({"entrance"}) : "The entrance to the lair lies just "
                               "south of here.",
              ({"floor","ground"}) : "The smooth floor is very damp.",
              ({"torch","torches"}) : "The torches enlighten the tunnel.",
              ({"wall","walls"}) : "The walls are very smooth and damp.",
              ({"ceiling"}) : "The low ceiling filtrates small amounts "
                              "of water."
          ]) );
  SetItemAdjectives( ([
                       "passage" : ({"draconian"}),
                       "floor" : ({"damp","smooth"}),
                       "wall" : ({"smooth", "damp"}),
                       "ceiling" : ({"low","damp","smooth"})
                   ]) );
  SetSmell("default", "It smells of stale water.");
  SetListen("default", "The sound of running water is heard from "
                       "the north." );
  SetExits( ([
              "south" : BARIA_LAIR + "entrance",
              "north" : BARIA_LAIR + "lair_2" 
          ]) );
}

