#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
  SetKeyName("butterfly wing");
  SetShort("butterfly wing");
  SetId( ({ "wing" }) );
  SetAdjectives( ({ "butterfly" }) );
  SetLong(
    "This butterfly wing is delicate and simple. Glorious "
    "designs and colors decorate it. Delicate black lines run "
    "across it, defining the different colored areas."
  );
  SetMass(1);
  SetValue(10);
  SetVendorType(VT_TREASURE);
  SetDamagePoints(5);
}


/* Approved by Zaxan on Sat Jan 17 02:50:22 1998. */
