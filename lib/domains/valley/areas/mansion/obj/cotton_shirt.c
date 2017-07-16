/* a shirt for servants of the mansion
   kyla 3-98
*/
#include <lib.h>
#include <armour_class.h>
#include "../mansion.h"
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;


static void create() {
  armour::create();
  SetKeyName("cotton shirt");
  SetId( ({ "shirt" }) );
  SetAdjectives( ({"cotton", "white" }) );
  SetShort("a white cotton shirt");
  SetLong("This cotton shirt looks to be very durable and practical."
          " It is quite dirty and looks as though it has been through alot.");
  SetMass(50);
  SetVendorType(VT_ARMOUR);
  SetMaterials( ({"textile"}) );
  SetArmourClass(ARMOUR_CLOTH);
  SetWarmth(10);
  SetValue(55);
  SetDamagePoints(100);
  SetArmourType(A_SHIRT);
  }
