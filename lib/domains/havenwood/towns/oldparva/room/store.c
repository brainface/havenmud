#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
  SetClimate("indoors");
  SetAmbientLight(30);
   SetShort("in Pons' Store");
   SetDomain("HavenWood");
   SetLong("Pons' Store is a rackety little shack in Parva.  "
           "Large boxes for the storage of fishing poles and "
           "other equipment sold by Pons are neatly set around "
           "the store.  The only exit is out.");
   SetItems( ([
                ({ "Pons Store","store","shack" }) :
                   (: GetLong :),
                ({ "storage boxes","box","boxes" }) :
                   "The only permanent thing inside this shack are "
                   "the many boxes.  They come in all shapes and "
                   "sizes; some are skinny but very long, while "
                   "other are short and squat.  They store all "
                   "of Pons' equipment.",
                ({ "Pons equipment","equipment","poles","pole" }) :
                   "All of Pons' equipment, including his fishing "
                   "poles, are carefully stored in the boxes.",
           ]) );
   SetItemAdjectives( ([
                         "store" : ({ "pons","rackety","little" }),
                         "boxes" : ({ "large","storage" }),
                         "poles" : ({ "fishing","equipment" }),
                    ]) );
   SetListen( ([
                 "default" : "The noises of Parva's Wharf and the "
                    "ocean have made it inside this shack.",
            ]) );
   SetSmell( ([
                "default" : "Fish and the salty ocean fill the "
                   "store with their smells.",
           ]) );
   SetExits( ([
                "out" : P_ROOM + "/path3",
           ]) );
   SetInventory( ([
                    P_NPC + "/storekeep" : 1,
                  P_NPC + "/snop" : 1,
               ]) );
}
