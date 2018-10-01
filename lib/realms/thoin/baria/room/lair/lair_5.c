// 
// Summary: caves for draconians
// Created by: Rhakz@Haven -- Angel Cazares
// For Baria
// Date: 31/01/99
//
#include <lib.h>
#include <domains.h>
#include "../../jungle.h"

inherit LIB_ROOM;

int CheckPC(string dir);

static void create() {
  room::create();
  SetShort("inside the lair");
  SetClimate("underground");
  SetAmbientLight(20);
  SetTown("Baria");
  SetLong(
          "Here, a massive wooden door stands closed to the north. "
          "The tunnel keeps getting somewhat wider and hotter. "
          "The walls contain "
          "several small carvings marked on them and lit torches that "
          "illuminate the area, but the most noticeable "
          "feature is the huge carving of an awesome dragon made "
          "on the ground."
         );
  SetItems( ([
              ({"tunnel"}) : (: GetLong :),
              ({"walls","wall"}) :
                "Torches hang from the hot walls, which have "
                "several carvings on them.",
              ({"small carvings","carvings","carving"}) :
                "Several carvings of dragons and draconians fill "
                "the walls.",
              ({"torch","torches"}) :
                "The torches' light give this place a decent "
                "illumination.",
              ({"huge carving","carving"}) :
                "This huge and detailed carving depicts a large "
                "and powerful dragon. It has several pieces of "
                "blue jewels incrusted on it, making the carving "
                "sparkle with the light.",
              ({"floor","ground"}) :
                "The wet floor contains a huge carving of a dragon.",
              ({"ceiling"}) : 
                "The ceiling is low on this part, and very damp."
          ]) );
  SetItemAdjectives( ([
                       "walls" : ({"hot","carved","marked"}),
                       "torch" : ({"lit"}),
                       "huge carving" : ({"sparkling","blue"}),
                       "floor" : ({"wet","carved","marked"}),
                       "ceiling" : ({"low","damp"})
                   ]) );
  SetInventory( ([
                   BARIA_NPC + "warrior" : 2,
                   BARIA_NPC + "ashtang" : 1
              ]) ); 
  SetSmell("default", "The smell of wet soil is all around.");
  SetExits( ([
              "south" : BARIA_LAIR + "lair_4"
          ]) );
  AddExit("north", BARIA_VIRTUAL + "tunnel/0,0", (: CheckPC :) );
  SetDoor("north", BARIA_OBJ + "tunnel_door");
}

int CheckPC(string dir) {
  if ( (this_player()->GetReligion() == "Kuthar") && 
       (this_player()->GetTown() == "Baria") ) return 1;
  if (present("warrior", this_object()) || present("ashtang", this_object())) {
    message("no", "The warrior stands in front of the door, blocking the path "
                  "north.", environment(this_player()) );
    return 0;
  }
  return 1;
 }