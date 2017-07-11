#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("firestone");
  SetShort("an Averath firestone");
  SetId( ({ "firestone", "stone" }) );
  SetAdjectives( ({ "fire", "averath" }) );
  SetLong(
    "This is an Averath firestone, a special gem that is found on the "
    "Island of Averath. Rubbing the stone quickly has been known to "
    "make natives of Averath return quickly to the island.  Its known "
    "powers are fairly limited however, so <use stone to go home> with that knowledge "
    "in advance."
    );
  SetValue(100);
  SetMaterials( ({ "natural" }) );
  SetVendorType(VT_GEM);
  SetMass(5);
  SetProperty("magic", "This gem can be <use>d to return a native of Averath to the island.");
}

int eventUse(object who, string args) {
  string town = who->GetNationality();
  if (args != "go home") {
    who->eventPrint("Use the stone to go home?");
    return 1;
  }
  if (member_array(town, ({ "Averath", "Glistendin", "Dalnairn" })) == -1) {
    who->eventPrint("Only natives of Averath, Dalnairn, or Glistendin can use this stone.");
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
  who->eventMoveLiving("/domains/averath/towns/averath/room/tavern", 
         "$N rubs a firestone quickly... and DISAPPEARS!",
         "$N appears in a cloud of red, firey fury.");
  eventDestruct();
  return 1;
}
          
