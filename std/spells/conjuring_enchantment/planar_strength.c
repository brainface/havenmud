#include <lib.h>
#include <magic.h>

int eventEndPlanar(object);
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("planar strength");
  SetSpellType(SPELL_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
               "conjuring" : 30,
               "enchantment" : 30,
               ])  );
  SetRequiredMagic(100);
  SetMagicCost(50, 50);
  SetRequiredStamina(15);
  SetStaminaCost(10, 5);
  SetDifficulty(25);
  SetHelp(
          "This spell allows the caster to draw energy from the planes "
          "and use them to strengthen a living thing.  Because planar energy "
          "is difficult to control, there is a chance of unexpected results.");
}

int CanCast(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("planar_strength")) {
    message("system", "That person's strength has already been affected "
            "by the planar energies.", who);
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets)  {
  int amt, dur;
  object target = targets[0];
  amt = (level + who->GetSkillLevel("enchantment") +
    who->GetSkillLevel("conjuring"))/10;
  dur = (level * (15 + 10 + who->GetSkillLevel("enchantment")/20));
  target->SetProperty("planar_strength", 1);
  call_out( (: eventEndPlanar, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("strength", -amt, dur);
    target->SetProperty("planar_strength_failed", 1);
    if (target == who) {
      send_messages( ({ "lose", "weaken" }), "$agent_name $agent_verb control "
        "of the planar energies and $agent_verb $agent_reflexive.", who, 0,
        environment(who));
    }
    else {
      send_messages( ({ "lose", "weaken" }), "$agent_name $agent_verb control "
        "of the planar energies and $agent_verb $target_name.", who, target,
        environment(target));
    }
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

  if (target == who) {
    send_messages( ({ "take", "use" }), "$agent_name $agent_verb control of "
                  "the planar energies and $agent_verb them to strengthen "
                  "$agent_reflexive.", who, 0, environment(who));
  }
  else {
    send_messages( ({ "take", "use" }), "$agent_name $agent_verb control of "
                  "the planar energies and $agent_verb them to strengthen "
                  "$target_name.", who, target, environment(target));
  }
  target->AddStatBonus("strength", amt, dur);
  return 1;
}

int eventEndPlanar(object who) {
        if (!who) {
                return 1;
        }
        if(who->GetProperty("planar_strength_failed")) {
        		who->RemoveProperty("planar_strength_failed");
        		who->eventPrint("%^BOLD%^GREEN%^Your strength returns.%^RESET%^");
        }
        else {
        		 who->eventPrint("%^BOLD%^GREEN%^You weaken.%^RESET%^");
        }
        who->RemoveProperty("planar_strength");
        who->RemoveStatBonus("strength");
        return 1;
}

/* Approved by Zaxan on Tue Feb 17 21:35:17 1998. */
