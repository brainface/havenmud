//
// The Armoury Storage Room
// Filename: str_ar.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetPurgeInterval(3);
   SetInventory( ([
   ]) );
}


/* Approved by Haun on Tue Apr 27 21:19:02 1999. */