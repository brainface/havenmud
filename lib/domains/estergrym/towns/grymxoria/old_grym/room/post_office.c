#include <lib.h>
#include "../grymxoria.h"

inherit LIB_POST_OFFICE;
 
static void create() {
  post_office::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetDomain("Estergrym");
  SetShort("Grymxoria's Post Office");
  SetLong("This is the city post office of Grymxoria. \n"
          "From here, citizens may send and receive their mail by typing \n"
          "<mail>.  Once in, simply follow the instructions.");
  SetExits( ([ "out" : G_ROOM + "road19" ]) );
  SetProperty("no attack",1);
  SetProperty("no bump",1);
  }
