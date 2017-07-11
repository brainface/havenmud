#include <lib.h>
#include <magic.h>

int eventEndPlanar(object);
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("planar intelligence");
  SetSpellType(SPELL_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
               "conjuring" : 80,
               "enchantment" : 80,
               ])  );
  SetMagicCost(80, 80);
  SetStaminaCost(10, 10);
  SetDifficulty(45);
  SetHelp(
          "This spell allows the caster to draw energy from the planes "
          "and use them to enlighten a living thing.  Because planar energy "
          "is difficult to control, there is a chance of unexpected results.");
}

int CanCast(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("planar_intelligence")) {
    message("system", "That person's intelligence has already been affected by the planar energies.", who);
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets)  {
  int amt, dur;
  object target = targets[0];
  amt = (level + who->GetSkillLevel("enchantment") +  who->GetSkillLevel("conjuring"))/10;
   dur = (level * (15 + 10 + who->GetSkillLevel("enchantment")/20));
  target->SetProperty("planar_intelligence", 1);
  call_out( (: eventEndPlanar, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("intelligence", -amt, dur);
    if (target == who) {
      send_messages( ({ "lose", "stupify" }), "$agent_name $agent_verb control "
        "of the planar energies and $agent_verb $agent_reflexive.", who, 0,
        environment(who));
    }
    else {
      send_messages( ({ "lose", "stupify" }), "$agent_name $agent_verb control "
        "of the planar energies and $agent_verb $target_name.", who, target,
        environment(target));
    }
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

  if (target == who) {
    send_messages( ({ "take", "use" }), "$agent_name $agent_verb control of "
                  "the planar energies and $agent_verb them to enlighten "
                  "$agent_reflexive.", who, 0, environment(who));
  }
  else {
    send_messages( ({ "take", "use" }), "$agent_name $agent_verb control of "
                  "the planar energies and $agent_verb them to enlighten "
                  "$target_name.", who, target, environment(target));
  }
  target->AddStatBonus("intelligence", amt, dur);
  return 1;
}

int eventEndPlanar(object who) {
	if (!who) {
		return 1;
	}
	who->RemoveProperty("planar_intelligence");
        who->RemoveStatBonus("intelligence");
	who->eventPrint("%^BOLD%^GREEN%^You seem less enlightened.%^RESET%^");
	return 1;
}

/* Approved by Zaxan on Tue Feb 17 21:35:17 1998. */
