#include <lib.h>

#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {

  armour::create();
  SetKeyName("ethereal cloak");
  SetId( ({ "cloak" }) );
  SetAdjectives( ({ 
    "ethereal", 
    "black", 
    "beautiful", 
    "velvet",
    "shimmering" 
    }) );
  SetShort("an ethereal cloak");
  SetLong("This beautifully crafted black velvet cloak "
          "seems to shimmer with its own soft light, even "
          "in the darkness. It looks quite capable of "
          "absorbing its fair share of damage, both "
          "real and magical.");
  SetMass(150);
  SetArmourClass(ARMOUR_CLOTH);
  SetWarmth(20);
  SetValue(250);
  SetDamagePoints(4000);
  // SetProtection(PIERCE,1);
  // SetProtection(SLASH,1);
  // SetProtection(COLD,2);
  // SetProtection(MAGIC,8);
  // SetProtection(ACID,2);
  SetProperty( "magic", 
    "The aura around this cloak protects from both physical and "
    "magic attacks."); 
  SetProperty( "history",
    "This cloak has travelled to many dimensions and back, perhaps "
    "bestowing it with strange magical properties.");  
  SetArmourType(A_CLOAK);
  SetVendorType(VT_CLOTHING);
  SetWear("The cloak makes you feel very well protected.");
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(25);
  SetSize(SIZE_MEDIUM);
  }
