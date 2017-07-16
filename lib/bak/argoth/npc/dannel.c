#include <lib.h>
#include "../argoth.h"
#include <vendor_types.h>
inherit LIB_VENDOR;
static void create() {
    vendor::create();
    SetKeyName("dannel");
    SetShort("Dannel, the Armourer");
    SetRace("orc");
    SetClass("rogue");
    SetGender("male");
    SetLevel(8);
    SetLocalCurrency("khuca");
    SetVendorType(VT_ARMOUR);
    SetStorageRoom(ARGOTH_ROOM + "arm_str.c");
    SetLong("Dannel is the most skilled armour maker in Argoth.  His shop is "
    "full of armour that he crafted, and armour that he bought or traded for.");
}
