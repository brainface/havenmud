#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("haven ticket");
  SetProperty("averath_charter_ticket", "haven");
  SetShort("a charter ferry ticket");
  SetId( ({ "ticket" }) );
  SetAdjectives( ({ "haven", "ferry", "charter" }) );
  SetValue(100);
  SetMass(1);
  SetVendorType(VT_TREASURE);
  SetLong(
    "This ticket entitles the bearer to a one-way trip to Haven from "
    "the charter ferry in Averath."
    );
}

