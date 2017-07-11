/*  Davantalus@Haven 20060224
     Wedding pumps for luna.
*/

#include <lib.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("heels");
  SetShort("a pair white high heels");
  SetId( ({ "heels" }) );
  SetAdjectives( ({ "white", "pair of", "high"}) );
  SetLong(
    "These beautiful sparkling white high heals were created by a skilled "
    "shoemaker for the marriage of Luna An'Duheart to Atrus. In addition to "
    "making one's legs look sexy, they raise one off the floor by 2 inches. "
    "Small glass shards attached to the heels sparkle beautifully in the light."
    );
  SetValue(300);
  SetMass(10);
  SetMaterial( ({ "leather" }) );
  SetWarmth(3);
  SetArmourType(A_BOOT); 
  SetProperty("multiples", 1);
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
}
