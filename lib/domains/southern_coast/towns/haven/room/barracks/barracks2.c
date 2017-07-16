//
// Filename: barracks2.c
// Haven Town Barracks v2.0
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetShort("the training hall");
   SetExits( ([
      "south" : "barracks",
   ]) );
  SetInventory( ([
      H_NPC + "manar" : 1,
      H_NPC + "damon" : 1,
   ]) );
   SetLong("This is the training hall of the Haven Town Guard. \n"
           "Scattered around the room are various types of tools \n"
           "meant to train people in the use and defense against \n"
           "differing types of weapons.  The ceiling is a low one,\n"
           "with ropes dangling for climbing.  However, all the ropes \n"
           "are caught around the rafters right now and cannot be climbed.");
   SetItems( ([
      ({ "hall" }) :
         (: GetLong :),
      ({ "tool", "tools", "weapon", "weapons" }) :
        "Training weapons carelessly litter the barracks. ",
      ({ "ceiling" }): 
         "Because the ceiling is so low, the climb to the \n"
         "the top of the ropes would be somewhat short.",
      ({ "rope", "ropes" }):
         "The coarse ropes are wrapped around the rafters \n"
         "at the moment.",
      ({ "rafter", "rafters" }) :
         "Rough ropes cling to the wooden rafters like snakes \n"
         "wrap around their prey.",
   ]) );
   SetItemAdjectives( ([
      "hall" : ({ "training" }),
      "tool" : ({ "training" }),
      "ceiling" : ({ "low" }),
      "rope" : ({ "dangling", "climbing", "coarse", "rough" }),
      "rafter" : ({ "wooden" }),
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 18:36:58 1999. */
