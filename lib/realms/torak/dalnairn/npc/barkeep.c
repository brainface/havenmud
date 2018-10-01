// Dalnairn
// Aerelus
// edited for dalnairn recode
// torak@haven 2017

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("aulay");    
  SetId( ({ "aulay", "barkeep", "dalnairn_person" }) );
  SetShort("Aulay the Barkeep");
  SetLong(
    "Aulay is the owner of the tavern in Dalnairn. He is a friendly man, "
    "though is always on the lookout for potential troublemakers. He "
    "generally turns a blind eye towards the local thieves, and has even "
    "been known to endulge himself from time to time."    
  );
  SetFriends("dalnairn_people");
  SetRace("dark-dwarf");
  SetGender("male");
  SetClass("merchant");
  SetLevel(10);
  SetReligion("Soirin");
  SetMorality(-50);
  SetCurrency("shards", 50);
  SetAction(2, ({
    "!speak So, what will it be?",
    "!speak Try our orange shandy, you can't beat it.",    
  }) );
  SetInventory( ([
         DAL_ARM + "pants": "wear pants",
         DAL_ARM + "shirt" : "wear shirt",
         DAL_ARM + "shoes" : "wear shoes",
  ]) );
  
  SetMenuItems( ([ 
    "whisky"  : DAL_MEAL "whisky",
    "red ale" : DAL_MEAL "red_ale",
    "nuts"    : DAL_MEAL "nuts",
    "shandy"  : DAL_MEAL "orange_shandy",
    "sangria" : DAL_MEAL "orange_sangria",
  ]) );
  SetLocalCurrency("shards");  
}
