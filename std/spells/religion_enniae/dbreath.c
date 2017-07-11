//
//  Poison spell for gnolls
//  Thoin@haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("dark breath");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "evokation" : 25,
    "faith"      : 25,
  ]) );
  SetDifficulty(20);
  SetMorality(-10);
  SetAutoDamage(0);
  SetDamageType(POISON);
  SetEnhanceSkills( ({ "poison magic" }) );
  SetReligions("Enniae");
  SetHelp(
          "This spell allows a faithful Enniae cleric to poison a target "
          "as well as do a small amount of magical damage."
          );
}

int eventCast(object who, int level, mixed limb, object array targets) {
  int chance;
  
  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
        } 
        
  chance = level + random((int)who->GetSkillLevel("evokation"));
  chance -= targets[0]->GetLevel() * 3;

  if (chance < 0) {
  send_messages( ({ "attempt", "dodge" }), "$agent_name $agent_verb "
                    "grasp $target_name but $target_nominative "
                    "$target_verb out of the way.",who,
                    targets,
                    environment(who));
  return 1;
  } else {

    send_messages(({"grasp"}), 
                  "As $agent_name $agent_verb onto $target_name, "
                  "a dark mist covers $target_objective causing "
                  "$target_objective to shudder and collapse to the ground."
                  ,who,targets,
                  environment(who));
    targets->AddPoison(who->GetSkillLevel("evokation")/10);
    targets->eventCollapse();
    return 1;
  }
}
