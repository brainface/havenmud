// Island
// Aerelus

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetArmourClass(ARMOUR_CLOTH);
  SetKeyName("robe");
  SetShort("a filthy loincloth");
  SetId( ({"loincloth"}) );
  SetAdjectives( ({"filthy"}) );
  SetLong(
    "This unattractive article of clothing provides little function other "
    "than concealing the lower genitalia of the wearer. It looks ancient, "
    "and has gathered enough dirt during its existence to make its original "
    "color a complete mystery."    
  );
  SetMass(20);
  SetValue(1);
  SetDamagePoints(50);
  SetWarmth(30);
  SetMaterial("textile");
  SetRepairDifficulty(1);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_PANTS);
  SetVendorType(VT_CLOTHING);
}
