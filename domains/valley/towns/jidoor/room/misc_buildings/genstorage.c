//
// The General Store Storage Room
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetAmbientLight(30);
   SetProperty("no attack", 1);
   SetClimate("indoors");
   SetNoClean(1);
   SetTown("Jidoor");
   SetPurgeInterval(5);
   SetShort("The General Store Storage Room");
   SetInventory( ([
     JID_OBJ + "/clothing/diviner_robe" : 1,
     JID_OBJ + "/clothing/evoker_robe" : 1,
     JID_OBJ + "/clothing/necro_robe" : 1,
     JID_OBJ + "/clothing/enchanter_robe" : 1,
     JID_OBJ + "/clothing/mystic_robe" : 1,
     JID_OBJ + "/clothing/vs_diviner_robe" : 1,
     JID_OBJ + "/clothing/vs_evoker_robe" : 1,
     JID_OBJ + "/clothing/vs_necro_robe" : 1,
     JID_OBJ + "/clothing/vs_enchanter_robe" : 1,
     JID_OBJ + "/clothing/vs_mystic_robe" : 1,
     JID_OBJ + "/clothing/wing_cloth" : 4,
     JID_OBJ + "/clothing/wing_leather" : 4,     
     "/std/obj/light/torch" : 4,
     "/std/fish/pole" : 2,
     "/std/weapon/pole/baton" : 2,
   ]) );
}

void init() {
   ::init();
   if (!creatorp(this_player())) {
      message("system","%^BLUE%^BOLD%^What are you...some kind of "
              "THIEF?!?%^RESET%^",this_player());
      this_player()->eventMove(JID_ROOM "/misc_buildings/genstore");
   }
}

