//
// The Jidoor Post Office
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_POST_OFFICE;

static void create() {
   post_office::create();
   SetAmbientLight(30);
   SetClimate("indoors");
   SetTown("Jidoor");
   SetShort("Jidoor's Post Office");
   SetLong("This large post office provides a great place to "
           "keep in touch with the other citizens of Kailie. "
           "A small table sits to the west as a place to compose "
           "mail, while a little slot in the eastern wall provides "
           "a place to put the mail when it's finished.");
   SetItems( ([ 
      ({ "table" }) : 
         "This small table sits on the western wall, creating a fine "
         "place to write mail.",
      ({ "slot" }) : 
         "This slot in the wall is useful for putting mail through.",
   ]) );
   SetExits( ([ 
      "out" : JID_ROOM "/road5",
   ]) );
}
