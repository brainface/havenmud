#include <lib.h>
#include "../grymxoria.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create()
{
  vendor::create();
  SetKeyName("jubbal");
  SetShort("Jubbal, the blacksmith");
  SetId( ({ "jubbal", "smith", "master" }) );
  SetAdjectives( ({ "master" }) );
  SetLong(
    "Jubbal is a master smith. His weapons are sought all "
    "across the land, and his repair skills are legendary. "
    "He also appears to know more about weapons than just how "
    "to make them well. Rumor says Jubbal use to fight along "
    "side Gunthar in his younger years."
  );
  SetRace("nosferatu");
  SetGender("male");
  SetClass("merchant");
  SetClass("fighter");
  SetLevel(30);
  SetVendorType(VT_WEAPON);
  SetTown("Grymxoria");
  SetLocalCurrency("bloodgems");
  SetStorageRoom(G_ROOM + "sr_bsmith.c");
  SetInventory( ([
    G_OBJ + "nosf_sword" : "wield sword",
  ]) );
}
