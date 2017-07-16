//
// The Shop Storage Room
// Filename: str_sh.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include <std.h>
#include "../haven.h"

inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetInventory( ([
     
     STD_LIGHT "torch" : 8,
     STD_FISH "pole" : 2,
     H_OBJ + "pole" : 2,
//     STD_STORAGE "backpack" : 2
     STD_OBJ "parchment" : 3,
     STD_OBJ "digging/shovel" : 1,
   ]) );
   SetPurgeInterval(1);
}


/* Approved by Haun on Tue Apr 27 21:19:08 1999. */
