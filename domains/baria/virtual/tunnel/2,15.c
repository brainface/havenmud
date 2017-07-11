//
// Summary: room next to kysanth
// Created by: Rhakz@Haven -- Angel Cazares
// For Baria
// Date: 03/02/99
//
#include <lib.h>
#include "/domains/baria/towns/baria/jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("at the end of the tunnel");
  SetLong("The tunnel ends here abruptly at a massive black door from "
          "which extreme heat emanate. The walls are very smooth and "
          "free from carvings, unlike in the rest of the "
          "tunnel. Two torches hang from the walls at each side "
          "of the passage.");
  SetClimate("underground");
  SetAmbientLight(20);
  SetTown("Baria");
  SetItems( ([
              ({"tunnel","passage"}) : (: GetLong :),
              ({"wall","walls"}) : 
                "The walls have been perfectly cut out from the "
                "ground, making them very smooth. There are some "
                "carvings and markings on them. They also hold "
                "several lit torches.",
              ({"torch","torches"}) :
                "Several lit torches hang from the walls, dimly "
                "enlightening the tunnel.",
              ({"floor","ground"}) :
                "The ground is very smooth and dry.",
              ({"ceiling"}) :
                "The ceiling is very low."
          ]) );
  SetItemAdjectives( ([
                       "wall" : ({"smooth","marked","carved"}),
                       "carvings" : ({"strange"}),
                       "torch" : ({"lit"}),
                       "floor" : ({"smooth","dry"}),
                       "ceiling" : ({"low"})
                   ]) );
  SetSmell("default", "The smell of death is present.");
  SetListen("default", "Some growling can be heard in here.");
  SetExits( ([
              "south" : BARIA_VIRTUAL + "tunnel/2,14",
              "north" : BARIA_AREAS + "jungle/lair"
          ]) );
  SetDoor("north", BARIA_OBJ + "tunnel_door_2");
}
