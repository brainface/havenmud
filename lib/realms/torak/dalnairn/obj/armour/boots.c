// Dalnairn
// Aerelus

#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetId( ({"boots"}) );
  SetShort("a pair of sturdy boots");  
  SetLong(
    "These sturdy boots have been made from very tough leather, providing "
    "protection as well as some warmth. They seem very comfortable."
  );
  SetAdjectives( ({"sturdy", "pair of",}) );
  
  SetValue(70);
  SetMass(60);
  SetMaterial( ({"leather"}) );
  SetWarmth(5);
  SetProperty("multiples", 1);  
  SetRepairDifficulty(40);
  SetSize(SIZE_SMALL);
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_BOOT);
  SetVendorType(VT_ARMOUR);  
}