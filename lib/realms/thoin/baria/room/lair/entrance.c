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
  SetShort("a collapsed cave entrance");
  SetClimate("underground");
  SetAmbientLight(20);
  SetTown("Baria");
  SetLong(
          "This is the entrance to the underground lair in which "
          "draconians live however it is blocked off by a cave in. "
          "The wals have been carved out of the ground but it appears "
          "that it collapsed and is now buried beneath the rubble. "
          "There is a climbable ladder that leads up out of the cave."
         );
  SetItems( ([
              ({"lair", "passage"}) : (: GetLong :),
              ({"wall", "walls"}) : "The walls have been perfectly cut "
                                    "out from the ground, and they are "
                                    "very smooth.",
              ({"ceiling"}) : "The ceiling has mostly collapsed blocking "
                              "all of the exits except for the ladder. ",
              ({"floor","ground"}) : "The ground is covered in small bits of rock "
                                     "from the cave in.",
              ({"torch","torches"}) : "The torches burn slightly providing "
                                      "light for the cave.",
              ({"rubble", "rock"}) : "Large pieces of the ceiling and other pieces of rocks "
                                     "have filled the cave blocking all possible exits. The "
                                     "rocks are slightly wet and damp which may of caused the "
                                     "cave in."
          ]) );
  SetItemAdjectives( ([
                       "lair" : ({"underground"}),
                       "wall" : ({"smooth"}),
                       "ceiling" : ({"smooth"}),
                       "floor" : ({"smooth", "damp"}),
                       "torch" : ({"lit"}),
                       "rubble" : ({"wet", "damp"}),
                   ]) );
  SetInventory( ([
                  BARIA_OBJ + "lair_ladder" : 1
              ]) );
  SetSmell("default", "The place smells of dirt and soil.");
  SetListen("default", "An echo of rumblings reverberate through out the cave.");
  SetExits( ([
          ]) );
}
