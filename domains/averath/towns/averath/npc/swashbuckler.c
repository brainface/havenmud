//swashbuckler as musketeer type

// mostly Alessandra nov 2012


#include <lib.h>
#include "../averath.h"

inherit LIB_TRAINER;

#include "../wanted.h"
int CheckPoster();

static void create() {
  trainer::create();
  SetKeyName("Aramis");
  SetShort("Aramis d'Alexandre the Duelist");
  SetId( ({"aramis","d'Alexandre","duelist"}) );
  SetAdjectives( ({"aramis","the","duelist"}) );
  SetLong("Aramis is the epitome of the nobler of swashbuckling types. "
    "Brown wavy hair is perfectly coiffed to his shoulders and his chin "
    "beard is impeccably trimmed. Beneath the carefully curled ends of "
    "his mustache he smirks. Yes, Aramis is just the sort of fellow "
    "who gets all the fair maidens and puts those chaps who fancy "
    "themselves decent with a blade to shame. Perhaps he could teach "
    "you his ways."
  );
  SetTown("all");
  SetRace("human");
  SetGender("male");
  SetClass("fighter");
  SetSkill("swashbuckling",1,1);
  SetSkill("pierce combat",1,1);
  SetLevel(150);
  SetBaseLanguage("Avera");
  SetCurrency( ([
       "ducats" : random(1500) + 1000,
        ]) );
  SetMorality(100);
  SetAction(7, ({
    "!say Well, fancy a go at it?",
    "!say You rather shouldn't insult my honor.",
    "!say I think you'd have a fair chance, let's "
      " find something trivial to start a fight over.",
    "!say I hope Porthos is doing well.",
  }) );

  SetCombatAction(50, ({
    "riposte",
    "lunge",
    "harry",
    "parley", // lol?
    "skewer",
    "disarm",
  }) );
  SetInventory( ([
    AVERATH_OBJ "swash_boots" : "wear boots",
    AVERATH_OBJ "swash_leggings" : "wear leggings",
    AVERATH_OBJ "swash_tabard" : "wear tabard",
    AVERATH_OBJ "feathered_hat" : "wear hat",
    AVERATH_OBJ "swash_boots" : "wear boots",
   AVERATH_OBJ "swashy_rapier" : "wield rapier",
  ]) );
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("swashbuckling");
  SetWander(5);
  SetLimit(1);
  SetEncounter( (: CheckPoster :) );
}

int CheckPoster() {
  if (this_player()->GetInvis())
  {
    return 0;
  }

  if (member_array(this_player()->GetKeyName(), keys(Crimes)) != -1)
  {
    eventForce("follow " + this_player()->GetKeyName());
    eventForce("say There is no honor in running. Stand and face your "
      "destiny.");
    SetAttack(this_player());
    return 1;
   }
  return 0;
 }

