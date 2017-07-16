#include <lib.h>
#include "../averath.h"
inherit LIB_MAYOR;

static void create() {
   mayor::create();
   SetKeyName("Louis de Lioncourt");
   SetId( ({ "louis", "lioncourt", "assessor", "averath_person" }) );
   SetShort("Louis de Lioncourt the Royal Assessor");
   SetLong(
     "Louis de Lioncourt is the Royal Assessor for the Grand Duchy. It is he "
     "that determines if persons from outside the Grand Duchy should be "
     "granted citizenship, and also determines if the prerequisites for "
     "social advancement."
   );
   SetAdjectives( ({ "louis", "de", "royal" }) );
   
   SetRace("human");
   SetGender("male");
   SetBaseLanguage("Avera");
   SetReligion("Aetarin");
   SetLocalCurrency("ducats");
   
   SetMorality(0);
   SetClass("priest");
   SetSkill("melee combat",1,2);
   SetLevel(80);
   AddCurrency("ducats", random(150)+100);
   
   SetTax(5000);
   SetTown("Averath");   
   
   SetInventory( ([
   ]) );
     
   /*SetFirstCommands( ({ 
     "cast barrier of faith",
     "cast barrier of faith",
     "cast barrier of faith",
     "cast barrier of faith",
     "cast barrier of faith",
   }) );*/
   
   SetLimit(1);
   SetTax(5000);
   SetTown("Averath");
   
   /*SetSpellBook( ([
     "barrier of faith" : 100,
     "harm body"   : 100,     
   ]) );*/
   
   SetAction(5, ({ 
     "!speak The Grand Duchy of Averath is a plentiful land." 
   }));
     
   /*SetCombatAction(5, ({ 
   	"!cast harm body",   	
   }) );*/
   	
   SetTownRanks( ({
    ({ "Serf", "Serf" }),
    ({ "Citizen", "Citizen" }),
    ({ "Squire", "Squire" }),
    ({ "Seignoir", "Seignoire" }),
    ({ "Count", "Comte" }),
    ({ "Marquis", "Marquise" }),
    ({ "Prince", "Princess" }),
    }) );
}