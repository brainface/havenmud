#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("gauntlet");
  SetShort("a black bone gauntlet");
  SetId( ({ "gauntlet" }) );
  SetAdjectives( ({ "black","bone" }) );
  SetArmourType(A_GLOVE);
  SetSize(SIZE_VERY_SMALL);
  SetLong("The gauntlet is made up of a bones from different animals. It has been "
    "designed to fit comfortably on your hand. The gauntlet was dipped in a black "
    "laquer to greatly raise its durability and strength. ");
  SetValue(1000);
  SetMass(25);
  SetDamagePoints(10000);
  SetArmourClass(ARMOUR_NATURAL);
  SetMaterial( ({ "natural" }) );
  SetRepairDifficulty(50);
  SetWarmth(0);
  SetVendorType(VT_ARMOUR);
 }
