#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("parva ticket");
  SetProperty("averath_charter_ticket", "parva");
  SetShort("a charter ferry ticket");
  SetId( ({ "ticket" }) );
  SetAdjectives( ({ "parva", "ferry", "charter" }) );
  SetValue(100);
  SetMass(1);
  SetVendorType(VT_TREASURE);
  SetLong(
    "This ticket entitles the bearer to a one-way trip to Parva from "
    "the charter ferry in Averath."
    );
}

