#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include <std.h>
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("fisherman");
  SetShort("a gelfling fisherman");
  SetRace("gelfling");
  SetGender("male");
  SetId( ({ "gelfling", "fisherman" }) );
  SetAdjectives( ({ "gelfling" }) );
  SetLong(
    "This gelfling appears to be happily enjoying his life as a "
    "fisherman in Platypus Bay."
    );
  SetInventory( ([
    STD_FISH "pole" : "wield pole",
    ]) );
  SetClass("merchant");
  SetSkill("pole combat", 1, 1);
  SetLevel(15);
  SetMorality(200);
  SetCurrency("imperials", 50);
  SetAction(15, ({ 
    "!fish with my pole",
    "!fish with my pole",
    "!whistle",
    "!say A fine day for fishing, yes?",
    "!hum",
    "!emote sings a little sea ditty.",
  }) );
  SetTrainingSkills( ({
    "fishing",
    "cooking",
    }) );
  SetTown("all");
  SetFirstCommands( ({ "fish with my pole" }) );
}
    
int eventDie(object killer) {
  object bandit_inv;
  if(!random(1000)) {
    bandit_inv = new(DIR_INVASIONS + "/sanctum_bandit/bis_inv");
    INVASION_D->eventRegisterInvasion(bandit_inv, killer);
  }
return ::eventDie(killer);
}
