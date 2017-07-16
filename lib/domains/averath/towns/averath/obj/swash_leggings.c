//   Fancy Pants for swashbucklers
//   Aless 2011

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  
  SetKeyName("leggings");
  SetId( ({ "leggings" }) );
  SetAdjectives( ({ "pair of", "leather", "brown", "deep brown" }) );
  SetShort("a pair of leather leggings");
  SetLong(
     "Stitched with careful precision, these deep brown leather "
     "leggings cling like a second skin. The suppleness of the fine "
     "leather allowing greater freedom of movement for those "
     "more refined persons of action."
     );
  SetMass(100);
  SetWarmth(5);
  SetValue(600);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_PANTS);
  SetArmourClass(ARMOUR_LEATHER); 
  SetVendorType(VT_ARMOUR);
  SetMaterial( ({ "leather" }) );
  SetDamagePoints(3000);
  SetRepairDifficulty(25);
  
}
