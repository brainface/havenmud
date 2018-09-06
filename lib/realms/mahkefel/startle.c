/* Mahkefel 2017
 * there were no level 1 faith enchantment spells, wanted to add one
 * knocks down the target
 * pretty big effect but it's going to scale into uselessness soo.
 *
 * also hey! it's an iconic cleric spell from that game.
 */
#include <lib.h>
#include <magic.h>
#include <conditions.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("startle");
  SetSpellType(SPELL_COMBAT);
  SetRules("", "LIV");
  SetDifficulty(20);
  SetDamageType(MAGIC);
  SetAutoDamage(0);
  SetSkills( ([
    "illusion" : 10,
    ]) );
  SetEnhanceSkills( ({ "shock magic" }) );
  SetMessages( ([
    ({ "summon", "$agent_name $agent_verb a series of %^BOLD%^YELLOW%^calming%^RESET%^ %^BOLD%^CYAN%^pastels%^RESET%^ before an unfazed $target_name."}),
  ({ "gesture", "$agent_name $agent_verb with $agent_possessive_noun hand and a disturbing "
      "%^CYAN%^phantasm%^RESET%^ rushes at $target_name, startling "
     "$target_objective!"}),
  ]) )
  SetHelp("A novice illusionist's prank, you conjure a brief, fearful image to "
    "rush at your enemy or erstwhile friend. Most recover quickly, but it "
    "can provide an opening for those with malice on their mind.");
}

int CanCast(object who, int level, mixed limb, object *targets) {
  if (targets[0]->GetCurrentEnemy() == who) {
    who->eventPrint(capitalize(targets[0]->GetShort()) + " is looking right at you, angry at you, and unlikely to be startled!");
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}



int eventAfterEffect(object who, int level, string limb, object target) {
  int duration = 2;
  int duration_bonus = 0;
  duration += who->GetSkillLevel("illusion")/5;
  duration_bonus += who->GetSkillLevel("shock magic")/5;
  if (duration > 10) duration = 10;
  if (duration_bonus > 10) duration_bonus = 10;
  duration = duration + duration_bonus;

  target->AddCondition("Startled!",CONDITION_PREVENT_TALK|CONDITION_PREVENT_COMBAT|CONDITION_PREVENT_WIELD|CONDITION_FEAR, duration);
  return 1;
}


