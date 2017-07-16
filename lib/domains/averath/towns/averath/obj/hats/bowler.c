#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("bowler hat");
  SetShort("a black bowler hat");
  SetId( ({ "hat" }) );
  SetAdjectives( ({ "black", "bowler" }) );
  SetLong("This black bowler hat looks big enough to fit the average "
   			  "sized head comfortably. Made from a fine fabric, it looks expensive.");  
  SetVendorType(VT_CLOTHING);
  SetMaterial("textile");
  SetRepairDifficulty(10);
  SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(40);
  SetValue(300);
  SetDamagePoints(250);
  SetSize(SIZE_MEDIUM);
  }
