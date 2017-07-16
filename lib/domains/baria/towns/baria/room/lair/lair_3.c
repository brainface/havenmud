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
  SetShort("inside the lair");
  SetClimate("underground");
  SetAmbientLight(20);
  SetTown("Baria");
  SetLong(
          "North of the intersection, the tunnel seems to get wider "
          "as it continues north. The walls would be overall smooth "
          "if not for the small carvings on its surface, which emphasize "
          "the large carving of a dragon on the floor. "
          "The carving seems to shine with the light of the torches "
          "hanging from the walls."
         );
  SetItems( ([
              ({"tunnel"}) : (: GetLong :),
              ({"wall","walls"}) : 
                "The walls are smooth except for some carvings on them.",
              ({"small carvings","carving","figures"}) : 
                "Figures of dragons and draconians are clearly carved "
                "in the walls.",
              ({"large carving","carving"}) :
                "A large and detailed carving of a dragon is "
                "marked on the floor. The carving "
                "has some pieces of a black jewel incrusted on it, making "
                "it shine with the light.",
              ({"floor","ground"}) :
                "The ground seems drier than the walls or ceiling, "
                "but the most notable characteristic is the large "
                "carving of the black dragon--Kysanth.",
              ({"torch","torches"}) :
                "The torches illuminate the passage and make the "
                "carving sparkle."
          ]) );
  SetItemAdjectives( ([
                       "tunnel" : ({"wide"}),
                       "wall" : ({"smooth","carved"}),
                       "large carving" : ({"detailed","shiny"}),
                       "floor" : ({"dry","carved","marked"})
                   ]) );
  SetSmell("default", "The smell of wet soil abounds here.");
  SetListen("default", "The noise of flowing water is heard to the south.");
  SetExits( ([
              "south" : BARIA_LAIR + "lair_2",
              "north" : BARIA_LAIR + "lair_4" 
          ]) );
}

