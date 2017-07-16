//
// The HavenMage Guild Room
// Filename: havenmage_room.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetProperty("no teleport", 1);
   SetAmbientLight(45);
   SetShort("the home of the Haven Mages Guild");
   SetNewsgroups( ({ "town.haven.library" }) );
   SetExits( ([
      "down" : "masters_hall",
   ]) );
   SetLong("This is the home of the Haven Mages' Guild. Its walls are lined "
           "with books detailing the wisdom of hundreds of years of work. To "
           "even behold the raw power that has cycled through this place is "
           "to be awed by it. There is a glowing staircase leading back "
           "down.");
   SetItems( ([
      ({ "wall", "walls" }) :
         "The walls of this guild room are lined with many books that "
         "detail hundreds of year worth of work and information.",
      ({ "book", "books", "compilation", "compilations" }) :
         "These many books line the walls of the room. They are "
         "compilations of hundreds of years of wisdom and information.",
      ({ "power" }) :
         "The power that eminates from this room is awe-inspiring.",
      ({ "staircase" }) :
         "This glowing staircase leads back down into the library.",
   ]) );
   SetItemAdjectives( ([
      "staircase" : ({ "glowing" }),
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 19:21:07 1999. */
