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
  SetShort("entrance to draconians' lair");
  SetClimate("underground");
  SetAmbientLight(20);
  SetTown("Baria");
  SetLong(
          "This is the entrance to the underground lair in which "
          "draconians live. The walls, ceiling and floor have been "
          "perfectly cut out from the ground itself. Two lit torches "
          "hang from the wall at each side of the passage running "
          "north. There's a climbable ladder to go out of the lair."
         );
  SetItems( ([
              ({"lair", "passage"}) : (: GetLong :),
              ({"wall", "walls"}) : "The walls have been perfectly cut "
                                    "out from the ground, and they are "
                                    "very smooth.",
              ({"ceiling"}) : "The ceiling has been perfectly cut out "
                              "from the ground. Ocasionally, a drop of "
                              "water falls from it to ground.",
              ({"floor","ground"}) : "The ground is very smooth and quite "
                                     "damp.",
              ({"torch","torches"}) : "The torches enlighten the passage."
          ]) );
  SetItemAdjectives( ([
                       "lair" : ({"underground"}),
                       "wall" : ({"smooth"}),
                       "ceiling" : ({"smooth"}),
                       "floor" : ({"smooth", "damp"}),
                       "torch" : ({"lit"})
                   ]) );
  SetInventory( ([
                  BARIA_OBJ + "lair_ladder" : 1
              ]) );
  SetSmell("default", "The place smells of dirt and soil.");
  SetListen("default", "Footsteps can be heard.");
  SetExits( ([
              "north" : BARIA_LAIR + "lair_1"
          ]) );
}
