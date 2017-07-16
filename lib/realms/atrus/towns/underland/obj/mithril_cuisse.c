#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cuisse");
  SetId(( {"cuisse"} ));
  SetShort("a mithril platemail cuisse");
  SetAdjectives( ({"mithril", "chainmail"}) );  
  SetLong(
    "This cuisse is made of the finest quality mithril "
    "plates that have been inter-locked to allow a wide "
    "range of motion. The edge of each plate has gold "
    "scrollwork etched into the mithril."    
  );   
  SetMass(400);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("mithril");
  SetWarmth(0);
  SetRepairDifficulty(90);
  SetValue(4000);
  SetDamagePoints(40000);
  SetArmourType(A_PANTS);  
  SetWear("The mithril plates shift around your legs to settle comfortably.");
}
