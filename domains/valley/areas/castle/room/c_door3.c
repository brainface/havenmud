#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("coffin", ([
                        "id" : ({ "coffin lid","lid" }),
                        "short" : "the coffin lid",
                        "long" : "The lid to this coffin can be "
                           "opened and closed, unlike those to "
                           "other coffins.  It looks as if nothing "
                           "much can fit in there.",
                        "lockable" : 0,
                 ]) );
   SetSide("out", ([
                     "id" : ({ "coffin lid","lid" }),
                     "short" : "the coffin lid",
                     "long" : "The lid to this coffin can be "
                        "opened and closed, unlike those to "
                        "other coffins.  It looks as if nothing "
                        "much can fit in there.",
                     "lockable" : 0,
                 ]) );
   SetClosed(1);
}