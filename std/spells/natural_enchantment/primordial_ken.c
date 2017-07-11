// fuck you guys
// I'm making a stacking stat boost spell
// it's much lower than a planar, and stacks with everything but this spell
// from this caster.

#include <lib.h>
#include <magic.h>

int eventEndPlanar(object,string);
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("primordial ken");
  SetSpellType(SPELL_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
    "natural magic" : 50,
  ])  );
  SetRequiredMagic(100);
  SetMagicCost(50, 50);
  SetRequiredStamina(15);
  SetStaminaCost(10, 5);
  SetDifficulty(25);
  SetHelp(
    "An experienced druid can enhance a mortal's meagre wisdom by drawing "
    "upon the knowledge of ancient primordials. Drawing on such lost "
    "knowledge occasionally has dire consequences."
  );
}

int CanCast(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("stacking_boost_wis" + who->GetKeyName() + GetSpell() )) {
    message("system", "That person's vision has already been increased "
      "beyond their ken.", who);
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets)  {
  int amt, dur;
  object target = targets[0];

  amt = 3 + who->GetSkillLevel("natural magic") / 25;
  amt *= level / 100;
  if (amt < 2) amt = 2;
  dur = (level * (15 + 10 + who->GetSkillLevel("natural magic")/20));
  target->SetProperty(who->GetKeyName() + GetSpell(), 1 );
  
  call_out( (: eventEndPlanar, target, who->GetKeyName() :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("wisdom", -amt, dur);
      send_messages( ({ "giggle", }), "$agent_name $agent_verb idiotically "
        "as knowledge beyond $agent_possessive comprehension%^BOLD%^BLUE%^ "
        "floods%^RESET%^ $agent_possessive mind!",
         target, 0, environment(who));
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

    send_messages( ({ "grow" }), "$agent_possessive_noun eyes widen in "
      "comprehension as ancient knowledge%^BOLD%^%^GREEN%^ fills%^RESET%^ "
      "$agent_possessive mind.",
      target, 0, environment(target));
  target->AddStatBonus("wisdom", amt, dur);
  target->eventPrint("%^BOLD%^GREEN%^You feel more wise.%^RESET%^");
  return 1;
}

int eventEndPlanar(object target,string caster) {
  if (!target) {
    return 1;
  }
  target->RemoveProperty(caster + GetSpell());
  target->RemoveStatBonus("wisdom");
  target->eventPrint("%^BOLD%^YELLOW%^You feel foolish again.%^RESET%^");
  return 1;
}

