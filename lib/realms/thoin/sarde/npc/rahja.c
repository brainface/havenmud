//
//  Rahja the potion seller
//  Created by: Rhakz@Haven -- Angel Cazares
//  For: Baria
//  Date: 06/04/99
//
#include <lib.h>
#include "../sarde.h"
#include <vendor_types.h>
inherit LIB_VENDOR;
  
static void create() {
  vendor::create();
  SetKeyName("Rahja");
  SetShort("Rahja the Alchemist and Potion Seller");
  SetId( ({"rahja", "draconian", "alchemist","seller","potion seller"}) );
  SetGender("female");
  SetAdjectives( ({ "skinny"}) );
  SetMorality(300);
  SetLong("This skinny draconian has spent most of her life creating potions "
          "and elixirs for many purposes. Her blue scales have a dark rusty "
          "tint due to the materials she is constantly in contact with. " 
          "She dwells in Sarde, selling her potions and elixirs to make a living."
         );
  SetRace("draconian");
  SetClass("merchant");
  SetLevel(45);
  SetTown("Sarde");
  SetLocalCurrency("chits");
  SetVendorType(VT_HERB|VT_PLANT|VT_MAGIC|VT_TREASURE);
  SetFriends( ({"Naj"}) );
  SetStorageRoom(SARDE_ROOM + "potion_str");
  SetMaxSingleItem(15);
}
