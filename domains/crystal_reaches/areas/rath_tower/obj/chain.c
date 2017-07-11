#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("chainmail");
  SetProperty("magic",
     "This armour has some resistance to magic.");
  SetShort("a vest of aged chainmail");
  SetId( ({ "vest", "chainmail" }) );
  SetAdjectives( ({ "chainmail", "aged" }) );
  SetLong("This fine suit of chainmail is used by the soldiers of \n"
         "Rath Khan as standard issue.  Its deeply runed metals \n"
         "bear the marks of a true master.");
  SetDamagePoints(1200);
  SetValue(1800+random(500));
  SetArmourClass(ARMOUR_CHAIN);
  SetMass(300);
  SetArmourType(A_VEST);
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(15);
  SetWarmth(0);
  // SetProtection(BLUNT, 8);
  // SetProtection(SLASH, 12);
  // SetProtection(PIERCE, 6);
  // SetProtection(MAGIC, 2);
 }
