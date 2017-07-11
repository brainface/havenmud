// 
// Summary: caves for draconians
// Created by: Rhakz@Haven -- Angel Cazares
// For Baria
// Date: 13/02/99
//
#include <lib.h>
#include "../../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a dirty room inside the lair");
  SetClimate("underground");
  SetAmbientLight(20);
  SetTown("Baria");
  SetLong(
          "This room is full of mud and moss is all over the place. "
          "Drops of water fall incessantly from the ceiling, forming "
          "small pools on the ground. There is a table with bottles "
          "tubes and other alchemy equipment. Two lit braziers provide "
          "illumination to the room."
         );
  SetItems( ([
              ({"room","place"}) : (: GetLong :),
              ({"mud"}) :
                "The water mixes with the soil, creating brownish "
                "mud that makes this place dirty.",
              ({"moss"}) :
                "There is green moss covering walls, ceiling and "
                "ground.",
              ({"drops","drop","water","drops of water"}) :
                "Water drips from the ceiling and falls to the "
                "floor, creating a mess of mud and water.",
              ({"pools","pool"}) :
                "These pools are formed by the water dripping "
                "from the ceiling.",
              ({"table"}) :
                "This is a table where alchemy equipment rests.",
              ({"bottles","bottle","tubes","tube","equipment"}) :
                "These are several tools used by alchemists to "
                "create potions.",
              ({"braziers","braziers"}) :
                "The braziers illuminate the room."
          ]) );
  SetItemAdjectives( ([
                       "mud" : ({"brown","brownish"}),
                       "moss" : ({"green"}),
                       "pool" : ({"small"}),
                       "braziers" : ({"lit"})
                   ]) );
  SetInventory( ([
                  BARIA_NPC + "naj" : 1,
                  BARIA_NPC + "rahja" : 1
              ]) );
  SetSmell("default", "It smells of strange substances.");
  SetListen("default", "The sound of boiling water is present.");
  SetExits( ([
              "south" : BARIA_LAIR + "lair_nw1" 
          ]) );
}
