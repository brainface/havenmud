// cotton trousers for tairi captain

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create(); 
  SetKeyName("trousers");
  SetId( ({ "trousers" }) );
  SetAdjectives( ({ "cotton", "pair", "of" }) );
  SetShort("a pair of cotton trousers");
  SetLong(
    "This pair of white cotton trousers is "
    "very loose, and would comfortably fit most people even "
    "in a hot climate." 
  );
  SetArmourClass(ARMOUR_CLOTH); 
  SetArmourType(A_PANTS);
  SetDamagePoints(1200);
  SetMass(30);
  SetMaterials( ({ "textile" }) ); 
  SetSize(SIZE_MEDIUM);
  SetValue(0);
  SetVendorType(VT_CLOTHING); 
  SetWarmth(5);
}

