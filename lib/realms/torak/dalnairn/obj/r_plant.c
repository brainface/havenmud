//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include "../dalnairn.h"

inherit LIB_STORAGE;

static void create() {
  mapping inventory = ([]);
  ::create();
  SetOpacity(0);
  switch(random(3)) {
   case 0:
    SetShort("a yew tree");
    SetLong(
      "A yew tree. It has fruit."
    );
    SetMaxCarry(100);
    inventory [DAL_OBJ + "/aril"] = random(6) + random(6) + 12,
    SetInventory(inventory);
    SetId( ({ "tree" }) );
    SetAdjectives( ({ "yew" }) );
    SetKeyName("tree");
    SetPreventGet(
      "The yew tree is rooted firmly in place."
    );
    break;

  case 1:
    SetShort("an orange tree");
    SetLong(
      "An orange tree. It has fruit."
    );
    SetMaxCarry(150);
    inventory [DAL_OBJ + "/orange"] = random(3) +3,
    SetInventory(inventory);
    SetId( ({ "tree" }) );
    SetAdjectives( ({ "orange" }) );
    SetKeyName("tree");
    SetPreventGet(
      "The orange tree is rooted firmly in place."
    );
  break;

  case 2:
   SetShort("a tree fern");
   SetLong(
    "The trunk of this tree fern is a mass of roots growing "
    "from the base to support the many fronds shooting "
    "out from the top of the plant.  The older fronds are long "
    "and are laced with "
    "sori running down their veins. "
    "The younger fronds on top are still unfurling."
     );
  SetMaxCarry(100);
  SetId( ({
    "fern", "tree"
    }) );
   SetAdjectives( ({ "tree" }) );
   SetKeyName("fern");

  SetPreventGet(
    "The tree fern is rooted firmly in place."
  );
    break;
  }

}

// inventory always visible to look in
int inventory_visible() {
    return 1;
}

// append internal desc to external desc
//  (so display case is "transparent")
string GetExternalDesc() {
  string desc;
  desc = ::GetExternalDesc();
  desc += ::GetInternalDesc();
  return desc;
} 
