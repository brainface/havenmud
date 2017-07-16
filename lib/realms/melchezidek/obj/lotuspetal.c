#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("lotus petal");
  SetShort("a lotus petal");
  SetId( ({ "petal", }) );
  SetAdjectives( ({ "lotus", }) );
  SetLong(
    "This lotus petal is known to have special properties"
    " for those born in the land of Tairi. One need only"
    " <smell> it to find out it's purpose."
    );
  SetValue(5);
  SetVendorType(VT_PLANT);
  SetMass(5);
  SetProperty("magic", "This petal can be <smell>ed to return a native of Tairi to their island.");
  SetSmell("This lotus petal smells like a fresh spring rain.");
}

int eventSmell(object who, string args) {
  string town = who->GetNationality();
  if (town != "Tairi") {
    send_messages( ({ "smell" }), "$agent_name $agent_verb a lotus petal.", who, 0, environment(who));
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
  who->eventPrint("You smell the lotus petal.");
  who->eventMoveLiving("/domains/tairi/towns/tairi/room/path6", 
         "$N deeply sniffs a lotus petal... and is gone!",
         "$N appears in a shower of lotus petals.");
  eventDestruct();
  return 1;
}
