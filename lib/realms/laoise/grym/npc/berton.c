#include <lib.h>
#include "../grymxoria.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create()
{
  vendor::create();
  SetKeyName("berton");
  SetShort("Berton Bloodaxe, the armourer");
  SetId( ({
    "Berton", "Bloodaxe", "armourer", "nosferatu"
  }) );
  SetLong(
    "Berton is covered in dirt and persperation from "
    "spending the day working at the forge. He "
    "arrived in Grymxoria shortly after the priests of "
    "Saahagoth and quickly converted to the faith, "
    "after all war sells armour."
  );
  SetRace("nosferatu");
  SetGender("male");
  SetClass("merchant");
  SetClass("fighter");
  SetLevel(30);
  SetTown("Grymxoria");
  SetVendorType(VT_WEAPON);
  SetLocalCurrency("bloodgems");
  SetStorageRoom(G_ROOM + "sr_armoury");
  SetInventory(  ([
    G_OBJ + "nosf_sword" : "wield sword",
  ]) );
}
