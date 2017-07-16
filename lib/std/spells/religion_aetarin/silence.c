/* Mahkefel 2017
 * caster shutdown spell for aetarin clerics
 * also stops gnomes from talking! bonus.
 */
#include <lib.h>
#include <magic.h>
#include <conditions.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("silence");
  SetSpellType(SPELL_COMBAT);
  SetRules("", "LIV");
  SetDifficulty(20);
  SetSkills( ([
    "faith" : 50,
    "enchantment" : 50 
    ]) );
  SetHelp("Aerelus teaches that every word that a conjurer speaks is a lie, "
    "potentially quite literally dripping with poison. The honorable of "
    "Aerelus can guarantee they hear none of these falsehoods by simply "
    "robbing anyone they wish of the power of voice.");
}

int CanCast(object who, int level, mixed limb, object *targets) {
  if (targets[0]->GetCondition("Silence immunity")) {
    who->eventPrint(capitalize(targets[0]->GetShort()) + 
      " voice has bottled up and can't be contained! (Wait " + targets[0]->GetConditionTime("Silence immunity") + "more seconds)");
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}


int eventCast(object who, int level, mixed limb, object *targets) {
  object target = targets[0];
  int duration = 10;

  // mahk: should scale indefinitely
  if( CanAttack(who, targets, who->GetSkillLevel("faith")/2 + level/5) == - 1 ) {
    who->eventPrint("Your powers fail you.");
    return 0;
  }

  duration += who->GetSkillLevel("enchantment") / 10 * level/100;
  
  send_messages( ({ "shush" }),
    "$agent_name forcibly and righteously%^BOLD%^CYAN%^ $agent_verb%^RESET%^ $target_name.",
    who, target, environment(who) );

  target->AddCondition("Silenced!",CONDITION_PREVENT_TALK, duration);
  target->AddCondition("Silence Immunity",CONDITION_SPECIAL,duration+10);
  return 1;
}

