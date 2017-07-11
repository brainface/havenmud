// ennervate
// created by Thoin
// 12-17-05


#include <lib.h>
#include <magic.h>

int eventEndEnnervate(object);
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("ennervate");
  SetSpellType(SPELL_COMBAT);
  SetRules("", "LIV");
  SetSkills( ([
    "faith" : 30,
    "necromancy" : 30,
  ]) );
  SetReligions("Saahagoth");
  SetDifficulty(25);
  SetHelp(
    "This spell allows the caster to draw on necromantic energies "
    "and use them to weaken a living thing.  Because these energies "
    "are difficult to control, there is a chance of unexpected results."
  );
}

int CanCast(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("ennervate_strength")) {
    message("system", "That person's strength has already been affected "
      "by the necromantic energies.", who);
  return 0;
  }
return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets)  {
  int amt, dur, amt2;
  object target = targets[0];
  amt2 = who->GetSkillLevel("necromancy") * level/100;
  if (amt2 < 1) amt2 = 1;
  if (amt2 > 20) amt2 = 20;
  	
  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
        }
        
  amt = (level + who->GetSkillLevel("necromancy") +
    who->GetSkillLevel("natural magic"))/20;
  dur = level * 7 + 5;
  target->SetProperty("ennervate_strength", 1);
  call_out( (: eventEndEnnervate, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("strength", amt, dur);
    if (target == who) {
      send_messages( ({ "lose", "strengthen" }), "$agent_name $agent_verb control "
        "of the necromantic energies and $agent_verb $agent_reflexive.", who, 0,
        environment(who));
    }
    else {
      send_messages( ({ "lose", "strengthen" }), "$agent_name $agent_verb control "
        "of the necromantic energies and $agent_verb $target_name.", who, target,
        environment(target));
    }
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

  if (target == who) {
    send_messages( ({ "take", "use" }), "$agent_name $agent_verb control of "
      "the necromantic energies and $agent_verb them to weakenen "
      "$agent_reflexive.", who, 0, environment(who));
  }
  else {
    send_messages( ({ "take", "use" }), "$agent_name $agent_verb control of "
      "the necromantic energies and $agent_verb them to weaken "
      "$target_name.", who, target, environment(target));
  }
  target->AddCurseed(amt2);
  target->AddStatBonus("strength", -amt, dur);
  return 1;
}

int eventEndEnnervate(object who) {
  if (!who) {
    return 1;
  }
  who->RemoveProperty("ennervate_strength");
  who->RemoveStatBonus("strength");
  who->eventPrint("%^BOLD%^GREEN%^The necromantic energies fade from your "
    "muscles.%^RESET%^");
  return 1;
}
