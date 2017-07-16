#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("west", ([
                      "id" : ({ "west gate","gate","garden gate" }),
                      "short" : "the garden gate",
                      "long" : "The gate leads out of the garden.  "
                         "Rose bushes push up close to it, but have been "
                         "pulled back so as not to obstruct its movement.",
                      "lockable" : 0,
                 ]) );
   SetSide("east", ([
                      "id" : ({ "east gate","gate","garden gate" }),
                      "short" : "the garden gate",
                      "long" : "The gate leads into the Eclatish "
                         "garden.",
                      "lockable" : 0,
                 ]) );
   SetClosed(1);
}