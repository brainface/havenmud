#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("glass ring");
  SetId(( { "ring","glass ring"} ));
  SetShort("a glass ring");
  SetLong("Light refracts in an odd manner as it shines through the glass "
          "ring.");
  SetMass(1);
  SetValue(60);
  SetDamagePoints(75);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
    
  SetArmourType(A_RING);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  
  SetWear("The ring slips on your finger.");
}
