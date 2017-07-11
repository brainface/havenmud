/*  Portia  Ruins  10-9-98
    Path through the village.
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("a dusty walkway");
  SetClimate("tropical");
  SetExits( ([
        "north" : RUINS_ROOMS + "5,-2",
        "south" : RUINS_ROOMS + "5,-4",
          ]) );
  SetSmell( ([
       "default" : "The area smells very earthen.",
          ]) );
  SetListen( ([
       "default" : "The sound of claws on stone can be heard all around.",
          ]) );
  SetInventory( ([
         ]) );
  SetLong("This walkway is the entrance to the village. Upon entering "
          "one can see that the little community has been utterly destroyed. "
         "The attack was obviously long ago judging by the amount of "
        "foliage that has grown up around it. To the east lies a great "
        "pile of stone that was once a large building. To the west there "
        "is a crude structure of a building. The walkway continues farther "
        "south into the village and north out into the jungle.");
  SetItems( ([
        "walkway" : "This dusty walkway leads north to the jungle and "
                    "south farther into the village.",
        ({"entrance", "village" }) : (:GetLong:),
        ({"foliage", "plants", "vines"}) : "These plants and vines have been here quite some time.",
    ({"pile of stone", "stone", "pile", "east building" }) :
          "This pile of stone is the remains of a building that was "
          "destroyed by some sort of attack.",
      ({ "west building", "building", "structure" }) : "Although the "
           "roof and two walls are missing this structure looks as "
           "though it may have some interesting artifacts inside.",
       "jungle" : "The jungle is north of here along the walkway.",
        ]) );
  SetItemAdjectives( ([
        "pile of stone" : ({"great", "east"}),
         "walkway" : "dusty",
         "west building" : "crude",
          "building" : "large",
         ]) );
  SetEnters( ([
       "west building" : RUINS_ROOMS + "house1",
           ]) );
  }
/*   [ Portia Approved ] */
