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
          "The ground here is all covered in water from the underground "
          "river running east to west right through the tunnel. The "
          "walls and the ceiling are very wet and smooth. There are some "
          "torches that dimly light the way."
         );
  SetItems( ([
              ({"ground","floor"}) :
                "The ground is completely covered in water from the "
                "underground river.",
              ({"water","river","stream","stream of water"}) :
                "The underground river flows from east to west.",
              ({"tunnel"}) : (: GetLong :),
              ({"walls","wall"}) :
                "The walls are very smooth and wet from the river.",
              ({"ceiling"}) :
                "The low ceiling is very humid.",
              ({"torch","torches"}) :
                "A couple of torches hanging from the walls dimly "
                "light the tunnel."
          ]) );
  SetItemAdjectives( ([
                       "river" : ({"underground"}),
                       "walls" : ({"smooth","damp"}),
                       "ceiling" : ({"low","humid","wet","smooth"}),
                   ]) );
  SetListen("default", "Water flowing is heard.");
  SetExits( ([
              "east" : BARIA_LAIR + "lair_ew4",
              "west" : BARIA_LAIR + "lair_2" 
          ]) );
}
