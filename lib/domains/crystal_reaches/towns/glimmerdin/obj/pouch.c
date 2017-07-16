#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_STORAGE;

static void create() {
  ::create();
  SetKeyName("leather pouch");
  SetId( ({ "pouch", }) );
  SetAdjectives( ({ "small", "leather", }) );
  SetMaterials( ({ "leather" }) );
  SetShort("a small leather pouch");
  SetLong("The quality of the pouch is incredible, it looks like it will "
          "last for years.");
  SetMass(2);
  SetValue(10);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(45);
  
  SetVendorType(VT_CLOTHING);
  
}

