
#include <lib.h>
inherit LIB_LEADER;
#include "../rome.h"

static void create() {
   ::create();
  SetKeyName("acclima");
  SetShort("Acclima, Spirtual Teacher of Eclat");
  SetId( ({ "acclima","teacher","priest" }) );
  SetAdjectives( ({ "spiritual", "teacher", "of", "eclat" }) );
  SetLong("Acclima smiles happily, having retained the joy of her "
          "tribe while becoming Eclat by faith.  She loves dealing "
          "with nature and the surrounding world, so has worked "
          "hard at improving her skills.  It appears as if she "
          "has succeeded in many ways.");
  SetRace("human");
  SetClass("druid");
  SetGender("female");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetReligion("Eclat","Eclat");
  SetLevel(48);
  SetPlayerTitles( ([
       "newbie" : "the Caregiver",
       "mortal" : "the Child of the Forest",
       "hm"     : "the Practiced Druid",
       "legend" : "the Druidic Master",
       "avatar" : "the Protector of Sacred Forests",
   ]) );
  SetSpellBook( ([
       "heat"           : 100,
       "vine wall"      : 100,
       "create rose"    : 100,
       "enhance joy"    : 100,
       "natural charge" : 100,
       "freeze"         : 100,
       "tangle"         : 100,
       "create natural herb" : 100,
       ]) );
  SetCombatAction(80, ({
  	   "!cast heat",
  	   "!cast freese", 
  	   "!cast tangle",
  	   }) );
  SetFirstCommands( ({
  	   "cast vine wall",
  	   "cast vine wall",
  	   "cast vine wall",
  	   }) ); 
  SetTown("Sanctum");
  SetMorality(2000);
  SetLimit(1);
}

void heart_beat() {
  ::heart_beat();
  if (!present("natural_charge")) {
    eventForce("cast natural charge");
  }
}

