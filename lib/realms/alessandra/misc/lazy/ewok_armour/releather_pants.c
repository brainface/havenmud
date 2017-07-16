//   Ewok reinforced armour   //

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("studded leather pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "studded", "leather", "pair of" }) );
  SetMaterials( ({ "leather" }) );
  SetRepairDifficulty(15);
  SetShort("a pair of studded leather pants");
  SetLong("This pair of plain leather pants has been reinforced with "
     "hardened leather. Iron rivets form a line down each leg. These "
     "pants are much sturdier than normal leather.");
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_REINFORCED);
  SetSize(SIZE_SMALL);
  SetMass(40);
  SetWarmth(15);
  SetValue(100);
  SetDamagePoints(450);
  SetArmourType(A_PANTS);
}
