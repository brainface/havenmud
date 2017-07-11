//
//A corridor
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
  inherit LIB_ROOM;

static void create() {
room::create();
 SetShort("a gloomy corridor");
 SetLong("Shadows flicker and seem to move in the dim light. The "
         "corridor appears to go on forever to the east and west."
         " The walls are of dusty stone, grimy with ingrained dirt from"
         " the violent upheaval of being thrown into the bosom of the earth."
         " The ceiling has collapsed in places, making progress forwards"
         "--or backwards--difficult.");
  SetClimate("underground");
  SetAmbientLight(5);
  SetExits( ([
              "east" : RNQ_RM + "ecor2.c",
              "west" : RNQ_RM + "forect.c",
          ]) );
  SetItems( ([
              ({"shadows","shadow"}) : "The shadows seem to move of their"
                            " own accord, independant of the light.",
              ({"walls","stone"}) : "The walls are formed from blocks"
                            " of stone, quarried and hewn by gangs of "
                            "slaves.",
              ("dirt") : "Dirt is everywhere here. This is not altogether"
                            "surprising, considering where 'here' is.",
              ("ceiling") : "The ceiling here looks ready to give way "
                            "any moment.",
              ("corridor") : (:GetLong:),
          ]) );
  SetItemAdjectives( ([
              "walls" : ({"stone","dusty","grimy"}),
                    ]) );
  SetListen( ([
               "default" : "Eerie scratching sounds can be heard.",
           ]) );
  SetSmell( ([
               "default" : "The smell of dust and rot lingers in the air.",
          ]) );
  SetInventory( ([
                  RNQ_NPC + "rat.c" : 1,
              ]) );
}  
