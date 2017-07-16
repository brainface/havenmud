#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
  SetSide("cabin", ([
                     "id" : ({ "cabin door","door","plain door" }),
                       "short" : "the cabin door",
                       "long" : "The door fits well in its own niche in "
                          "the cabin.",
                       "lockable" : 0,
                  ]) );
   SetSide("out", ([
                     "id" : ({ "cabin door","door","plain door" }),
                     "short" : "the cabin door",
                     "long" : "The door fits well in its own niche in the "
                        "cabin.",
                     "lockable" : 0,
                ]) );
   SetClosed(1);
}
