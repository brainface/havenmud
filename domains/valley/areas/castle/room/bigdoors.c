#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("west", ([ "id" : ({ "set of large double doors","set",
                                "large double doors","set of double doors",
                                "large doors","set of large doors",
                                "large door","door","double doors",
                                "west door","west doors" }),
                      "short" : "two large doors",
                      "long" : "A set of large double doors leads "
                         "into the west, grand and majestically made of "
                         "finely rubbed wood.",
                      "lockable" : 0,
                 ]) );
   SetSide("east", ([ "id" : ({ "set of large double doors","set",
                                "large double doors","set of double doors",
                                "large doors","set of large doors",
                                "large door","door","double doors",
                                "east door","east doors" }),
                      "short" : "two large doors",
                      "long" : "A set of large double doors leads "
                         "into the east, grand and majestically made of "
                         "finely rubbed wood.",
                      "lockable" : 0,
                 ]) );
   SetClosed(1);
}