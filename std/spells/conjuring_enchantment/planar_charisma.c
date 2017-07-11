#include <lib.h>
#include <magic.h>

int eventEndPlanar(object);
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("planar charisma");
  SetSpellType(SPELL_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
               "conjuring" : 60,
               "enchantment" : 60,
               ])  );
  SetMagicCost(50, 50);
  SetStaminaCost(10, 5);
  SetDifficulty(25);
  SetHelp(
          "This spell allows the caster to draw energy from the planes "
          "and use them to beautify a living thing.  Because planar energy "
          "is difficult to control, there is a chance of unexpected results.");
}

int CanCast(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("planar_charisma")) {
    message("system", "That person's charisma has already been affected "
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
  target->SetProperty("planar_charisma", 1);
  call_out( (: eventEndPlanar, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("charisma", -amt, dur);
    target->SetProperty("planar_charisma_failed", 1);
    if (target == who) {
      send_messages( ({ "lose", "ugly" }), "$agent_name $agent_verb control "
        "of the planar energies and $agent_verb $agent_reflexive.", who, 0,
        environment(who));
    }
    else {
      send_messages( ({ "lose", "ugly" }), "$agent_name $agent_verb control "
        "of the planar energies and $agent_verb $target_name.", who, target,
        environment(target));
    }
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

  if (target == who) {
    send_messages( ({ "take", "use" }), "$agent_name $agent_verb control of "
                  "the planar energies and $agent_verb them to beautify "
                  "$agent_reflexive.", who, 0, environment(who));
  }
  else {
    send_messages( ({ "take", "use" }), "$agent_name $agent_verb control of "
                  "the planar energies and $agent_verb them to beautify "
                  "$target_name.", who, target, environment(target));
  }
  target->AddStatBonus("charisma", amt, dur);
  return 1;
}

int eventEndPlanar(object who) {
        if (!who) {
                return 1;
        }
        if(who->GetProperty("planar_charisma_failed")) {
        		who->eventPrint("%^BOLD%^GREEN%^You are more charismatic.%^RESET%^");
        		who->RemoveProperty("planar_charisma_failed");
        }
        else {
        		who->eventPrint("%^BOLD%^GREEN%^You are somewhat less charismatic.%^RESET%^");
        }
        who->RemoveProperty("planar_charisma");
        who->RemoveStatBonus("charisma");
        
        return 1;
}

/* Approved by Zaxan on Tue Feb 17 21:35:17 1998. */
