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
  SetKeyName("shoes");
  SetId( ({"shoes"}) );
  SetShort("a pair of comfortable shoes");  
  SetLong(
    "These shoes are made of a tough fabric, though are well padded. They "
    "look very comfortable, and should offer reasonable protection to the "
    "wearer."    
  );
  SetAdjectives( ({"comfortable", "pair of",}) );
  
  SetValue(50);
  SetMass(40);
  SetMaterial( ({"leather"}) );
  SetWarmth(5);
  SetProperty("multiples", 1);  
  SetRepairDifficulty(40);
  SetSize(SIZE_SMALL);
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_BOOT);
  SetVendorType(VT_ARMOUR);  
}