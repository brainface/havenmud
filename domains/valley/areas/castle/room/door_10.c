#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("north", ([
                       "id" : ({ "north door","stout door","door" }),
                       "short" : "the north door",
                       "long" : "The door to the north is sturdy "
                          "and well made, not too grandiose to serve "
                          "its useful purposes, such as keeping the "
                          "cold out in winter.",
                       "lockable" : 0
                  ]) );
   SetSide("south", ([
                       "id" : ({ "south door","stout door","door" }),
                       "short" : "the south door",
                       "long" : "The door to the south is sturdy "
                          "and well made, not too grandiose to serve "
                          "its useful purposes, such as keeping the "
                          "cold out in winter.",
                       "lockable" : 0
                  ]) );
   SetClosed(1);
}