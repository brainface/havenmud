// mahkefel 2017
// word of binding
// high level area paralyze

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <conditions.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("word of binding");
   SetSpellType(SPELL_COMBAT);
   SetAreaSpell(1);
   SetRules("");
   SetSkills( ([
     "conjuring"  : 300,
     "enchantment" : 300,
   ]) );
   SetMorality(0);
   SetDifficulty(40);
   SetEnhanceSkills( ({"ice magic"}) );
   // cooldown doesn't seem to work
   SetCooldown(30);
   SetHelp(
    "You speak a single word of power, binding all who hear. Speaking "
    "syllables of power is quick but exhausting, and only the most skilled "
    "can speak them without consequence."
    "\n"
    "This spell scales with level."
   );
}

int eventCast(object who, int level, string limb, object array targets) {
  int duration;
  
  // handle cooldown
  who->AddCooldown(GetSpell(), GetCooldown());
  
  // 20 seconds at skill level 500
  duration = who->GetSkillLevel("enchantment")/25;
  if (duration > 20) duration = 20;
  // up to 20 more seconds with 1000 ice magic
  duration += who->GetSkillLevel("ice magic")/50;
  duration *= level/100;
  
  send_messages(({ "speak" }), "$agent_name $agent_verb the ancient word of "
    "%^BOLD%^BLUE%^binding%^RESET%^!",who,targets, environment(who));

  foreach(object target in targets) {
  if (CanAttack(who, ({target}), who->GetSkillLevel("enchantment")/2 + level /5) == -1) {
    send_messages("resist", "$target_name%^YELLOW%^ $target_verb%^RESET%^ "
    "$agent_possessive_noun power!", who, target, environment(who)); 
  } else {
    send_messages("resist", "Conjured chains of%^BOLD%^BLUE%^ arcane "
    "might%^RESET%^ enwrap and "
    "enfetter $target_name!", who, target, environment(who));
    // make the duration somewhat random
    target->AddParalyzed(duration/2 + random(duration/2));
  }
  }
  
  // silence the player after casting the spell at lower levels
  if (level < 90) {
    who->AddCondition("Lost voice", CONDITION_PREVENT_TALK,(100-level)/10);
  }
  
  return 1;
}

