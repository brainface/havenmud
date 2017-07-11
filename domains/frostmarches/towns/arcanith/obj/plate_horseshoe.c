// Mahkefel Dec 16 2010
#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;
int checkHoof();
static void create() {
  armour::create();
  SetKeyName("horseshoe");
  SetId(( {"horseshoe"} ));
  SetShort("a salvaged steel horseshoe");
  SetAdjectives( ({"steel", "salvaged"}) );
  SetLong(
    "This old horseshoe looks like it was used to shoe a pony "
    "or small riding horse. Whatever its usage, it shoes the marks "
    "of years of wear, and a bad crack along the left side has been "
    "reforged with steel of a slightly different color."
  );
  SetMass(250);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(4000);
  SetDamagePoints(4000);
  SetArmourType(A_SOCK);
  SetWear( (: checkHoof :) );

  // Doesn't do a damned thing
  // SetRestrictLimbs( ({"right hoof", "left hoof"}) );
  //SetWear("You nail the horseshoe carefully to your hoof.");
}

int checkHoof() {
  object dude = this_player();
  if (dude->GetLimb("left hoof") || dude->GetLimb("right hoof") ) {
    dude->eventPrint("You nail the horseshoe carefully to your hoof.");
    return 1;
  } else {
    dude->eventPrint("You have better things to do than nailing a "
      "horseshoe to your foot.");
    return 0;
  }
}
