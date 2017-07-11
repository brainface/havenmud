//
// The Gem Store Storage Room
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetAmbientLight(60);
   SetProperty("no attack", 1);
   SetClimate("indoors");
   SetNoClean(1);
   SetTown("Jidoor");
   SetShort("The Gem Store Storage Room");
   SetInventory( ([  ]) );
   SetPurgeInterval(5);
}

void init() {
   ::init();
   if (!creatorp(this_player())) {
      message("system","%^BLUE%^BOLD%^What are you...some "
               "kind of THIEF?!?%^RESET%^",this_player());
      this_player()->eventMove(JID_ROOM "/misc_buildings/gemstore");
   }
}
