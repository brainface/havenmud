#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("lisht ticket");
  SetProperty("parva_charter_ticket", "lisht");
  SetShort("a charter ferry ticket");
  SetId( ({ "ticket" }) );
  SetAdjectives( ({ "lisht", "ferry", "charter" }) );
  SetValue(100);
  SetMass(1);
  SetVendorType(VT_TREASURE);
  SetLong(
    "This ticket entitles the bearer to a one-way trip to Lisht from "
    "the charter ferry in Parva."
    );
}

