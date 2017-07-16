/* EnjilCode */


#include <lib.h>
#include "../ungkh.h"
#include <vendor_types.h>

inherit LIB_VENDOR;

static void create() {
  vendor::create();

  SetKeyName("Gobskork");
  SetAdjectives( ({
    "dirty","ugly"
    }) );
  SetId( ({
    "goblin","merchant","gobskork",
    }) );

  SetShort("Gobskork, the merchant");
  SetLong("Gobskork is busy and constantly writing on "
          "parchment.  He runs this little store with quiet "
          "splendor.  He is always trying to sell his merchandise.");

  SetRace("goblin");
  SetClass("merchant");

  SetSkill("knife attack" , 1, 52);

  SetLevel(45);
  SetGender("male");

  SetInventory( ([
    U_OBJ + "gob_knife" : "wield knife",
    U_OBJ + "gob_loincloth" : "wear loincloth",
    ]) );

  SetLocalCurrency("skins");
  SetStorageRoom(U_ROOM + "gobskork_store");
  SetMaxItems(65);
  SetVendorType(VT_ALL);

  RemoveLanguage("Gobyshkin");
  SetLanguage("Uruk",100,1);
  SetAction(1, ({"!yell Shiny, Glittery Things for sale!",
                 "!say you wanna buy somtin?",
                 }) );

  SetMorality(-500);
  SetCurrency("skins",123 + random(75) );

  SetDie("The goblin squeaks like a pig.");

}
