// mahkefel 2017
// word of binding
// high level area paralyze

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <conditions.h>
#include <rooms.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("word of compulsion");
   SetSpellType(SPELL_COMBAT);
   SetAreaSpell(1);
   SetRules("");
   SetSkills( ([
     "conjuring"  : 225,
     "enchantment" : 225,
   ]) );
   SetMorality(0);
   SetDifficulty(40);
   // cooldown doesn't seem to work
   SetCooldown(30);
   SetUniqueSpell(1);
   SetEnhanceSkills( ({ "shock magic" }) );
   SetHelp(
    "You speak a single word of power, charming all who hear. Speaking "
    "syllables of power is quick but exhausting, and only the most skilled "
    "can speak them without consequence. Lightning mages are particularly "
    "skilled at pronouncing this word."
    "\n"
    "This spell scales with level."
   );
}

int eventCast(object who, int level, string limb, object array targets) {
  int duration;
  
  // handle cooldown
  who->AddCooldown(GetSpell(), GetCooldown());
  
  
  send_messages(({ "speak" }), "$agent_name $agent_verb the ancient word of "
    "%^BOLD%^MAGENTA%^compulsion%^RESET%^!",who,targets, environment(who));

  foreach(object target in targets) {
  if (CanAttack(who, ({target}), who->GetSkillLevel("enchantment")/3 + 
    who->GetSkillLevel("shock magic")/6 + level /5) == -1) {
    send_messages("resist", "$target_name%^YELLOW%^ $target_verb%^RESET%^ "
    "$agent_possessive_noun power!", who, target, environment(who)); 
  } else {
    send_messages("resist", "Sparks %^BOLD%^YELLOW%^crackle and pop%^RESET%^ "
    "around $target_possessive_noun head, and $target_possessive gaze "
    "grows dim.", who, target, environment(who));
    // make the duration somewhat random
    target->eventCollapse();
      target->eventForce("halt " + who->GetKeyName());
      target->eventMove(ROOM_VOID);
      target->RemoveEnemy(who);
      target->SetWander(0);
      who->RemoveEnemy(target);
      target->ResetCurrentEnemy();
      who->ResetCurrentEnemy();
      target->eventMove(environment(who));
      target->AddFriend(who->GetKeyName());
      target->SetOwner(who->GetKeyName());
      who->AddFollower(target);
      who->eventForce("lead " + target->GetKeyName());
      target->eventForce("drool");
      if (member_array(target, who->GetFollowers()) == -1) {
        who->eventPrint(capitalize(target->GetShort()) + " is not following you.");
      }
      target->SetParalyzed(0);
  }
  }
  
  // silence the player after casting the spell at lower levels
  if (level < 90) {
    who->AddCondition("Lost voice", CONDITION_PREVENT_TALK,(100-level)/10);
  }
  
  return 1;
}

