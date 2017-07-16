// haven ferry captain
// mahk '10
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create(); 
  SetKeyName("jacket");
  SetShort("a dark naval jacket");
  SetId( ({ "jacket" }) );
  SetAdjectives( ({ "dark", "naval"  }) );
  SetLong(
    "This dark blue linen jacket is marked with a golden fleur de lis "
    "along each sleeve, probably denoting rank. The waist and sleeve "
    "buttons are carved from murky obsidian stones."
  );
  SetProperty("history",
    "An officer's jacket issued to seamen of the Duchy of "
    "Averath."
  );
  SetArmourClass(ARMOUR_CLOTH); 
  SetArmourType(A_CLOAK);
  SetDamagePoints(1200);
  SetMass(40);
  SetMaterials( ({ "textile" }) ); 
  SetSize(SIZE_MEDIUM);
  SetValue(0);
  SetWarmth(10);
}


