#include <lib.h>
#include "../haven.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create() {
::create();
SetKeyName("talnif");
SetId( ({ "talnif", "mixer", "apothecary" }) );
SetShort("talnif, Mixer of Medicine");
SetLong("Talnif is a lanky half-elf, who spends his days"
"brewing potions for the largely thankless haven citizenry. "
"His fingers are stained a noxious green from constant handling "
"of various herbs."
);
SetMorality(100);
SetRace("half-elf");
SetClass("merchant");
SetLevel(20);
SetTown("Haven");
SetReligion("Eclat");
SetGender("male");
SetVendorType(VT_PLANT|VT_HERB);
SetLocalCurrency("imperials");
SetStorageRoom(H_ROOM "storage_rooms/str_pots");
SetMaxSingleItem(6);
SetMaxItems(100);
}

