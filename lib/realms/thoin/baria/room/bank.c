//
// Summary: the bank of Baria
// Created by Rhakz - Angel Cazares
// For Baria
// Date: 10/17/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the Barian Jungle Bank");
  SetLong("This large hut serves as the bank of Baria. In the back, "
          "there is a big vault where the all the money is stored. "
          "The hut is decorated with a few tapestries hanging from "
          "the walls and a rug covering the floor. There "
          "are a couple of chairs for the customers to sit down "
          "while the teller attends them." 
         );
  SetClimate("indoors");
  SetAmbientLight(40);
  SetTown("Baria");
  SetItems( ([
              ({"tapestries", "tapestry"}) : "These tapestries are "
                                             "very nice and fit the "
                                             "hut perfectly.",
              ({"rug"}) : "This rug is hand-woven and very beautiful.",
              ({"vault"}) : "This is a huge vault where the money "
                            "is kept. It is firmly closed.",
              ({"hut"}) : (: GetLong :)
          ]) );
  SetItemAdjectives( ([
                       "hut" : ({"large"}),
                       "tapestries" : ({"very nice","few"}),
                       "rug" : ({"hand-woven","beautiful"}),
                       "vault" : ({"huge","big"})
                   ]) );
  SetInventory( ([
                  BARIA_NPC + "pakal" : 1,
                  BARIA_OBJ + "bank_chair" : 2
              ]) );
  SetExits( ([
              "out" : BARIA_ROOM + "path10",
          ]) );
  SetSmell( ([ "default" : "The hut smells of fresh flowers." ]) );
  SetListen( ([ "default" : "Coins hitting against each other are "
                            "heard." ]) );
}

