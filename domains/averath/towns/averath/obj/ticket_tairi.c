#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("tairi ticket");
  SetProperty("averath_charter_ticket", "tairi");
  SetShort("a charter ferry ticket");
  SetId( ({ "ticket" }) );
  SetAdjectives( ({ "tairi", "ferry", "charter" }) );
  SetValue(100);
  SetMass(1);
  SetVendorType(VT_TREASURE);
  SetLong(
    "This ticket entitles the bearer to a one-way trip to Tairi from "
    "the charter ferry in Averath."
    );
}
