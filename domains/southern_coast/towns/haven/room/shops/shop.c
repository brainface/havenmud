//
// Taylor's General Store
// Filename: shop.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include <std.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("Taylor's General Store");
   SetClimate("indoors");
   SetExits( ([
      "out" : "../merchants_way/mw4",
   ]) );
   SetAmbientLight(50);
   SetInventory( ([
      H_NPC + "taylor" : 1,
      H_NPC + "guard" : 2,
      STD_OBJ "lootchest" : 1,
   ]) );
   SetLong("The shop is a chaotic jumble of items which are scattered \n"
           "across the room in no particular order.  The walls of the \n"
           "shop are crowded with items hanging on racks of some kind. \n"
           "The floor is cluttered with scraps of paper and bits of objects.");
   SetProperty("no bump",1);
   SetItems( ([
      ({ "shop", "store" }) :
         (: GetLong :),
      ({ "item", "items", "jumble" }) :
         "These many items are jumbled across the room in no particular "
         "order.",
      ({ "wall", "walls" }) :
         "The walls of the shop are crowded with racks full of different "
         "items.",
      ({ "rack", "racks" }) :
         "These racks line the walls, filled with items for sale.",
      ({ "floor" }) :
         "This floor is cluttered with many scraps of paper and bits "
         "of various objects.",
      ({ "paper", "object", "objects" }) :
         "These scraps of paper and bits of objects are strewn all over "
         "the floor.",
   ]) );
   SetItemAdjectives( ([
      "store" : ({ "general", "taylor's" }),
      "item" : ({ "many", "chaotic" }),
      "wall" : ({ "crowded" }),
      "paper" : ({ "scraps of", "bits of" }),
   ]) );
}


/* Approved by Haun on Tue Apr 27 21:16:54 1999. */
