//
// The Necromancers' Training Hall
// Filename: necromancers.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include "../haven.h"
#include <lib.h>

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("the Necromancers Training Hall");
   SetLong("This is the training hall of the Necromancers. Scattered about "
           "the room are the tools and wares of the School of Necromancy.");
   SetItems( ([
      ({ "tool", "tools", "ware", "wares" }) :
         "These many tools and wares that are scattered about the room are "
         "used by the School of Necromancy to assist in their teachings.",
   ]) );
   SetExits( ([
      "west" : "north_library",
   ]) );
   SetListen( ([
      "default" : "The chants of students fill the air.",
   ]) );
   SetSmell( ([
      "default" : "The scents of spell components taint the room.",
   ]) );
   SetInventory( ([
      H_NPC + "necro" : 1,
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 19:31:46 1999. */
