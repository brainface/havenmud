//
// Summary: outside leader tent
//     kYla 11-1-97
// Modified by Rhakz - Angel Cazares
// Date: 11/01/98
//
#include <lib.h>
#include <domains.h>
#include "../jungle.h"
inherit LIB_FISHING;

static void create() {
  ::create();
  SetShort("on the beach in Baria");
  SetLong("This is the southern most part of the Barian village. The "
          "small path ends at the a beach. An enormous hut sits along "
          "the beachfront. There are strange markings carved on "
          "hut that resemble religious writing. The most beautiful "
          "flowers in all the jungle are gathered here, around the hut "
          "and especially at its entrance. The beach leads south to the "
          "ocean.");
  SetTown("Baria");
  SetProperty("coastal", 1);
  SetClimate("tropical");
  SetDomain("Baria");
  SetItems( ([
              ({"path"}) : "A small path that leads south to a large "
                           "hut and north to the main path of the "
                           "village.",
              ({"hut"}) : "This hut is very big, and quite imposing.",
              ({"markings","marking"}) : "The markings appear to be "
                                         "in some ancient language.",
              ({"flowers","flower"}) : "These extremely beautiful "
                                       "flowers move with the faint "
                                       "wind of the jungle.",
              ({"entrance"}) : "The entrance of the hut is surrounded "
                               "by beautiful flowers."
          ]) );
  SetItemAdjectives( ([
                       "path" : ({"small"}),
                       "hut" : ({"large","big","very","imposing",
                                 "enormous","important"}),
                       "markings" : ({"strange"}),
                       "flowers" : ({"beautiful","extremely"})
                   ]) );
  SetInventory( ([
                   BARIA_NPC + "native_baria" : 1,
                   BARIA_NPC + "ferrycaptain" : 1,
                   BARIA_OBJ + "ferry"        : 1,
             ]) );
   SetSpeed(5);
   SetFish( ([
      DIR_STD "fish/guppy" : 100,
      DIR_STD "fish/trout" : 10,
      DIR_STD "fish/boot" : 1,
   ]) );
   SetChance(25);
   SetMaxFishing(12);
  SetExits( ([
              "north" : BARIA_ROOM + "path9",
              "east" : BARIA_ROOM + "path11",
              "west" : BARIA_ROOM + "path10",
              "south" : INNERSEA_VIRTUAL "ocean/-150,0",
          ]) );
  SetEnters( ([
               "hut" : BARIA_ROOM + "shrine_1",
           ]) );
  SetSmell( ([ "default" : "The strong odor of medicines fill the "
                           "air." ]) );
  SetListen( ([ "default" : "Chanting can be heard coming from the "
                            "hut." ]) );
}

