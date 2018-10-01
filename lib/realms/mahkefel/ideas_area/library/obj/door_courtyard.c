// A jammed door
//  requires strength check to open.
#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("south",
    ([ "id" : "door", 
     "short": "a jammed wooden door",
     "long" : "Age has warped this wooden door badly. It may take some "
       "strength to open it.",
     "lockable" : 0])
  );
  SetSide("north",
    ([ "id" : "door", 
     "short": "a jammed wooden door",
     "long" : "Age has warped this wooden door badly. It may take some "
       "strength to open it.",
     "lockable" : 0]) 
  );
  SetClosed(1);
}

int eventOpen(object by, object agent) {
  int pro, con;

  if (creatorp(by)) {
    by->eventPrint("You bust through the door like the Kool-Aid man.");
    return ::eventOpen(by,agent);
  }
  if (by->GetStaminaPoints() < 60) {
    by->eventPrint("You are too tired.");
    return 0;
  }
  pro = random(by->GetStatLevel("strength"));
  con = random(40) + 40;
  debug("pro: " + (string)pro + "  con: " + (string)con);
  if ( pro < con ) {
    by->AddStaminaPoints(-50 - random(20));
    send_messages("shove",
      "$agent_name%^GREEN%^ $agent_verb%^RESET%^ the old wooden door "
      "with all $agent_possessive might, but it refuses to budge.",
      by,0,environment(by)
    );
    return 0;
  } else {
    send_messages("kick",
      "$agent_name%^GREEN%^ violently $agent_verb%^RESET%^ the old wooden "
      "door open.",
      by,0,environment(by)
    );
    return ::eventOpen(by,agent);
  }

}

