// chains of bonding
// created by Thoin


#include <lib.h>
#include <magic.h>

int eventEndEnnervate(object);
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("chains of bonding");
  SetSpellType(SPELL_COMBAT);
  SetRules("", "LIV");
  SetSkills(  ([
               "faith" : 50,
               "necromancy" : 50,
               ])  );
  SetDifficulty(125);
  SetReligions("Aberach");
  SetHelp(
          "This spell allows the caster to draw on necromantic energies "
          "and use them to constrict a living thing.  Because these energies "
          "are difficult to control, there is a chance of unexpected results.");
}

int CanCast(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("chains_bond")) {
    message("system", "That person has already been constricted "
            "by necromantic energies.", who);
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets)  {
  int amt, dur;
  object target = targets[0];
  amt = (level + who->GetSkillLevel("necromancy") +
    who->GetSkillLevel("faith"))/20;
  dur = level * 7 + 5;
  target->SetProperty("chains_bond", 1);
  call_out( (: eventEndEnnervate, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("agility", amt, dur);
    target->AddStatBonus("coordination", amt, dur);
    if (target == who) {
      send_messages( ({ "lose", "amplify" }), "$agent_name $agent_verb control "
        "of the necromantic energies and $agent_verb $agent_possessive reflexes.", who, 0,
        environment(who));
    }
    else {
      send_messages( ({ "lose", "amplify" }), "$agent_name $agent_verb control "
        "of the necromantic energies and $agent_verb $target_name reflexes.", who, target,
        environment(target));
    }
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

  if (target == who) {
    send_messages( ({ "take", "use" }), "$agent_name $agent_verb control of "
                  "the necromantic energies and $agent_verb them to constrict "
                  "$agent_reflexive.", who, 0, environment(who));
  }
  else {
    send_messages( ({ "take", "use" }), "$agent_name $agent_verb control of "
                  "the necromantic energies and $agent_verb them to constrict "
                  "$target_name.", who, target, environment(target));
  }
  target->AddStatBonus("agility", -amt, dur);
  target->AddStatBonus("coordination", -amt, dur);
  return 1;
}

int eventEndEnnervate(object who) {
        if (!who) {
                return 1;
        }
        who->RemoveProperty("chains_bond");
        who->RemoveStatBonus("agility");
        who->RemoveStatBonus("coordination");
        who->eventPrint("%^BOLD%^GREEN%^You no longer feel constricted by necromantic energies.%^RESET%^");
        return 1;
}

