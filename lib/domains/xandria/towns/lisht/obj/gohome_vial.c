#include <lib.h>  
#include <vendor_types.h>
inherit LIB_ITEM;        

static void create() {
  ::create();         
  SetKeyName("vial");
  SetShort("a tiny vial of spice");
  SetId( ({ "vial","spice" }) );
  SetAdjectives( ({ "tiny","vial","of" }) );
  SetLong(
    "This is a small glass vial, supposedly filled with a few specks of "
    "spice harvested from a slain sandworm. A native drinking such a mixture will "
    "reportedly be returned to the sands from which they were born from "
    "great distances. Its known powers are fairly limited however, so "
    "<use vial to go home> with that knowledge "
    "in advance."                                                                      
    );                                                                                 
  SetValue(100);                                                                       
  SetMaterials( ({ "natural" }) );
  SetVendorType(VT_GEM);
  SetMass(5);
  SetProperty("magic", "This gem can be <use>d to return a native of Xandria to their desert home.");
}

int eventUse(object who, string args) {
  string town = who->GetNationality();
  if (args != "go home") {
    who->eventPrint("Use the vial to go home?");
    return 1;
  }
  if (member_array(town, ({ "Lisht" })) == -1) {
    who->eventPrint("Only natives of Xandria can use this vial.");
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
  who->eventMoveLiving("/domains/xandria/virtual/desert/-2,-1",
         "$N quaffs the vial quickly... and DISAPPEARS in sudden burst of sand!",
         "$N appears in a small whirlwind of sand and dust.");
  eventDestruct();
  return 1;
}

