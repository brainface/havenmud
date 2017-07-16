#include <lib.h>
#include "../argoth.h"
#include <vendor_types.h>
inherit LIB_VENDOR;
static void create() {
    vendor::create();
    SetKeyName("garret");
    SetShort("Garret the Forger");
    SetRace("orc");
    SetClass("fighter");
    SetGender("male");
    SetLevel(16);
    SetLocalCurrency("khuca");
    SetVendorType(VT_WEAPON);
    SetStorageRoom(ARGOTH_ROOM + "wpn_str.c");
    SetLong("Garret is a large bulky orc with only one eye.  Because of this "
    "disability, he was deemed unfit to serve as a footsoldier in the orkish "
    "hordes, and instead opened up a weapon shop.  He still looks as though he "
    "would be quite effective in combat.");
}
