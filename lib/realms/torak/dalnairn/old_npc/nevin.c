// Dalnairn
// Aerelus

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_MAYOR;

static void create() {
  ::create();  
  SetKeyName("nevin");  
  SetId( ({ "nevin", "mayor", "dalnairn_people" }) );
  SetShort("Nevin the Mayor of Dalnairn");  
  SetLong(
    "Nevin is the mayor of Dalnairn. His responsibilities extend to welcoming "
    "new citizens and tending to the needs of existing ones. He is very "
    "friendly, unlike the majority of his race, making him the perfect "
    "Dark-dwarf for the job."    
  );
  SetFriends("dalnairn_people"); 
  SetRace("dark-dwarf");
  SetGender("male");
  SetClass("rogue");
  SetLevel(120); //torak 2012
  SetReligion("Soirin");
  SetMorality(-300);
  SetCurrency("shards", random(80));
  SetTown("Dalnairn");
  SetTax(50);
  SetLocalCurrency("shards");
  SetAction(5, ({
    "!speak How may I help you today?",
  }) );
  SetInventory( ([
         DAL_OBJ + "pants": "wear pants",
         DAL_OBJ + "shirt" : "wield shirt",
         DAL_OBJ + "shoes" : "wear shoes",
  ]) );
  SetTownRanks( ({
    ({ "Vassal", "Vassal" }),
    ({ "Clanbrother", "Clansister" }),
    ({ "Lord", "Lady" }),
    ({ "Counselor", "Counselor" }),
    ({ "Viceroy", "Viceroy" }),
    ({ "Holdmaster", "Holdmistress" }),
    ({ "Highlord", "Highlady" }),
    }) );
}
