#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("temple", ([ "id" : ({ "temple doors","temple door","doors",
                                  "door","beautiful doors",
                                  "beautiful door" }),
                        "short" : "the temple doors",
                        "long"  : "The entrance to the temple is through "
                           "these two temple doors.  They are simply "
                           "decorated, but look quite beautiful.",
                        "lockable" : 0,
                   ]) );
   SetSide("out", ([ "id" : ({ "temple doors","temple door","doors",
                               "door","beautiful doors",
                               "beautiful door" }),
                     "short" : "the temple doors",
                     "long"  : "The exit from the temple is through "
                        "these two temple doors.  They are simple "
                        "decorated, but quite beautiful.",
                     "lockable" : 0,
                ]) );
   SetClosed(1);
}