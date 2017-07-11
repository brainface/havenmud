#include <lib.h>
#include <vendor_types.h>
#include <domains.h>
#include "../nat_store.h"

inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("talamar");
  SetId( ({ "talamar", "taxidermist" }) );
  SetShort("talamar the Taxidermist");
  SetAdjectives( ({ "leather" }) );
  SetLong(
    "Talamar is a hulking brute of an elf, standing head and shoulders over his "
    "cousins. He's known around the havenwood for making animal skins into "
    "useful things like armour and shields, as well as less useful things like "
    "mounted heads. His armour is known to be extremely protective, if somewhat "
    "feral-looking."
  );
  SetRace("wild-elf");
  SetGender("male");
  SetBaseLanguage("Eltherian");
  SetLocalCurrency("imperials");
  SetTown("Havenwood");
  SetMorality(100);
  SetClass("merchant");
  SetLevel(30);
  AddCurrency("imperials", random(500)+500);
  SetStorageRoom(NAT_STORE_ROOM "store");
  SetVendorType(VT_ARMOUR);

  SetInventory( ([
    NAT_STORE_OBJ "prop_broom" : "wield broom",
    NAT_STORE_OBJ "nat_leggings" : "wear leggings",
    NAT_STORE_OBJ "nat_shirt" : "wear shirt",
  ]) );
}

