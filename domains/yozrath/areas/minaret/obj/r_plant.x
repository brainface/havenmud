#include <lib.h>
#include "../minaret.h"

inherit LIB_STORAGE;

static void create() {
  mapping inventory = ([]);
  ::create();
  SetOpacity(0);
  switch(random(3)) {
   case 0:
   SetShort("a fern bush");
   SetLong(
    "This bush is a sea of green fern fronds.  "
    "The older fronds are long and are laced with " 
    "red sori running down their veins while younger "
    "fronds on top are still unfurling."
     );
  SetId( ({
    "fern", "bush"
    }) );
   SetAdjectives( ({ "fern" }) );
   SetKeyName("fern");
  SetPreventGet(
    "The ferns are securely rooted to the minaret."
  );
      break;

  case 1:
   SetShort("an opuntia cactus patch");
   SetLong(
    "Flat, rounded cladodes spring from the ground "
    "to make the bolk of this opuntia.  Smooth, long "
    "spines line its skin, protecting it from harm.  "
    "The cladodes are green with red "
    "sprouts at their tips, forming the new growth.  "
    "Small cactus figs sprout from it."
     );
  SetMaxCarry(100);
  inventory [MIN_OBJ + "/cactus_fig"] = random(3) +3,
  SetInventory(inventory);
   SetId( ({"opuntia", "cactus", "patch"}) );
   SetAdjectives( ({ "cactus", "patch" }) );
   SetKeyName("opuntia");
  SetPreventGet(
    "A sharp needle pricks your fingers!"
  );
      break;

  case 2:
   SetShort("a tall desert lily");
   SetLong(
    "A long green shaft grows out from a small bush "
    "to become the stem of this desert lily.  Numerous "
    "six petal white flowers sprout from the stem.  "
    "Their stigma is a soft yellow."
     );
  SetSmell( ([
    "default" : "The lily smells of honey.",
  ]) );
   SetId( ({ "lily"  }) );
   SetAdjectives( ({ "desert", "tall" }) );
   SetKeyName("lily");
  SetPreventGet(
    "You can't seem to pick that up."
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
