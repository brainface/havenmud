//
// Summary: the hut of the Cazique
// Created by Rhakz - Angel Cazares
// For Baria
// Date: 10/16/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a very fancy hut");
  SetLong(
          "This is a very fancy hut, it is decorated with rugs "
          "and tapestries. Also, there are several jewels incrusted "
          "in the walls. Obviously, the person living in this hut "
          "has a lot of wealth and power in order to decorate his "
          "home in such a way."
         );
  SetClimate("indoors");
  SetAmbientLight(40);
  SetTown("Baria");
  SetItems( ([
              ({"rugs","rug","tapestries",
                "tapestry"}) : "These rugs and tapestries look very out "
                               "of place, like if they had been imported "
                               "from another town.",
              ({"jewels","jewel"}) : "There's an assortment of "
                                     "different jewels placed on the "
                                     "walls that make them sparkle "
                                     "like the sky in a starry night.",
              ({"hut","home"}) : (: GetLong :)
          ]) );
  SetItemAdjectives( ([
                       "hut" : ({"very","fancy"})
                   ]) );
  SetInventory( ([
                  BARIA_NPC + "mianin" : 1,
  ]) );
  SetExits( ([
              "out" : BARIA_ROOM + "path10",
  ]) );
  SetNewsgroups( ({ "town.baria" }) );
  SetSmell( ([ "default" : "A faint scent of incense penetrates "
                           "the hut." ]) );
  SetListen( ([ "default" : "There's a pleasant sound of wind chimes "
                            "inside the hut." ]) );
}

