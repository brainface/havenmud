// Dalnairn
// Aerelus

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetKeyName("wuach"); 
  SetId( ({ "wuach", "banker", "teller", "dalnairn_people" }) );
  SetShort("Wuach the Banker");  
  SetLong(
    "Wuach is the manager of the Bank of Dalnairn. He is one of the taller "
    "members of his race, a feature he finds useful for putting off would-be "
    "robbers. He is well known throughout the city for providing a safe place "
    "to store money."
  );
  SetFriends("dalnairn_people");
  SetRace("dark-dwarf");
  SetGender("male");
  SetClass("rogue");
  SetLevel(15);
  SetReligion("Soirin");
  SetMorality(-200);
  SetCurrency("shards", random(100));
  SetAction(5, ({
    "!speak Your money will be safer with me.",
  }) );
  SetInventory( ([
         DAL_OBJ + "pants": "wear pants",
         DAL_OBJ + "shirt" : "wield shirt",
         DAL_OBJ + "shoes" : "wear shoes",
  ]) );
  
  SetBankName("the Bank of Dalnairn");
  SetLocalCurrency("shards");
  SetCurrencies( ({
    "shards", "imperials",
  }) );
  SetLocalFee(0);
  SetNonLocalFee(2);
  SetTown("Dalnairn");
  SetExchangeFee(0.03);  
}
