#include <lib.h>
#include "../path.h"
inherit LIB_POST_OFFICE;

static void create() {
  post_office::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetTown("Glimmerdin");
  SetShort("a quiet post office");
  SetLong(
    "Scattered around the room are various tubes and slots for the delivery "
    "and sorting of the mail for the city of Glimmerdin. Outside lies the "
    "immense Great Hall of Glimmerdin. "
    );
  SetProperty("no teleport",1);
  SetProperty("no conjuring",1);
  SetItems( ([
    ({ "tube", "tubes", "slot", "slots" }) :
        "These slots in the wall hold the mail for the citizens.",
    ]) );
 SetSmell( ([
   "default" : "The post office smells of inks and dyes.",
   ]) );
 SetListen( ([
   "default" : "The post office is quiet and effecient.",
   ]) );
 SetExits( ([
   "out" : G_ROOM "gh_south",
   ]) );
}

int CanReceive(object ob) {
	return 1;
}
