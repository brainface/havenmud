//
// The Gem Store Storage Room
// Created by Zaxan@Haven
// Stolen by Davantalus@Haven
//

#include <lib.h>
#include "../mal.h"
#define GEM "/std/obj/treasure/gem/"
inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetAmbientLight(60);
   SetProperty("no attack", 1);
   SetClimate("indoors");
   SetNoClean(1);
   SetTown("Malveillant");
   SetShort("The Gem Store Storage Room");
   SetInventory( ([ 
/*
            GEM "amber" : 2,
            GEM "amethyst" : 2,
            GEM "aquamarine" : 2,
            GEM "citrine" : 2,
            GEM "diamond" : 1,
            GEM "emerald" : 1,
            GEM "garnet" : 1,
            GEM "jade": 1,
            GEM "onyx" : 1,
            GEM "opal" : 1,
            GEM "peridot" : 1,
            GEM "ruby" : 2,
            GEM "sapphire" : 2,
            GEM "topaz" : 2,
            GEM "tourmaline" : 1,
*/
 ]) );
   SetPurgeInterval(5);
}

void init() {
   ::init();
   if (!creatorp(this_player())) {
      message("system","What are you...some "
               "kind of THIEF?!?",this_player());
      this_player()->eventMove(MAL_ROOMS "/gemstore");
   }
}
