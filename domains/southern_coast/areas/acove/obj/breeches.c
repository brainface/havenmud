  /* Lucie's breeches
  Zara 8/15/98 
*/
#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("breeches");
  SetShort("cloth breeches");
  SetId( ({"breeches","pants"}) );
  SetAdjectives( ({"ladie's","sturdy","blue"}) ); 
  SetLong("These ladie's breeches are made of sturdy "
          "cloth and are royal blue.");
  SetMass(30);
  SetValue(50); 
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(100);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  // SetProtection(BLUNT, 3);
  // SetProtection(SLASH, 2);
  // SetProtection(HEAT, 3);
  // SetProtection(COLD, 4);
  // SetProtection(SHOCK, 3);
  // SetProtection(WATER, 1);
  // SetProtection(ACID, 1);
  SetMaterial("textile");
  SetRepairDifficulty(25);
  SetArmourType(A_PANTS);
}
