// Dalnairn
// Aerelus

#include <lib.h>
#include "../dalnairn.h"
#include <vendor_types.h>
inherit LIB_OLD_VENDOR;

static void create() {
  ::create();
  SetKeyName("sionn");
  SetId( ({ "sionn", "merchant", "dalnairn_people" }) );
  SetShort("Sionn the Wealthy Merchant");
  SetLong(
  "Sionn is a very wealthy man. He has cornered almost all of the "
  "business in Dalnairn by often dishonourable means, though is still looked "
  "up to in the community. He seems willing to buy and sell most items."
  );
  SetFriends("dalnairn_people"); 
  SetMorality(-200);
  SetRace("dwarf");
  SetClass("merchant");
  SetLevel(20);
  SetSkill("bargaining", 120, 1);
  SetGender("male");
  SetVendorType(VT_ALL);
  SetLocalCurrency("shards");
  SetStorageRoom(DAL_ROOM "storage/shop");
  SetMaxSingleItem(25);
  SetMaxItems(800);
  SetAction(5, ({
    "!speak Would you like to see what I have for sale today?",
  }) );
  SetInventory( ([
         DAL_OBJ + "pants": "wear pants",
         DAL_OBJ + "shirt" : "wield shirt",
         DAL_OBJ + "shoes" : "wear shoes",
  ]) );
}
