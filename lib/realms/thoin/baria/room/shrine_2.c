// 
// Summary: Kutharin Shrine
// Created by Rhakz - Angel Cazares
// For Baria
// Date: 10/16/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the upper level of the Shrine of Kuthar");
  SetLong("This is the upper level of an enormous, circular-shaped "
          "hut that serves as a shrine for the Kutharian followers. "
          "There is a diagram hanging from the wall of the anatomy "
          "of a dragon and another of the anatomy of humans, both "
          "look very ancient. There is a rack filled with ointments "
          "and bottles of medicine. "
          "There is a wooden ladder attached to a hatch in the floor "
          "to go down to the ground level of this huge hut.");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetTown("Baria");
  SetItems( ([
              ({"wall"}) : "The circular wall is made of wood and tree "
                           "leaves.",
              ({"diagram","diagrams"}) : "There are two diagrams "
                                         "hanging from the wall. "
                                         "One depicts the anatomy "
                                         "of a dragon and the other "
                                         "the anatomy of a human. "
                                         "Both are very old.",
              ({"floor"}) : "The floor is made of a very strong "
                            "type of wood.",
              ({"ladder"}) : "A simple wooden ladder.",
              ({"hatch"}) : "This hatch leads into the ground level "
                            "of the hut.",
              ({"rack","bottles","bottle",
                "ointment","ointments"}) : "There are several bottles "
                                           "and ointments of different "
                                           "effects in a wooden rack.",
              ({"hut"}) : (: GetLong:)
           ]) );
  SetItemAdjectives( ([
                       "wall" : ({"circular"}),
                       "diagram" : ({"old","ancient"}),
                       "ladder" : ({"wooden"}),
                       "rack" : ({"wooden"}),
                       "hut" : ({"circular","enormous","huge"})
                   ]) );
  SetInventory( ([
                  BARIA_NPC + "ayla" : 1
              ]) );
  SetExits( ([
              "down" : BARIA_ROOM + "shrine_1"
          ]) );
  SetListen( ([ "default" : "There is a faint humming in the air." ]) );
  SetSmell( ([ "default" : "There is a strong smell of medicine and "
                           "herbs." ]) );
}

