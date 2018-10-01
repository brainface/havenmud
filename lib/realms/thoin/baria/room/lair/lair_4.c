// 
// Summary: caves for draconians
// Created by: Rhakz@Haven -- Angel Cazares
// For Baria
// Date: 31/01/99
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
          "The tunnel keeps getting hotter as it approaches the door "
          "seen north of here. The walls contain several small carvings "
          "that add to the primitive nature of the lair. The ground "
          "holds a detailed carving of a large dragon, which seems "
          "to sparkle because of the light emitted by the torches "
          "hanging from the walls."
         );
  SetItems( ([
              ({"tunnel"}) : (: GetLong :),
              ({"door"}) : 
                "A closed door can be seen north of here.",
              ({"wall","walls"}) :
                "The walls keep getting hotter and hotter. There "
                "are several figures carefully carved on them.",
              ({"small carvings","carvings","carving"}) :
                "Several drawings of draconians and dragons are "
                "carved in the walls.",
              ({"large carving", "carving"}) :
                "This is a detailed carving of a large dragon. It "
                "has a few pieces of red jewel incrusted in it, "
                "making the carving sparkle with the torches' light.",
              ({"torch","torches"}) : 
                "The torches illuminate the area.",
              ({"floor","ground"}) :
                "The floor is very damp. A large carving is marked on it.",
              ({"ceiling"}) :
                "The low ceiling is very wet and covered in moss.",
              ({"moss"}) :
                "Humid moss covers the ceiling."
          ]) );
  SetItemAdjectives( ([
                       "tunnel" : ({"hot"}),
                       "wall" : ({"hot","carved"}),
                       "large carving" : ({"detailed"}),
                       "floor" : ({"damp","marked"}),
                       "ceiling" : ({"low","wet"}),
                       "moss" : ({"humid"})
                   ]) );
  SetSmell("default", "It smells of stale water.");
  SetExits( ([
              "south" : BARIA_LAIR + "lair_3",
              "north" : BARIA_LAIR + "lair_5" 
          ]) );
}


