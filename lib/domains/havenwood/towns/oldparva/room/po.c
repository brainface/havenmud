#include <lib.h>
#include "parva.h"
inherit LIB_POST_OFFICE;

static void create() {
   post_office::create();
   SetTown("Parva");
   SetClimate("indoors");
   SetDomain("HavenWood");
   SetAmbientLight(35);
   SetShort("the post office");
   SetLong("The Parva Post Office is just a small room built on "
           "top of the town hall.  There is nothing "
           "special.  A staircase leads down to the town hall.");
   SetItems( ([
                ({ "Parva Post Office","office","po","room" }) :
                   (: GetLong :),
                ({ "post office staircase","staircase","stairs",
                      "stair" }) :
                   "The stairs lead down to the town hall.",
                ({ "hall", "town hall", "townhall" }) : "The town hall "
                     "resides below this room."
           ]) );
   SetItemAdjectives( ([
                         "stairs" : ({ "post","office" }),
                         "po" : ({ "parva","post","office","small" }),
                    ]) );
   SetExits( ([
                "down" : P_ROOM + "/th",
           ]) );
}
