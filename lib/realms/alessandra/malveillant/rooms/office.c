/*  Portia  12-11-98
   Copied from Haven's Post office coded by Duuktsaryth.
    The post office.
    version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_POST_OFFICE;
 
static void create() {
  post_office::create();
  SetClimate("indoors");
  SetTown("Malveillant");
  SetShort("Malveillant's Post Office");
  SetLong("This is the city post office that serves the town of Malveillant. \n"
          "From here, citizens may send and receive their mail by typing \n"
          "<mail>.  Once in, simply follow the instructions.");
  SetObviousExits("out");
  SetExits( ([ 
    "out" : MAL_ROOMS + "path14",
    ]) );
  }
