#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_WORN_STORAGE;
static void create() {
  ::create();
  SetKeyName("leather pouch");
  SetSize(SIZE_MEDIUM);
  SetId( ({ "pouch", }) );
  SetAdjectives( ({ "medium", "leather", }) );
  SetShort("a medium leather pouch");
  SetLong("The quality of the pouch is incredible, it looks like it will "
          "last for years.");
  SetMass(2);
  SetValue(20);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(45);
  SetArmourType(A_BELT);
  SetVendorType(VT_ARMOUR);
}

