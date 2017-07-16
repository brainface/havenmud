/* Mahkefel 2017
 * divine guidance
 * planar coord for aeterin clerics (so they can better whomp with their staves)
 *
 */

#include <lib.h>
#include <magic.h>

int eventEndPlanar(object);
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("divine guidance");
  SetSpellType(SPELL_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
    "faith" : 30,
    "enchantment" : 30,
    ])  );
  SetRequiredMagic(100);
  SetMagicCost(50, 50);
  SetRequiredStamina(15);
  SetStaminaCost(10, 5);
  SetDifficulty(25);
  SetReligions("Aetarin");
  SetHelp(
    "You pray to Aerelus to see the honorable deeds, or at least potential, "
    "of the target, and assist their actions, coordinating their attacks and "
    "guiding their hands.");
}

int CanCast(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("planar_coordination")) {
    message("system", "That person's coordination is already unnatural.", who);
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets)  {
  int amt, dur;
  object target = targets[0];
  amt = (level + who->GetSkillLevel("enchantment") +
    who->GetSkillLevel("faith"))/10;
  dur = (level * (15 + 10 + who->GetSkillLevel("enchantment")/20));
  target->SetProperty("planar_coordination", 1);
  call_out( (: eventEndPlanar, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("coordination", -amt, dur);
    target->SetProperty("planar_coordination_failed", 1);
    send_messages( ({ "stagger" }), "$target_name $target_verb clumsily as "
      "target_possessive_noun doubt and fear overcome $target_objective.",
      who, 0, environment(who));
    return 1;
  }

  /* SUCCESS SUCCESS SUCCESS */
  send_messages( ({ "begin" }), "$agent_name $agent_verb moving with "
        "outright divine precision.", who, target, environment(target) );

  target->AddStatBonus("coordination", amt, dur);
  return 1;
}

int eventEndPlanar(object who) {
        if (!who) {
                return 1;
        }
        if(who->GetProperty("planar_coordination_failed")) {
        		who->RemoveProperty("planar_coordination_failed");
        		who->eventPrint("%^BOLD%^GREEN%^You feel less clumsy.%^RESET%^");
        }
        else {
        		 who->eventPrint("%^BOLD%^GREEN%^Aerelus no longer guides your movement.%^RESET%^");
        }
        who->RemoveProperty("planar_coordination");
        who->RemoveStatBonus("coordination");
        return 1;
}


