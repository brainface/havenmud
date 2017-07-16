#include <lib.h>
#include <damage_types.h>
#include "../ph.h"
inherit LIB_NPC;

int HealEm();

static void create() {
  ::create();
  SetKeyName("cleric");
  SetShort("a young cleric");
  SetId( ({ "cleric" }) );
  SetAdjectives( ({ "young","eclat","eclatish" }) );
  SetLong(
    "Tired and saddened eyes peer out from this young Eclat's face. "
    "No one ever informed the innocent cleric of the pain and "
    "suffering found in hospital work. However, a small spark of "
    "joy exists in those clear eyes."
  );
  SetRace(({ "muezzin","halfling","gelfling"})[random(3)]);
  SetClass("priest");
  SetLevel(10+random(5));
  SetGender(({ "male","female" })[random(2)]);
  
  SetMorality(1000);
  SetMeleeAttackString("fists");
  SetMeleeDamageType(BLUNT);
  SetSpellBook( ([
    "mend" : 100,
    "fortify" : 100,
  	]) );
  SetReligion("Eclat","Eclat");
  SetAction(1, (: HealEm() :) );
  SetCurrency("cuicui",10);
  SetCurrency("oros",20);
  SetCombatAction(15, ({ 
    "!shout HELP!  HELP!",
  }) );
}

int HealEm() {
  object array blargs;
  object blarg;
  blargs = all_inventory(environment(this_object()));
  blargs = filter(blargs, (: living :));
  blarg = blargs[random(sizeof(blargs))];
  eventForce("cast mend on " + blarg->GetKeyName());
  return 1;
}

