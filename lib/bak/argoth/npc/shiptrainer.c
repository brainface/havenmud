#include <lib.h>
#include <std.h>
#include "../argoth.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("worg");
  SetShort("Worg the Orcish Reaver");
  AddAlcohol(75);
  SetId( ({ "worg", "reaver" }) );
  SetAdjectives( ({ "orcish" }) );
  SetRace("orc");
  SetGender("male");
  SetTrainingSkills( ({
  	"sailing", "navigation", "slash combat",
  	"slash combat", "fishing", "swimming",
  }) );
  SetLevel(20);
  SetMorality(50);
  SetLong("Worg is a Reaver, a member of the Orc Navy. "
          "He's always willing to teach someone and tell "
          "his tales of the sea.");
  SetInventory( ([
    STD_FISHING "pole" : "wield pole",
    ]) );
  SetAction(5, ({
  	"!speak Yo ho ho!",
  	"!yell Ahoy Mateys!",
  	"!fish with my pole",
  	"!speak Aye, I can teach you about sailing!",
  }) );
/*
  SetLimit(1);
*/
  SetTown("all");
}

  	
  	
