#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
#include "../path.h"
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("hemp amulet");
  SetShort("a hemp amulet");
  SetId( ({ "hemp","amulet","hemp amulet" }) );
  SetAdjectives( ({ "hemp" }) );
  SetLong("The hemp amulet is just some braided hemp that has been "
          "tied together to form a circle.");
  SetMass(4);
  SetSize(SIZE_SMALL);
  SetValue(15);
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_AMULET);
  SetVendorType(VT_ARMOUR);
  SetDamagePoints(225);
  // SetProtection(PIERCE,1);
  // SetProtection(SLASH,1);
  // SetProtection(BLUNT,1);
  SetWear("The hemp wraps close to your neck.");
  SetMaterial( ({ "natural" }) );
  SetWarmth(0);
  SetRepairDifficulty(23);
  SetRepairSkills( ([
    "natural working" : 3,
    "armour smithing" : 1,
  ]) );
}
