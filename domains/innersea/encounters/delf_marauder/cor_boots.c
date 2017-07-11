#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  
  SetKeyName("leather boots");
  SetId( ({ "boots" }) );
  SetAdjectives( ({ "leather", "laced", "black", "tall" }) );
  SetShort("laced leather boots");
  SetLong(
     "These tall black boots are made from a hardened leather. They "
     "lace up the front with a blood red leather string and cover to just "
     "below the knee. They appear to be quite durable."
     );
  SetMass(80);
  SetWarmth(5);
  SetValue(350);
  SetProperty("multiples", 1);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_BOOT);
  SetArmourClass(ARMOUR_LEATHER); 
  SetVendorType(VT_ARMOUR);
  SetMaterial( ({ "leather" }) );
  SetDamagePoints(3000);
  SetRepairDifficulty(25);
  
}
