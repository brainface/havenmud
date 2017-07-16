/*
 * Blindness
 * Balishae@haven 1/11/98
 */
 
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create()
{
  spell::create();
  SetSpell("blindness");
  SetSpellType(SPELL_COMBAT);
  SetRules("","LIV");
  SetDifficulty(20);
  SetSkills( ([
    "conjuring" : 40,
    "enchantment" : 40,
    ]) );
  SetMorality(0);
  SetHelp(
          "This spell removes the sight from its "
          "target for a duration of time relative to the power of the "
          "caster relative to that of the target.");
}

int CanCast(object who, int level, string limb, object array targets) {
  foreach(object target in targets) {
    if (target->GetBlind()) {
      message("my_action","But "+target->GetName()+" is "
              "blinded aready!",who);
      return 0;
    } else {
      return spell::CanCast(who, level, limb, targets);
    }
  }
}

int eventCast(object who, int level, mixed limb, object array targets) {
  int chance, dur;
  chance = level + random((int)who->GetSkillLevel("enchantment"));
  chance -= targets[0]->GetLevel() * 5;
  dur = level/10;

  if (chance < 0) {
  send_messages( ({ "blink","shake" }), "$target_name "
                    "$target_verb tears out of "
                    "$target_possessive eyes, but "
                    "$target_nominative "
                    "$target_verb it off.",who,
                    targets,
                    environment(who));
  return 1;
  } else {
    send_messages(({"point","clench","cover"}), 
                  "$agent_name $agent_verb "
                  "$agent_possessive finger at $target_name, "
                  "and then slowly $agent_verb $agent_possessive "
                  "fist causing $target_name to $target_verb "
                  "$target_possessive eyes in pain.",
                  who,targets,
                  environment(who));
    targets->eventBlind(who, dur+random(dur));
    return 1;
  }
}
