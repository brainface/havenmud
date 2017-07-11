#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shield");
  SetId( ({ "shield" }) );
  SetAdjectives( ({ "large", "black" }) );
  SetShort("large black shield");
  SetLong(
    "This single piece of black metal has been shaped in to a large shield "
    "with a handle grip riveted to the back. Its front is unadorned, with "
    "creases and rivets only where needed to give it strength and durability. "
  );
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetArmourType(A_SHIELD);
  SetSize(SIZE_LARGE);
  SetValue(150);
  SetMass(100);
  SetDamagePoints(1000);
  SetWarmth(0);
  SetMaterial( ({ 
  	"metal", 
  }) );
  SetRepairDifficulty(25);  
}
