/*  A test bag of smoothness */
#include <lib.h>
#include <vendor_types.h>
inherit LIB_STORAGE;

static void create() {
  storage::create();
  SetKeyName("bag");
  SetShort("a small bag");
  SetMaxCarry(-1);
  SetLong("This is a small bag made of leather.");
  SetProperty("magic", "This is a bag of infinite holding.");
  SetMass(1);
  SetValue(4500);
  SetAdjectives( ({ "small" }) );
  SetMaterial( ({ "leather" }) );
  SetVendorType(VT_TREASURE|VT_MAGIC);
  }

int GetMass() {
  return (1);
  }
