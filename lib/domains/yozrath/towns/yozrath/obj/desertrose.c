#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("desert rose");
  SetShort("a desert rose");
  SetId( ({ "rose", }) );
  SetAdjectives( ({ "desert", }) );
  SetLong(
    "This is a desert rose, a special flower that is found at the "
    "Oasis in Yozrath. Smelling the flower has been known to "
    "make natives of the desert return quickly to the Oasis.  Its known "
    "powers are fairly limited however, so <smell flower> with that knowledge "
    "in advance."
    );
  SetValue(5);
  SetVendorType(VT_PLANT);
  SetMass(5);
  SetProperty("magic", "This flower can be <smell>ed to return a native of Yozrath to the Oasis.");
  SetSmell("This rose smells of the sands of Yozrath.");
}

int eventSmell(object who, string args) {
  string town = who->GetNationality();
  if (town != "Yozrath") {
    send_messages( ({ "smell" }), "$agent_name $agent_verb a beautiful desert rose.  Ahhhhh.", who, 0, environment(who));
    return 1;
  }
  if (who->GetInCombat()) {
    who->eventPrint("You're too busy right now.");
    return 1;
  }
  if (sizeof(who->GetEnemies())) {
    who->eventPrint("Too many people dislike you right now.  Settle your issues with your enemies first.");
    return 1;
  }
  who->eventPrint("You deeply inhale the scent of the desert rose.");
  who->eventMoveLiving("/domains/yozrath/towns/yozrath/room/oasis2", 
         "$N deeply inhales the scent of a desert rose... and is gone!",
         "$N appears with a waft of desert freshness.");
  eventDestruct();
  return 1;
}
          
