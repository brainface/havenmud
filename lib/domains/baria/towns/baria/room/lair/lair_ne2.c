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
  SetShort("at the end of the northeast tunnel");
  SetClimate("underground");
  SetAmbientLight(20);
  SetTown("Baria");
  SetLong(
          "The tunnel ends here in this humid and hot room. Water "
          "filtrates through the soil which also transmits the heat "
          "received on the surface from the sun. Two lit braziers "
          "give out enough light for moss to grow on the walls."
         );
  SetItems( ([
              ({"room"}) : (: GetLong :),
              ({"tunnel"}) : 
                "The tunnel running south-north in the northeast "
                "part of the lair.",
              ({"water"}) :
                "Water that filtrates through the soil drips from "
                "the ceiling.",
              ({"brazier","braziers"}) :
                "The braziers illuminate the room.",
              ({"moss"}) :
                "There is moss on the ceiling and on the walls."               
          ]) );
  SetItemAdjectives( ([
                       "room" : ({"humid","hot"}),
                       "braziers" : ({"lit"})
                   ]) );
  SetInventory( ([
                  BARIA_NPC + "malkark" : 1
              ]) );
  SetSmell("default", "The smell of moisture is noticeable.");
  SetExits( ([
              "south" : BARIA_LAIR + "lair_ne1" 
          ]) );
}
