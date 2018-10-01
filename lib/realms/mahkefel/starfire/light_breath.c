// blue dragon breath
// mahkefel 2017
// for melbelle

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <conditions.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("blue dragon breath");
  SetRules("");

  SetEnhanceSkills( ({ "shock magic" }) );
  SetSkills( ([
    "conjuring" : 225,
    "evokation" : 225,
  ]) );
  SetDamageType(SHOCK|SOUND);
  SetStaminaCost(50, 25);
  SetAutoDamage(0);
  SetAreaSpell(1);
  SetSpellType(SPELL_COMBAT);
  SetDifficulty(100);
  SetUniqueSpell(1);
  SetMessages( ({
    ({"", "$agent_possessive_noun %^BOLD%^YELLOW%^lightning breath%^RESET%^ "
      "hops over $target_name." }),
    ({"", "$agent_possessive_noun %^BOLD%^YELLOW%^lightning breath%^RESET%^ "
      "bounces into $target_name, shocking "
      "$target_objective." }),
    ({"", "$agent_possessive_noun %^BOLD%^YELLOW%^lightning breath%^RESET%^ "
      "ricochets into $target_name, electrocuting "
      "$target_objective! " }),
    }) );
  SetHelp(
    "A reckless bit of magic, this spell emulates the breath of "
    "a dragon, unleashing pure lightning from ones lungs to the surrounding "
    "area. Rumors say only a dragon can teach a mortal to work such magic, "
    "and that doing so is far from free of consequence."
  );
}

// overide the whole eventCast function I guess.
int eventCast(object who, int level, string limb, object array targets) {
  int result;

  result = ::eventCast(who, level, limb, targets);
  
  if (result) {
    send_messages( ({"take","belch"}),
      "$agent_name%^BOLD%^WHITE%^$agent_verb%^RESET%^ a big gulp of air, then "
      "violently $agent_verb an uncontrolled %^BOLD%^YELLOW%^bolt of "
      "lightning!%^RESET%^",
      who, who, environment(who));
    who->AddCondition("Sorely Shocked Throat", CONDITION_PREVENT_TALK,10);
  }
  return result;
}

int eventAfterEffect(object who, int level, string limb, object target) {
  // test for you got shocked brah
  if (who->eventCheckSkill("evokation", target->GetStatLevel("durability"), 0, 0)) {
    // apply electrocution!
    target->eventKnockDown();
    target->AddCondition("Lightning Struck!", 
    CONDITION_PREVENT_HEAR|CONDITION_PREVENT_COMBAT,
    random(10+who->GetSkillLevel("shock magic")/50)+1);
  }

  return 1;
}

