//
//  Disease spell for Thorians
//  Thoin@haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <std.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("major infection");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "necromancy" : 150,
    "faith" : 150,
  ]) );
  SetMagicCost(75, 75);
  SetDifficulty(20);
  SetMorality(-10);
  SetAutoDamage(0);
  SetReligions("Thorian");
  SetHelp(
          "This spell allows a faithful thorian cleric to disease a target."
          );
}

int eventCast(object who, int level, mixed limb, object *targets) {
  int chance;
  object target = targets[0];

  chance = level + who->GetSkillLevel("necromancy") + random(100);
  chance -= target->GetLevel() * 3;

  if (chance < 0) {
  send_messages( ({ "attempt" }), "$agent_name $agent_verb "
                    "to infect $target_name but $target_nominative "
                    "resists.",who,target,environment(who));
  return 1;
  } else {
          send_messages( ({"wrap", "grasp"}), 
                  "Tendrils of black smoke $target_verb around $target_name "
                  "as $agent_name $agent_verb onto $target_possessive_noun "
                  "arm. As $target_name inhales the smoke $target_nominative "
                  "becomes stricken with disease.",who,target,environment(who) );
  switch(random(100)) {
   case 0..50 :  
     STD_GERMS "waste_sick"->eventInfect(target);
   break;
   case 51..100 :
     STD_GERMS "bird_flu"->eventInfect(target);
   break;
  }
    return 1;
  }
}
