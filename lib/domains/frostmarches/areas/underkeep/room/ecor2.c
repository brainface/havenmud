//
// A corridor
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
  inherit LIB_ROOM;

static void create() {
room::create();
 SetShort("a gloomy corridor");
 SetLong("Here the corridor bends sharply, first to the right, then back "
         "to the left, as if trying to throw off this impudent mortal who "
         "dares to desecrate its long-undisturbed area. Cobwebs abound,"
         " though they have caught little in recent centuries. The "
         "ceiling has collapsed in places, making progress forwards"
         "--or backwards--difficult.");
  SetClimate("underground");
  SetAmbientLight(5);
  SetExits( ([
              "east" : RNQ_RM + "tower2.c",
              "west" : RNQ_RM + "ecor1.c",
          ]) );
  SetItems( ([
    ({"cobweb","cobwebs"}) : "The cobwebs are old and dusty.",
              ({"shadows","shadow"}) : "The shadows look dark and spooky.",
              ({"walls","stone"}) : "The walls are solid granite.",
              ("dirt") : "Dirt is scattered around the floor, and is"
                    "ingrained on the walls.",
              ("ceiling") : "The ceiling here looks ready to give way "
                            "any moment.",
              ("floor") : "The floor is covered in dirt.",
              ("corridor") : (:GetLong:),
          ]) );
  SetItemAdjectives( ([
    "walls" : "stone",
    ]) );
  SetListen( ([
               "default" : "Eerie scratching sounds can be heard.",
           ]) );
  SetSmell( ([
               "default" : "The smell of dust and rot lingers in the air.",
          ]) );
  SetInventory( ([
                  RNQ_NPC + "rat.c" : 2,
              ]) );
}
