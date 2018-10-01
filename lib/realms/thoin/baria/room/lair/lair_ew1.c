// 
// Summary: caves for draconians
// Created by: Rhakz@Haven -- Angel Cazares
// For Baria
// Date: 08/02/99
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
          "There is a head of a dragon carved out from the wall to the "
          "west, out of the dragon's mouth a stream of "
          "water flows out and covers the ground. The walls are very "
          "smooth and damp. A couple of torches hang from the walls "
          "illuminating the area."
         );
  SetItems( ([
              ({"head","dragon","dragon's head","head of a dragon"}) :
                "This is a dragon's head carved out from the wall. "
                "From its open mouth, a stream of water flows to "
                "the east.",
              ({"west wall","wall"}) :
                "This is a smooth and damp wall from which a dragon's "
                "head has been carved out.",
              ({"mouth","dragon's mouth"}) :
                "From the dragon's mouth, a stream of water flows east.",
              ({"stream","water","stream of water"}) :
                "This underground stream flows from the west wall to "
                "the east.",
              ({"walls","wall"}) :
                "The walls are very smooth and humid. They hold torches "
                "that light the tunnel.",
              ({"torch","torches"}) :
                "A couple of lit torches enlighten the area. They are "
                "hanging from the walls.",
              ({"floor","ground"}) :
                "The ground is completely covered in water from the "
                "underground stream."
          ]) );
  SetItemAdjectives( ([
                       "west wall" : ({"smooth","damp"}),
                       "walls" : ({"smooth","damp","humid"}),
                       "torch" : ({"lit"}),
                       "ground" : ({"wet","damp"})
                   ]) );
  SetListen("default", "There is a strong noise of flowing water.");
  SetExits( ([
              "east" : BARIA_LAIR + "lair_ew2",
              "north" : BARIA_LAIR + "lair_nw1" 
          ]) );
}

