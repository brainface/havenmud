// A soggy boot that you can get fishing HAHA! 
// For Platypus Bay 
// Urien@Haven 06JUL08 
#include <lib.h> 
#include <damage_types.h> 
#include <armour_types.h> 
#include <armour_class.h> 
#include <size.h> 
#include <vendor_types.h> 
inherit LIB_ARMOUR; 
inherit LIB_FISH; 
static void create() 
{ 
  armour::create(); 
  SetKeyName("leather boot"); 
  SetId(( { "leather","boot" } )); 
  SetAdjectives( ({ "leather" }) ); 
  SetShort("a slimy boot"); 
  SetLong( 
          "This boot is made of what appears to be soft leather. It " 
          "is covered in algea and mud. It looks as if it would not " 
          "provide any decent protection." 
          ); 
  SetMass(7); 
  SetValue(2); 
  SetDamagePoints(50); 
  SetFight(25); 
  SetArmourClass(ARMOUR_LEATHER); 
  SetSize(SIZE_MEDIUM); 
  SetArmourType(A_BOOT); 
  SetVendorType(VT_ARMOUR); 
  SetWear("The boot feels gross and slimy."); 
  SetMaterial( ({ "leather" }) ); 
  SetWarmth(2); 
  SetRepairDifficulty(1); 
  SetRepairSkills( ([ 
                      "armour smithing" : 1, 
                      "leather working" : 1, 
                 ]) ); 
} 
