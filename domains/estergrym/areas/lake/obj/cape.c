/* cape Tassadar 11/27/99*/
#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h> 

inherit LIB_ARMOUR; 

 static void create() { 
  armour::create(); 
  SetKeyName("cape");
  SetShort("anhinga's cape"); 
  SetId( ({ "cape" }) ); 
  SetAdjectives( ({ "blue","silk","embroidered" }) ); 
  SetLong("This cape was worn by a great person, " 
          "strange to find it, left behind in perfect " 
          "shape. It is dark blue and waterproof " 
          "to protect against the elements."); 
  SetMass(30); 
  // SetProtection(SLASH, 3);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  // SetProtection(BLUNT, 4);
  // SetProtection(PIERCE, 3);
  // SetProtection(COLD, 6);
  // SetProtection(HEAT, 1);
  // SetProtection(ACID, 2);
  // SetProtection(WATER, 7);
  // SetProtection(GAS, 2);
  // SetProtection(MAGIC, 1);
  // SetProtection(SHOCK, 1);
  SetValue(80); 
  SetDamagePoints(900);
  SetVendorType(A_CLOAK);
  SetMaterial("textile"); 
  SetRepairDifficulty(10);
  SetWarmth(20);
  SetArmourType(A_CLOAK);
 }
