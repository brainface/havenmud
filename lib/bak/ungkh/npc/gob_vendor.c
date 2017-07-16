#include <lib.h>
#include "../ungkh.h"
#include <vendor_types.h>

inherit LIB_VENDOR;

static void create() {
  vendor::create();

  SetKeyName("merchant");
  SetAdjectives( ({
    "dirty","ugly"
    }) );
  SetId( ({
    "goblin","merchant","citizen"
    }) );

  SetShort("Gobskork, the merchant");
  SetLong("This merchant is busy and constantly writing on "
          "parchment.  The goblin runs this little store with quiet "
          "splendor.  He is always trying to sell his merchandise.");

  SetRace("goblin");
  RemoveLanguage("Gobyshkin");
  SetLanguage("Uruk",100,1);
  SetClass("merchant");
  SetSkill("knife attack" , 1, 52);
  SetLevel(45);
  SetGender("male");
  SetInventory( ([
    U_OBJ + "gob_knife" : "wield knife",
    U_OBJ + "gob_loincloth" : "wear loincloth",
    ]) );
  SetLocalCurrency("skins");
  SetStorageRoom(U_ROOM + "gen_store");
  SetMaxItems(65);
  SetVendorType(VT_ALL);
  SetAction(1, ({"!yell Shiny, Glittery Things for sale!",
                 "!say you wanna buy somtin?",
                 }) );
  SetMorality(-100);
  SetCurrency("skins",123 + random(75) );
  SetDie("The goblin squeaks like a pig.");
}
