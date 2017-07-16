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
  SetShort("a dark and hot tunnel");
  SetLong("The dark and hot tunnel runs endlessly to the north. "
          "The walls are very smooth and they contain some "
          "carvings and strange markings. "
          "Torches hang from the walls in an attempt to dimly "
          "illuminate the passage.");
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
              ({"carvings","carving","markings","marking"}) :
                "These strange figures of dragons are marked on "
                "the walls' surface. They seem to be religion-"
                "related.",
              ({"torch","torches"}) :
                "Several lit torches hang from the walls, dimly "
                "enlightening the tunnel.",
              ({"floor","ground"}) :
                "The ground is very smooth and dry."
          ]) );
  SetItemAdjectives( ([
                       "wall" : ({"smooth","marked","carved"}),
                       "carvings" : ({"strange"}),
                       "torch" : ({"lit"}),
                       "floor" : ({"smooth","dry"})
                   ]) );
  SetExits( ([
              "south" : BARIA_LAIR + "lair_5",
              "north" : BARIA_VIRTUAL + "tunnel/0,1"
          ]) );
  SetDoor("south", BARIA_OBJ + "tunnel_door");
}
