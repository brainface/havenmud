#include <lib.h>
#include <magic.h>

int eventEndWisdom(object);
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("ancestral wisdom");
  SetSpellType(SPELL_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
               "natural magic" : 50,
               "faith" : 50,
               ])  );
  SetRequiredMagic(100);
  SetMagicCost(75, 75);
  SetRequiredStamina(25);
  SetStaminaCost(15, 10);
  SetDifficulty(35);
  SetHelp(
          "This spell allows the caster to gather spirits around themself "
          "and use them to give wisdom to a living thing. Because the spirits "
          "can be fickle sometimes their will be unexpected results."
  );
}

int CanCast(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("spiritual_wisdom")) {
    message("system", "That person's wisdom has already been influenced "
            "by the ancients.", who);
    return 0;
  }
  if(target->GetReligion() != "Kuthar" ) {
    message("system", "This spell can only be cast on those of the Kuthar "
            "faith.", who);
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets)  {
  int amt, dur;
  object target = targets[0];
  amt = (level + who->GetSkillLevel("faith") +
    who->GetSkillLevel("natural magic"))/20;
  dur = level * 7 + 10;
  target->SetProperty("spiritual_wisdom", 1);
  call_out( (: eventEndWisdom, target :), dur);

/* FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("wisdom", -amt, dur);
    if (target == who) {
      send_messages( ({ "attempt", "curse" }), "$agent_name $agent_verb to summon "
        "spirits but instead $agent_nominative $agent_verb $agent_reflexive.", who, 0,
        environment(who));
    }
    else {
      send_messages( ({ "attempt", "curse" }), "$agent_name $agent_verb to summon "
        "spirits but instead $agent_nominative $agent_verb $target_name.", who, target,
        environment(target));
    }
  return 1;
  }

/* SUCCESS */

    if (target == who) {
      send_messages( ({ "ask" }), "$agent_name $agent_verb the spirits "
        "to bless $agent_possessive wisdom.", who, 0,
        environment(who));
    }
  else {
    send_messages( ({ "ask" }), "$agent_name $agent_verb the spirits "
        "to bless $target_name wisdom.", who, target, environment(target));
  }
  target->AddStatBonus("wisdom", amt, dur);
  return 1;
}

int eventEndWisdom(object who) {
        if (!who) {
                return 1;
        }
        who->RemoveProperty("spiritual_wisdom");
        who->RemoveStatBonus("wisdom");
        who->eventPrint("%^BOLD%^GREEN%^The spirits leave you.%^RESET%^");
        return 1;
}
