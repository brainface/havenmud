#include <lib.h>
#include "../lodge.h"
inherit LIB_DOOR;

static void create() {
  door::create();

  SetSide( "annex", ([ 
     "keyname" : ("door"),
     "id" : "door",
     "short" : "a complicated door",
     "long" : "This door is small in size but could fit mostly anyone.  The lock on the "
       "door needs a special shaped key to open.",
     "lockable" : 1,
     "keys" : "icekey01",
     ]) );
  SetSide( "out", ([ 
     "keyname" : ("door"),
     "id" : "door",
     "short" : "a complicated door",
     "long" : "This door is small in size but could fit mostly anyone.  The lock on the "
       "door needs a special shaped key to open.",
     "lockable" : 1,
     "keys" : "icekey01",
     ]) );
  SetClosed(1);
  SetLocked(1);
}
