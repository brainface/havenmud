// Dalnairn
// Aerelus

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shield");
  SetId( ({ "shield", "large shield" }) );
  SetShort("a large metal shield");
  SetLong(
    "This large metal shield looks like it would offer the wearer "
    "great protection against physical attacks. It looks like it could take "
    "a lot of damage."
  );
  SetAdjectives( ({ "metal", "large" }) );
  
  SetRepairDifficulty(10);  
  SetMaterial( ({ "metal" }) );  
  SetDamagePoints(2000);
  SetValue(150);
  SetArmourClass(ARMOUR_PLATE);
  SetMaterial( ({ "metal" }) );
  SetSize(SIZE_SMALL);
  SetArmourType(A_SHIELD);
  SetMass(350);
    
 }
