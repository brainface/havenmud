//
// Filename: diviners.c
// The Diviners' Training Hall
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
   SetShort("the Diviners' Training Hall");
   SetLong("This is the training hall of the Diviners. Scattered about "
           "the room are the tools and wares of the School of Divination. ");
   SetItems( ([
      ({ "tool", "tools", "ware", "wares" }) :
         "These many tools and wares of the School of Divination are "
         "scattered throughout the floor in many places.",
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
      H_NPC + "diviner" : 1,
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 19:19:47 1999. */
