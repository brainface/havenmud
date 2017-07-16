//
// Summary: outside the post office
//         Kyla 11-1-97
// Modified by Rhakz - Angel Cazares
// Date: 31/10/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("near a large hut");
  SetLong("The path ends at the entrance of a large hut. There are "
          "several birdcages around the hut containing carrier "
          "pigeons that deliver and bring letters and packages, "
          "they are the mail service of Baria."
         );
  SetTown("Baria");
  SetClimate("tropical");
  SetDomain("Baria");
  SetItems( ([
              ({"path"}) : "This is a small offshoot of the main path.",
              ({"birdcages","birdcage"}) : "Several birdcages are "
                                           "organized around the "
                                           "hut.",
              ({"pigeons","pigeon"}) : "The carrier pigeons are "
                                       "in charge of Baria's "
                                         "postal service.",
              ({"hut"}) : "This hut is a very cleverly designed building.",
          ]) );
  SetItemAdjectives( ([
                       "path" : ({"small"}),
                       "birdcages" : ({"several"}),
                       "pigeons" : ({"carrier"}),
                       "hut" : ({"large"})
                   ]) );
  SetObviousExits("east");
  SetExits( ([
              "east" : BARIA_ROOM + "path6",
          ]) );
  SetEnters( ([
               "hut" : BARIA_ROOM + "post",
           ]) );
  SetSmell( ([ "default" : "The smells of paper and ink are abundant "
                           "here." ]) );
  SetListen( ([ "default" : "Many birds are chirping loudly." ]) );
}

