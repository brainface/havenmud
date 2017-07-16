//
//  Poison spell for Thorians
//  Thoin@haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("major venomous touch");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "necromancy" : 200,
    "faith"      : 200,
  ]) );
  SetDifficulty(125);
  SetMorality(-10);
  SetAutoDamage(0);
  SetReligions("Thorian");
  SetDamageType(COLD|MAGIC);
  SetEnhanceSkills( ({ "poison magic" }) );
  SetMessages( ({
    ({ "evade", "$target_name $target_verb $agent_possessive_noun "
                   "touch with ease." }),
    ({ "touch", "$agent_name $agent_verb $target_name barely making any "
                 "contact."}),
    ({ "grasp", "As $agent_possessive_noun hand $agent_verb on to $target_name, "
                 "tendrils of %^BOLD%^%^BLACK%^black smoke%^RESET%^ choke "
                 "$target_objective causing $target_objective to cough and "
                 "shake uncontrollably." }),
    }) );
  SetHelp(
          "This spell allows a faithful thorian cleric to poison a target "
          "as well as do a damage."
          );
}

varargs int eventCast(object who, int level, mixed limb, object array targets) {
  int chance;
  chance = level + (int)who->GetSkillLevel("necromancy");
  chance -= targets[0]->GetLevel()*1.5;

  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("You fail to poison your target.");
         ::eventCast(who, level, limb, targets);
  } else {
    targets->AddPoison(level/5);
  ::eventCast(who, level, limb, targets);
  }
}
