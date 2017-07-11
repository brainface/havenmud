#include <lib.h>
#include "../minaret.h"

inherit LIB_STORAGE;

static void create() {
  mapping inventory = ([]);
  ::create();
  SetOpacity(0);
  switch(random(3)) {
   case 0:
    SetShort("a date palm");
    SetLong(
      "The short date palm has a stout woody trunk "
      "topped by a crown of leaves.  Bunches of "
      "fruit dangle off the evergreen palm leaves."
    );
    SetMaxCarry(100);
    inventory [MIN_OBJ + "/date"] = random(3) +3,
    SetInventory(inventory);
    SetId( ({"palm", "tree" }) );
    SetAdjectives( ({ "date" }) );
    SetKeyName("palm");
    SetPreventGet(
      "The date palm is rooted firmly to the minaret."
    );
    break;

  case 1:
    SetShort("a pomegranate tree");
    SetLong(
      "A thin, woody trunk supports an array of branches "
      "atop this tree.  The branches are covered in tiny "
      "green leaves and a few have pomegranates growing "
      "from them."
    );
    SetMaxCarry(150);
    inventory [MIN_OBJ + "/pomegranate"] = random(3) +3,
    SetInventory(inventory);
    SetId( ({ "tree" }) );
    SetAdjectives( ({ "pomegranate" }) );
    SetKeyName("tree");
    SetPreventGet(
      "The pomegranate tree is rooted firmly to the minaret."
    );
  break;

  case 2:
   SetShort("a tree fern");
   SetLong(
    "The trunk of this tree fern is a mass of roots growing "
    "from the base to support the many fronds shooting "
    "out from the top of the plant.  The older fronds are long "
    "and are laced with "
    "sori running down their veins."
    "  The younger fronds on top are still unfurling."
     );
  SetMaxCarry(100);
  SetId( ({
    "fern", "tree"
    }) );
   SetAdjectives( ({ "tree" }) );
   SetKeyName("fern");
  SetPreventGet(
    "The tree fern is rooted firmly to the minaret."
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
