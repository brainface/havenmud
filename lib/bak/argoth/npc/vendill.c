#include <lib.h>
#include "../argoth.h"
#include <vendor_types.h>
inherit LIB_VENDOR;
static void create() {
    vendor::create();
    SetKeyName("vendill");
    SetShort("Vendill the Grocer");
    SetRace("orc");
    SetClass("rogue");
    SetGender("male");
    SetLevel(12);
    SetLocalCurrency("khuca");
    SetVendorType(VT_TREASURE);
    SetStorageRoom(ARGOTH_ROOM + "gen_str.c");
    SetLong("Vendill has one of the safer jobs in Argoth, selling and bagging "
    "groceries and other everyday things.  His job lacks excitement, but he "
    "has little chance of being killed by someone wishing to rise up to his rank.");
}
