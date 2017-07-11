// 
// Summary: caves for draconians
// Created by: Rhakz@Haven -- Angel Cazares
// For Baria
// Date: 13/02/99
//
#include <lib.h>
#include "../../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the northwest part of the lair");
  SetClimate("underground");
  SetAmbientLight(20);
  SetTown("Baria");
  SetLong(
          "The walls in this part of the tunnel are very dirty and "
          "full of scratches. The area is very humid, and most of it "
          "is covered with moss, making the ground very slippery. "
          "Two torches hanging from the walls illuminate the place."
         );
  SetItems( ([
              ({"walls","wall"}) :
                "The walls are wet and covered with moss. Torches hang "
                "from them",
              ({"tunnel","area","place"}) : (: GetLong :),
              ({"moss"}) :
                "Green moss covers the ceiling, the walls, and the ground.",
              ({"torch","torches"}) :
                "Two torches hanging from the walls give out some amount "
                "of light."
          ]) );
  SetItemAdjectives( ([
                       "wall" : ({"wet","humid","damp","dirty"}),
                       "tunnel" : ({"humid","dirty"}),
                       "moss" : ({"green"}),
                   ]) );
  SetSmell("default", "The smell of moisture is strong.");
  SetExits( ([
              "north" : BARIA_LAIR + "lair_nw2",
              "south" : BARIA_LAIR + "lair_ew1" 
          ]) );
}
