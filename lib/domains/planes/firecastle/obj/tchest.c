//
// filename: tchest
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include "../firecastle.h"
inherit LIB_STORAGE;

static void create() {
  ::create();
  SetKeyName("chest");
  SetDamagePoints(25000);
  SetLockStrength(200);
  SetShort("a large silver chest");
  SetMass(30000);
  SetId( ({ "chest" }) );
  SetAdjectives( ({ "large", "silver" }) );
  SetLong("This large chest is made from silver and it "
          "has a thick metal lock on the front which "
          "seems to be of a sturdy make.");
  SetClosed(1);
  SetPreventGet("You cannot pick that up!");
  SetCanClose(1);
  SetMaxCarry(7500);
  SetCanLock(1);
  SetLocked(1);
  SetKeys( ({ "chestkey" }) );
}


varargs mixed eventOpen(object who, string id, object tool) {
 if(!(who->GetQuestCompleted("Elemental Castle Quest"))) {
  who->AddQuest("the Ravager of Flames",  
                "Elemental Castle Quest");
   AddInventory(FCASTLE_OBJ + "scroll", 1);
  }
  ::eventOpen(who, id, tool);
}


varargs void reset(int count) {
  ::reset(count);
  SetClosed(1);
  SetLocked(1);
}
