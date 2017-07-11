//
// an obisidian door
// created by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
 inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("south", ([
     "keyname" : "door",
     "id" : ({ "door" }),
     "adjectives" : ({"obsidian","solid"}),
     "short" : "an obsidian door",
     "long" : "This door was built to keep out intruders in a serious"
        " way. It must have taken slaves a lifetime of toil to make"
        " this door, as it was chipped from solid obsidian to form"
        " an imposing obstacle to any invader.",
     "lockable" : 1,
     "keys" : "obsidian_key",
     ]) );
   SetSide("north", ([
     "keyname" : "door",
     "id" : ({ "door" }),
     "adjectives" : ({"obsidian","solid"}),
     "short" : "an obsidian door",
     "long" : "This door was built to keep out intruders in a serious"
       " way. It must have taken slaves a lifetime of toil to make"
       " this door, as it was chipped from solid obsidian to form an"
       " imposing obstacle to any invader.",
     "lockable" : 1,
     "keys" : ({ "obsidian_key" }),
     ]) );
   SetClosed(1);
   SetLocked(1);
}
