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
  SetShort("the northeast part of the lair");
  SetClimate("underground");
  SetAmbientLight(20);
  SetTown("Baria");
  SetLong(
          "The tunnel is very damp and slippery due to the water "
          "that filtrates through the soil and drips from the "
          "ceiling and the walls, from where some torches hang to "
          "enlighten the tunnel. Moss can be seen in the walls and "
          "in the ceiling."
         );
  SetItems( ([
              ({"tunnel","place"}) : (: GetLong :),
              ({"water"}) :
                "Water drips from the ceiling and the walls.",
              ({"soil"}) :
                "The whole lair is made of underground soil.",
              ({"ceiling"}) :
                "The ceiling is very wet and water drips from "
                "it.",
              ({"walls","wall"}) :
                "The walls are wet and dirty, creating mud all "
                "over the place.",
              ({"torch","torches"}) :
                "A couple of torches hang from the walls in order "
                "to illuminate the area.",
              ({"moss"}) :
                "Green moss is all around the walls and the ceiling.",
              ({"mud"}) :
                "Brown mud is all over the floor, due to the mix of "
                "water and soil."
          ]) );
  SetItemAdjectives( ([
                       "soil" : ({"underground"}),
                       "ceiling" : ({"wet"}),
                       "walls" : ({"wet","dirty"}),
                       "moss" : ({"green"}),
                       "mud" : ({"brown"})
                   ]) );
  SetSmell("default", "It smells of moisture and musk.");
  SetListen("default", "The sound of flowing water comes from the south.");
  SetExits( ([
              "north" : BARIA_LAIR + "lair_ne2",
              "south" : BARIA_LAIR + "lair_ew4" 
          ]) );
}
