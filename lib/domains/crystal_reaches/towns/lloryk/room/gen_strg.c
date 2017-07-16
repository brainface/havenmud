#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetInventory( ([
     "/std/obj/light/torch" : 5,
      STD_FISH "pole" : 2,
     "/std/weapon/pole/staff" : 1,
                   ]) );
 }
