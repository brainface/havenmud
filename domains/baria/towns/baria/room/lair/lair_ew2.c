// 
// Summary: caves for draconians
// Created by: Rhakz@Haven -- Angel Cazares
// For Baria
// Date: 04/02/99
//
#include <lib.h>
#include "../../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("inside the east-west tunnel");
  SetClimate("underground");
  SetAmbientLight(20);
  SetTown("Baria");
  SetLong(
          "This is an east-west passage that intercepts the "
          "north-south one. The walls are very smooth and quite "
          "spotless, they have also been perfectly cut out from the "
          "underground soil. The floor is all covered in water, as "
          "this passage "
          "is part of an underground water stream that passes through "
          "the draconians lair."
         );
  SetItems( ([
              ({"passage","lair"}) : (: GetLong :),
              ({"wall","walls"}) :
                "The walls are very smooth and clean.",
              ({"ground","floor"}) :
                "The ground is covered with water of an underground "
                "water stream that passes through it.",
              ({"soil"}) :
                "The lair has been made out of the underground soil "
                "of Baria.",
              ({"water","stream","river"}) :
                "This underground river runs straight through the "
                "east-west corridor of the draconian lair."
          ]) );
  SetItemAdjectives( ([
                       "lair" : ({"draconians"}),
                       "wall" : ({"smoot","clean","spotless"}),
                       "soil" : ({"underground"}),
                       "water" : ({"underground"})
                   ]) );
  SetSmell("default", "There is a smell of stale water in here.");
  SetListen("default", "The sound of running water is present.");
  SetExits( ([
              "east" : BARIA_LAIR + "lair_2",
              "west" : BARIA_LAIR + "lair_ew1" 
          ]) );
}
