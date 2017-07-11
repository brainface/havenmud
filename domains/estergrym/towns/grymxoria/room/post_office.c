#include <lib.h>
#include "../grymxoria.h"

inherit LIB_POST_OFFICE;
 
static void create() {
  post_office::create();
  SetProperty("no attack",1);
  SetProperty("no bump",1);
  SetClimate("indoors");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("grymxoria's Post Office");
  SetLong(
    "This is the city post office of Grymxoria. "
    "From here, citizens may send and receive their mail by typing "
    "<mail>.  Once in, simply follow the instructions."
  );
  SetExits( ([ 
    "out" : G_ROOM + "road19"
  ]) );
}
