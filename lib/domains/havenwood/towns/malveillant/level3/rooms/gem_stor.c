//  The Gem Store Storage Room
//  Created by Zaxan@Haven
//  Stolen by Davantalus@Haven
//  Re-Stolen by Alessandra 2009

#include <lib.h>
#include "../mal.h"
#define GEM "/std/mine/gems/"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  
  SetInventory( ([ 
     GEM "amber" : 2,
     GEM "aquamarine" : 2,
     GEM "diamond" : 1,
     GEM "garnet" : 1,
     GEM "jade": 1,
     GEM "onyx" : 2,
     GEM "sapphire" : 1,
     GEM "topaz" : 2,
     ]) );
  SetPurgeInterval(5);

}
