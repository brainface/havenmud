/* a barn doorway
    kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an entranceway");
SetDomain("Valley");
  SetExits( ([
     "out" : MANSION_ROOMS + "pasture4",
     "south" : MANSION_ROOMS + "barn4",
     "west" : MANSION_ROOMS + "barn1",
        ]) );
  SetInventory( ([
            ]) );
  SetSmell( ([
          "default" : "There is the distinct smell of horse here.",
           ]) );
  SetListen( ([
         "default" : "Stomping can be heard to the south and to the west.",
           ]) );
  SetClimate("indoors");
  SetLong("The entranceway is quite large and full of loose straw. The air "
          "is musty and what little sunlight shines through the cracks in the "
          "walls glints off the dust in the air. To the south and to the west "
          "lie some animal stalls, while there seems to be a pasture outside "
          "the doorway.");
  SetItems( ([
     ({"entranceway", "doorway", "barn"}) : (:GetLong:),
            "straw" : "The dried straw covers the floor.",
             "floor" : "The wooden floor is covered in straw.",
             "sunlight" : "The bright sunlight peers through the cracks in the"
                              " wall.",
             "cracks" : "The cracks in the walls let some sunlight through.",
       ({"wall", "walls"}) : "The large wooden walls are full of cracks.",
             "crack" : "The cracks in the walls let some sunlight through.",
  ({"dust", "particle", "particles"}) : "These small particles float softly to the floor.",
        ({"stall", "stalls"}) : "The stalls lie to the west and to the south.",
           "pasture" : "The pasture is outside of the barn.",
               ]) );
  }
