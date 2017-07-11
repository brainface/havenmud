#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("east", ([
                      "id" : ({ "east door","door","crypt door" }),
                      "short" : "the east door",
                      "long" : "This door reveals the one attempt "
                         "to put doors inside burial vaults here at "
                         "the castle.  Evidently, someone decided "
                         "that others weren't necessary, as none "
                         "decorate any other openings.",
                      "lockable" : 0,
                 ]) );
   SetSide("west", ([
                      "id" : ({ "west door","door","crypt door" }),
                      "short" : "the west door",
                      "long" : "This door reveals the one attempt "
                         "to put doors inside burial vaults here at "
                         "the castle.  Evidently, someone decided "
                         "that others weren't necessary, as none "
                         "decorate any other openings.",
                      "lockable" : 0,
                 ]) );
   SetClosed(1);
}