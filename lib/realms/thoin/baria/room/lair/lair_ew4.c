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
          "The underground river that passes right through this "
          "tunnel continues its way further to the east through a "
          "hole existing in the east wall. The area is decently "
          "enlightened by a pair of torches hanging from the smooth "
          "and wet walls."
         );
  SetItems( ([
              ({"river"}) :
                "This is an undergound river coming from the west "
                "and passes through this part of the tunnel.",
              ({"tunnel","area"}) : (: GetLong :),
              ({"hole"}) :
                "This is a relatively small hole where the river "
                "continues its way to the east.",
              ({"east wall","wall"}) :
                "There is a hole in this wall where the river flows "
                "into. The wall is quite wet, mainly because of the "
                "river flowing into the hole. A torch hangs from it.",
              ({"torch","torches"}) :
                "The torches hanging from the walls give out some "
                "decent light.",
              ({"walls","wall"}) :
                "The walls are very wet and smooth. Lit torches hang "
                "from them."
          ]) );
  SetItemAdjectives( ([
                       "river" : ({"underground"}),
                       "hole" : ({"small","relatively"}),
                       "east wall" : ({"wet"}),
                       "torch" : ({"lit"}),
                       "walls" : ({"smooth","damp"})
                   ]) );
  SetListen("default", "The sound of water flowing can be heard.");
  SetSmell("default", "Smells of moisture and humidity.");
  SetExits( ([
              "west" : BARIA_LAIR + "lair_ew3",
              "north" : BARIA_LAIR + "lair_ne1" 
          ]) );
}

