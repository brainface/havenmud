// File: ranger_guildhall.c
// Original Author: Sabrielle@Haven
// Date: August 1998
// Synopsis: Ranger Guild Hall
// Addition Work: Zaxan Zimtafarous@Haven
//

#include <lib.h>

#include "../ranger_hall.h"
inherit LIB_ROOM;
static void create() {
    room::create();
    SetShort("Rangers Guild Hall");
    SetDomain("Valley");
    SetClimate("indoors");
    SetAmbientLight(50);
    SetProperty("no bump", 1);
    SetProperty("no attack", 1);
    SetProperty("no teleport", 1);
    SetExits( ([
       "out" : RH_ROOM + "path1",
    ]) );
    SetLong("The ranger guild is a small hole in the ground with steps "
            "leading up out of the ground. Sturdy but simple furniture "
            "is arranged in an organized fashion about the room in a "
            "pleasing manner. The walls are pure stone that look as "
            "if they were formed as opposed to cut. Glistening on the "
            "walls are bright mineral deposits that keep the room "
            "well-lit in a seemingly powerful way. A small underground "
            "stream trickles south along a trove in the west wall.");
    SetItems( ([
           ({"hole","ground","room"}) : "This hole in the ground forms "
                                        "a unique room.",
           ({"steps"}) : "The steps lead out from the ground up to "
                         "the crevice above.",
           ({"walls","stone","deposits"}) : "The stone walls are "
                                            "covered from floor to "
                                            "ceiling in sparkling "
                                            "mineral deposits. "
                                            "A trove runs along the "
                                            "western wall that allows "
                                            "an underground stream to "
                                            "run through the guildhall.",
           ({"furniture"}) : "The simple furniture is mainly of wood "
                             "and stone.",
            ]) );
    SetItemAdjectives( ([
           "hole" : ({"small"}),
           "furniture" : ({"simple"}),
           "deposits" : ({"bright","mineral"}),
           "walls" : ({"stone"}),
    ]) );
    SetInventory( ([
       RH_OBJ + "stream" : 1,       
    ]) );
    }



