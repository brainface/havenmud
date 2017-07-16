// Dalnairn
// Aerelus

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
  SetRace("dwarf");
  SetGender("male");
  SetClass("merchant");
  SetLevel(10);
  SetReligion("Soirin");
  SetMorality(-50);
  SetCurrency("shards", 50);
  SetAction(2, ({
    "!speak So, what will it be?",
    "!speak Try our locally distilled scotch, you can't beat it.",    
  }) );
  SetInventory( ([
         DAL_OBJ + "pants": "wear pants",
         DAL_OBJ + "shirt" : "wield shirt",
         DAL_OBJ + "shoes" : "wear shoes",
  ]) );
  
  SetMenuItems( ([ "whisky" : DAL_OBJ "whisky",
                   "ale"  : "/std/meal/beer.c",
                   "nuts" : DAL_OBJ "nuts",
  ]) );
  SetLocalCurrency("shards");  
}
