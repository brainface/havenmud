#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("beanie");
  SetShort("a cute pink beanie");
  SetId( ({ "beanie" }) );
  SetAdjectives( ({ "cute", "pink" }) );
  SetLong("This cute little hat is entirely pink. Made from a soft wool, it "
  				"looks like it would do a great job of keeping the wearer's head and ears "
  				"warm during the colder months.");
  SetVendorType(VT_CLOTHING);
  SetMaterial("textile");
  SetRepairDifficulty(10);
  SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(40);
  SetWarmth(30);
  SetValue(50);
  SetDamagePoints(500);
  SetSize(SIZE_MEDIUM);
  }
