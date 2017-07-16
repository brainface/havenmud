//
// The Sanctum Post Office
// Filename: post.c
// Created by Duuk@Pax Imperialis
//

#include <lib.h>
#include "../rome.h"

inherit LIB_POST_OFFICE;
 
static void create() {
   post_office::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetTown("Sanctum");
   SetShort("Sanctum's Post Office");
  SetLong("This booth serves as the mail station and post office "
          "for the city of Sanctum. The room is devoid of anything "
          "that could even vaguely be considered useful.  This room "
          "is _totally_ out-of-character.  Use the <mail> command "
          "to enter the mudwide mail system.");
   SetExits( ([ 
      "out" : ROME_ROOM "forum",
   ]) );
   SetInventory( ([ 
   ]) );
}

