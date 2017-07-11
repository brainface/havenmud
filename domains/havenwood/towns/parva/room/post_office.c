#include <lib.h>
#include "../parva.h"

inherit LIB_POST_OFFICE;
 
static void create() {
   post_office::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetTown("Parva");
   SetShort("the Parva Post");
   SetLong("This small office serves as the mail station and post office "
          "for the city of Parva. The room is devoid of anything "
          "that could even vaguely be considered useful.  This room "
          "is _totally_ out-of-character.  Use the <mail> command "
          "to enter the mudwide mail system.");
   SetExits( ([ 
      "down" : PARVA_ROOM "town_hall",
   ]) );
   SetInventory( ([ 
   ]) );
}

