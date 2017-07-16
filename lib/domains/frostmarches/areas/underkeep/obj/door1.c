//
// a sturdy wooden door
// created by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
 inherit LIB_DOOR;

static void create() {
  door::create();
  SetSide("south", ([
    "keyname" : ("door"),
    "short" : "a sturdy door",
    "long" : "The door is built of sturdy oak, cross-braced with iron. It"
       " looks old and dusty, but has weathered the years remarkably"
       " well.",
    "id" : "door",
    "adjectives" : ({"sturdy","oak","old","dusty"}),
    "lockable" : 1,
    "keys" : "rusty key",
    ]) );
  SetSide("north", ([
    "keyname" : ("door"),
    "short" : "a sturdy door",
    "long" : "This door is built of good, thick oak, which has not rotted"
       " too badly over the years. It could certainly withstand a"
       " small army for a while if need be.",
    "id" : "door",
    "adjectives" : ({"sturdy","thick","oak","good"}),
    "lockable" : 1,
    "keys" : "rusty key",
    ]) );
  SetClosed(1);
  SetLocked(1);
}
