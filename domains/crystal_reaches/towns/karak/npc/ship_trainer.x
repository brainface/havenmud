// Karak Recode
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("worg");
  SetId( ({ "worg", "reaver", "orc"}) );
  SetAdjectives( ({ "orcish" }) );
  SetShort("Worg the Orcish Reaver");
  SetLong(
    "Worg is a Reaver, a member of the Orc Navy. "
    "He's always willing to teach someone and tell "
    "his tales of the sea."
  );
  SetRace("orc");
  SetGender("male");
  
  AddTrainingSkills("sailing");
  AddTrainingSkills("navigation");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("fishing");
  AddTrainingSkills("swimming");
  AddTrainingSkills("bargaining");
  SetLevel(20);
  SetReligion("Saahagoth");
  SetMorality(-150);
  AddAlcohol(75);
  SetInventory( ([
    STD_FISHING "pole" : "wield pole",
  ]) );
  SetAction(5, ({
  	"!speak Yo ho ho!",
  	"!yell Ahoy Mateys!",
  	"!fish with my pole",
  	"!speak Aye, I can teach you about sailing!",
  }) );
  SetTown("all");
}

  	
  	
