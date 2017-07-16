//coded by Syra 11/97
//taken over by Zedd 12/98

#include <lib.h>
#include "../keryth.h"

inherit LIB_POST_OFFICE;

static void create() {
  post_office::create();
  SetClimate("indoors");
  SetAmbientLight(50);
  SetTown("Keryth");
  SetShort("inside Keryth's Post Office");
  SetLong("This is the post office that serves the town of Keryth. From "
          "here, citizens may send and recieve their mail by typing <mail>.  "
          "Once in, simply follow the directions.");
  SetExits( ([ "out" : K_ROOM + "/road1.c" ]) );
  SetProperty("no bump", 1);
  SetProperty("no attack", 1);
 SetProperty("no magic", 1);
  SetListen( ([
    "default" : "Little can be heard except the occasional sound of snow "
                "falling from the roof."
  ]) );
}
