#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("south",
    ([ "id" : "door", 
     "short": "a heavy steel door",
     "long" : "This heavy steel door shows no sign of decay, nor does "
       "the intricate lock holding it in place. A faded pictogram of a broom "
       "is barely visable on the surface.",
     "lockable" : 1])
  );
  SetSide("north",
    ([ "id" : "door", 
     "short": "a heavy steel door",
     "long" : "This heavy steel door shows no sign of decay. A simple "
       "latch allows you to open it from this side.",
     "lockable" : 1]) 
  );
  SetClosed(1);
  SetLocked(1);
  SetLockStrength(300);
}

// allow opening from the janitor's closet
mixed CanOpen(object who) {
  object room;
  room = environment(who);
  if(room->GetProperty("janitor")) {
    SetLocked(0);
  }
  return ::CanOpen(who);
}

// auto-lock when closed
int eventClose(object by, object agent) {
  send_messages("",
    "The door latches shut with a clang.",
    by,0,environment(by)
  );
  SetLocked(1);
  ::eventClose(by,agent);
}
