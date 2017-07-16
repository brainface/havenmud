#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("biretta");
  SetShort("a red biretta");
  SetId( ({ "biretta" }) );
  SetAdjectives( ({ "red" }) );
  SetLong("This square shaped hat is bright red, and looks reasonably "
          "comfortable. It has three peaks, and is surmounted by a tuft.");  
  SetVendorType(VT_CLOTHING);
  SetMaterial("textile");
  SetRepairDifficulty(10);
  SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(40);
  SetValue(400);
  SetDamagePoints(250);
  SetSize(SIZE_MEDIUM);
  }
