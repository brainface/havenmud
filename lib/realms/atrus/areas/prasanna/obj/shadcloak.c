#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shadow cloak");
  SetId(( { "cloak" } ));
  SetAdjectives( ({ "shadow","black","velvet","shimmering" }) );
  SetShort("a shadowy cloak");
  SetLong("This mystically crafted cloak seems to bend light around itself "
          "and appears quite heavy.");
  SetMass(150);
  SetWarmth(18);
  SetValue(275);
  SetDamagePoints(500);
  SetProtection(PIERCE,2);
  SetProtection(SLASH,2);
  SetProtection(COLD,2);
  SetProtection(MAGIC,12);
  SetProtection(ACID,2);
  SetProperty("magic","The aura around this cloak protects from both physical and "
       "magic attacks."); 
  SetProperty("history","This cloak seems to be woven with death, and seeds fear"
       "deep within your soul.");  
  SetRestrictLimbs( ({ "torso" }) ); 
  SetArmourType(A_CLOAK);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetWear("The cloak winds around you and feels almost liquid against your skin.");
}

