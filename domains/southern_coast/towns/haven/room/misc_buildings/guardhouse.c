//
// The Guardhouse
// Filename: guardhouse.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetNoClean(1);
   SetClimate("indoors");
   SetAmbientLight(60);
   SetShort("inside a guardhouse");
   SetLong("The guardhouse is a simple affair of stone built for the "
           "protection of the town from all invaders. There is a "
           "clear view of the gate and its surrounding roadside from "
           "here.");
   SetItems( ([
      ({ "house", "guardhouse" }) :
         (: GetLong :),
      ({ "stone" }) :
         "The entire guardhouse is made out of this stone.",
      ({ "invader", "invaders" }) :
         "The entire guardhouse was set up to protect the town from "
         "any possible invaders.",
      ({ "gate" }) :
         "The town gate can clearly be seen from here.",
      ({ "roadside", "side" }) :
         "The roadside surrounding the town gate can be seen from here.",
   ]) );
   SetItemAdjectives( ([
      "gate" : ({ "town" }),
   ]) );
   SetInventory( ([
      H_NPC + "templar_support" : 6,
   ]) );
   SetExits( ([
      "out" : H_ROOM + "gate",
   ]) );
}


/* Approved by Duuktsaryth on Tue Apr 27 21:12:07 1999. */
