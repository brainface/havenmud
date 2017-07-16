#include <lib.h>
#include "../karak.h"

inherit LIB_POST_OFFICE;

static void create() {
  post_office::create();
  SetClimate("indoors");
  SetTown("Karak");
  SetShort("Karak-Varn's Communications Post");
  SetLong("This cramped and cluttered office is where the mail is "
           "recieved and sent.  If you would like to send or read "
          "mail, type <mail> for further instructions.");
  SetObviousExits("out");
  SetExits( ([ "out" : K_ROOM + "/rd5" ]) );

}

