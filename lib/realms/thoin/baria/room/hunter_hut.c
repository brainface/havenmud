//
// Summary: the hut of Brun and Vorn
// Created by Rhakz - Angel Cazares
// For Baria
// Date: 10/16/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a hunter's hut");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetTown("Baria");
  SetLong(
          "This is the hut where Brun, the leader of the Hunters, "
          "and Vorn, the trainer, live. As the hut of a hunter, it "
          "is filled with heads of animals hanging from the walls as "
          "trophies. There are also several rugs covering the floor "
          "made out of different animal skins. In one of the corners "
          "of the hut, there are a few tools that are useful for the "
          "hunter profession."
         );
  SetItems( ([
               ({"heads of animals","head of animal",
                 "trophies"}) : "Several heads of animals such as "
                                "jaguars, monkeys and warthogs.",
               ({"walls","wall"}) : "The walls are made of wood and "
                                    "tropical trees' leaves.",
               ({"rugs","rug"}) : "Several rugs decorate the ground. "
                                  "They are made out of skins of "
                                  "different animals.",
               ({"few tools","tool"}) : "Tools like spears, nets, "
                                        "knives, etc., are "
                                        "accommodated in one of "
                                        "the corners of the hut." 
          ]) );
  SetInventory( ([
                   BARIA_NPC + "vorn" : 1,
                   BARIA_NPC + "sarkos" : 1,
                   BARIA_NPC + "brun" : 1,
              ]) );
  SetExits( ([
              "out" : BARIA_ROOM + "path11",
          ]) );
  SetSmell( ([ "default" : "Particles of dust fly around the hut." ]) );
}

