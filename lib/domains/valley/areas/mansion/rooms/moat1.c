/* a large moat
     kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the bank of a large moat");
SetDomain("Valley");
  SetClimate("temperate");
  SetExits( ([
       "north" : MANSION_ROOMS + "moat2",
       "west" : MANSION_ROOMS + "pasture5",
       "northwest" : MANSION_ROOMS + "pasture4",
          ]) );
  SetInventory( ([
            ]) );
  SetListen( ([
        "default" : "Ths squaking of a bird can be heard in the distance.",
            ]) );
  SetSmell( ([
     "default" : "The rotten stench of the still moat water is overwhelming.",
           ]) );
  SetLong("From the bank of the moat one can see a large mansion to "
          "the east. The moat continues to the north and and to the west "
           "is what appears to be a pasture. The bank is muddy and full of "
          "animal tracks. It appears that someone has passed through here "
          "recently.");
  SetItems( ([
        "moat" : "The moat water is green and is covered in algea and "
                 "other plants.",
        "water" : "THe water is very green.",
        "algea" : "The algea is just floating there.",
   ({ "plants", "plant" }) : "These are ordinary water plants.",
         "bank" : (:GetLong:),
         "mansion" : "The large mansion is across the moat.",
         "pasture" : "The pasture lies to the west.",
    ({ "track", "tracks" }) : "These appear to be sea creature tracks.",
             ]) );
  }
