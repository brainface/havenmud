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
  SetSpell("undying vitality");
  SetSpellType(SPELL_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
               "necromancy" : 50,
               ])  );
  SetRequiredMagic(100);
  SetMagicCost(50, 50);
  SetRequiredStamina(15);
  SetStaminaCost(10, 5);
  SetDifficulty(25);
  SetHelp(
    "With this spell, a necromancer channels the energy of undeath into "
    "their target, fortifying their durability beyond what mere mortality allows. "
    "Due to the horrible source of the vitality, some targets may suffer "
    "unfortunate side effects."
  );
}

int CanCast(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("stacking_boost_dur" + who->GetKeyName() + GetSpell() )) {
    message("system", "That person's vitality has already been affected "
            "by your necromantic energies.", who);
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets)  {
  int amt, dur;
  object target = targets[0];
  
  amt = 3 + who->GetSkillLevel("necromancy") / 25;
  amt *= level / 100;
  if (amt < 2) amt = 2;
  dur = (level * (15 + 10 + who->GetSkillLevel("necromancy")/20));
  target->SetProperty("stacking_boost_dur"+ who->GetKeyName() + GetSpell(), 1 );
  call_out( (: eventEndPlanar, target, who->GetKeyName() :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("durability", -amt, dur);
      send_messages( ({ "cackle", }), "$agent_name $agent_verb maniacaly "
        "as the spirits $agent_nominative seeks to channel momentarily seize "
        "control and%^BOLD%^BLACK%^ corrupt%^RESET%^ $agent_possessive spell!",
         who, 0, environment(who));
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

    send_messages( ({ "grow" }), "$agent_name $agent_verb perfectly still as "
      "the dusty scent of%^BOLD%^BLACK%^ gravedust%^RESET%^ fills your nose.",
      target, 0, environment(target));
  target->AddStatBonus("durability", amt, dur);
  target->eventPrint("%^BOLD%^RED%^You can't feel your heartbeat.%^RESET%^");
  return 1;
}

int eventEndPlanar(object target,string caster) {
if (!target) {
return 1;
}
target->RemoveProperty("stacking_boost_dur"+ caster + GetSpell());
    target->RemoveStatBonus("durability");
target->eventPrint("%^BOLD%^GREEN%^Your heart starts to beat again.%^RESET%^");
return 1;
}

