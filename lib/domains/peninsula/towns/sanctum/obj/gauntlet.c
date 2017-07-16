#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("gauntlet");
  SetShort("a plate mail gauntlet");
  SetId( ({ "gauntlet" }) );
  SetAdjectives( ({ "mail","plate" }) );
  SetArmourType(A_GLOVE);
  SetSize(SIZE_MEDIUM);
  SetLong("The gauntlet is made from a fine metal and appears to be extremely "
    "sturdy and durable. The fingers of the gauntlet are made from a different metal "
    "to offer more flexibility yet provide excellent protection to the wearer.");
  SetValue(1500);
  SetMass(50);
  SetDamagePoints(25000);
  SetArmourClass(ARMOUR_PLATE);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(85);
  SetWarmth(0);
  SetVendorType(VT_ARMOUR);
 }
