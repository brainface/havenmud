//
// Summary: an inn
//   Kyla 11-1-97
// Modified by Rhakz - Angel Cazares
// Date: 10/21/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("inside a small hut");
  SetObviousExits("out");
  SetClimate("indoors");
  SetTown("Baria");
  SetAmbientLight(50);
  SetLong("This hut seems to be a common lodging place for the "
          "village, and it is also the home of the famous Barian "
          "cocktails. There is some sort of kitchen in one of the "
          "corners of the hut where the delicious food is cooked. "
          "A large bar "
          "stands in another corner, and tables and chairs are "
          "scattered about."
         );
  SetInventory( ([
                  BARIA_NPC + "drunkard" : 1,
                  BARIA_NPC + "ginfur" : 1,
              ]) );
  SetItems( ([
              ({"hut"}) : (: GetLong :),
              ({"bar"}) : "A large counter from which food and drink "
                          "are served.",
              ({"table", "tables"}) : "This table looks very sturdy.",
              ({"chair", "chairs"}) : "This chair looks as if it has "
                                     "been well made.",
              ({"kitchen"}) : "The kitchen is made of a primitive "
                              "stove and a bonfire where meat can be "
                              "cooked."
          ]) );
  SetExits( ([
           "out" : BARIA_ROOM + "path3",
          ]) );
  SetSmell( ([ "default" : "The smell of ale and good cooking abound "
                           "your senses." ]) );
  SetListen( ([ "default" : "There is much laughing and joking to "
                            "be heard here." ]) );
}


