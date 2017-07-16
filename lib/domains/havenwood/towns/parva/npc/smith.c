#include <lib.h>
#include <vendor_types.h>
#include <std.h>
#include "../parva.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("carlos");
  SetId( ({ "carlos", "smith" }) );
  SetShort("Carlos the Smith");
  SetRace("human");
  SetClass("merchant");
  SetSkill("blunt combat", 1, 1);
  SetGender("male");
  SetLevel(35);
  SetMorality(250);
  SetLocalCurrency("oros");
  SetLong(
    "Carlos is a portly fellow whose face is always flushed by the heat "
    "of his forge. His arms are as big as an orc's from working long hours "
    "with the heavy hammers and anvils, but his smile is genuine, and he "
    "enjoys sharing his wares with the public."
    );
  SetMenuItems( ([
    "rapier"         : PARVA_OBJ "smith_rapier",
    "broadsword"     : PARVA_OBJ "smith_broadsword",
    "cutlass"        : PARVA_OBJ "smith_cutlass",
    "horseshoe"      : PARVA_OBJ "smith_horseshoe",
   ]) );
  SetLimit(1);
  SetInventory( ([
    PARVA_OBJ "smith_hammer" : "wield hammer",
    ]) );  
 }
