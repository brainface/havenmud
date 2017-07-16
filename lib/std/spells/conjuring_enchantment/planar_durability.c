// Derived from planar strength
// Artanis@Haven (July 1 2004)

#include <lib.h>
#include <magic.h>

int eventEndPlanarDura(object);
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("planar durability");
  SetSpellType(SPELL_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
     "conjuring" : 35,
     "enchantment" : 35,
  ]) );
  SetMagicCost(60, 60);
  SetStaminaCost(15, 10);
  SetDifficulty(40);
  SetHelp(
          "This spell allows the caster to draw energy from the planes "
          "and use them to enhanced the durability of a living thing. "
          "Because planar energy is difficult to control, there is a chance "
          "of unexpected results. "
     );
}
int CanCast(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("planar_durability")) {
    message("system", "That person's durability has already been affected "
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
  target->SetProperty("planar_durability", 1);
  call_out( (: eventEndPlanarDura, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("durability", -amt, dur);
    target->SetProperty("planar_durability_failed", 1);
    if (target == who) {
      send_messages( ({ "lose", "cause" }), "$agent_name $agent_verb control "
        "of the planar energies and $agent_verb $agent_reflexive to become "
        "feeble and weak!", who, 0,
        environment(who));
    }
    else {
      send_messages( ({ "lose", "cause" }), "$agent_name $agent_verb control "
        "of the planar energies and $target_verb $target_reflexive to become "
        "feeble and weak!", who, 0,
        environment(target));
    }
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

  if (target == who) {
    send_messages( ({ "take", "use" }), "$agent_name $agent_verb "
                  "control of the planar energies and $agent_verb them "
                  "enhance $agent_possessive durability.",
                    who, 0, environment(who));
  }
  else {
    send_messages( ({ "take", "use" }), "$agent_name $agent_verb "
                  "control of the planar energies and $agent_verb them to "
                  "enhance $target_possessive_noun durability.",
                   who, target, environment(target));
  }
  target->AddStatBonus("durability", amt, dur);
  return 1;
}

int eventEndPlanarDura(object who) {
        if (!who) {
                return 1;
        }
        if(who->GetProperty("planar_durability_failed")) {
        		who->eventPrint("%^BOLD%^GREEN%^You feel your health returns to normal.%^RESET%^");
        		who->RemoveProperty("planar_durability_failed");
        }
        else {
        		who->eventPrint("%^BOLD%^GREEN%^You feel less healthy again.%^RESET%^");
        }
        who->RemoveProperty("planar_durability");
        who->RemoveStatBonus("durability");
        return 1;
}



/* Approved by Zaxan on Tue Feb 17 21:35:17 1998. */
