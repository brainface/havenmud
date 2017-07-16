//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
//

#include <lib.h>
#include <std.h>
#include "../dalnairn.h"
inherit LIB_BARKEEP;

static void create() {
  ::create();
  SetKeyName("gromrarra");    
  SetId( ({ "aulay", "fisherwoman", "dalnairn_person" }) );
  SetShort("Gromrarra the Fisherwoman");
  SetLong(
    "Gromrarra is a stout dark-dwarf with long flowing black hair. "
    "Her pale green eyes always scanning her surroundings. "
    "Her skin is weathered with the salty air, giving her a leathery "
    "appearance.",
  );
  SetFriends("dalnairn_people");
  SetRace("dark-dwarf");
  SetGender("female");
  SetClass("merchant");
  SetLevel(10);
  SetReligion("Soirin");
  SetMorality(-50);
  SetCurrency("shards", 50);
  SetAction(5, ({
    "!fish with my first pole",
    "!speak Get your lobster cages from me.",    
  }) );
  SetInventory( ([
    STD_OBJ "fishing/pole" : 1,
    DAL_ARM + "pants": "wear pants",
    DAL_ARM + "shirt" : "wear shirt",
    DAL_ARM + "shoes" : "wear shoes",
  ]) );
  
  SetMenuItems( ([ 
    "lobster cage"  : DAL_OBJ "lobster_cage",
  ]) );
  SetLocalCurrency("shards");  
}
