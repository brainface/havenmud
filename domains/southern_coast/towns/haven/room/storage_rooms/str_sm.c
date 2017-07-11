//
// The Smithy Storage Room
// Filename: str_sm.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include <std.h>
#include "../haven.h"

inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetPurgeInterval(3);
   SetInventory( ([
     "/std/weapon/melee/brass_knuckles" : 3,
     "/std/weapon/pole/staff" : 2,
   ]) );
}


/* Approved by Haun on Tue Apr 27 21:19:12 1999. */
