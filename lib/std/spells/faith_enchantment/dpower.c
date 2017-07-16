// Divine Power
// increases str and dur
// Thoin@Haven

#include <lib.h>
#include <magic.h>

int eventEndForce(object);
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("divine power");
  SetSpellType(SPELL_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
     "faith" : 175,
     "enchantment" : 175,
  ]) );
  SetMagicCost(120, 120);
  SetDifficulty(130);
  SetHelp(
          "A powerful cleric may call upon the gods to bestow themself or others "
          "with divine powers. This spell greatly increases the strength and "
          "durability of the target."
     );
}
int CanCast(object who, int level, mixed limb, object array targets)
{
  object target = targets[0];
  if(target->GetProperty("divine_power") && (who == targets[0]))
  {
    message("system", "You have already been touched by the Gods."
            , who);
    return 0;
  }
  else if( target->GetProperty("divine_power"))
  {
    message("system", "That person has already been touch by the Gods."
            , who);
    return 0;
  }
  if(target->GetProperty("planar_strength")) {
    message("system", "That person's strength has already been affected "
            "by a strength spell.", who);
    return 0;
  }
  if(target->GetProperty("planar_durability")) {
    message("system", "That person's strength has already been affected "
            "by a durability spell.", who);
    return 0;
  }
  if(target->GetProperty("nature_force")){
    message("system", "That person's strength has already been affected "
            "by a durability spell.", who);
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets)  {
  int amt, dur;
  object target = targets[0];
  amt = (level + who->GetSkillLevel("enchantment") + who->GetSkillLevel("faith"))/15;
  if (amt > 50) amt = 50;
   dur = (level * (15 + 10 + who->GetSkillLevel("enchantment")/20));
  target->SetProperty("divine_power", 1);
  target->SetProperty("planar_durability", 1);
    target->SetProperty("planar_strength", 1);
  call_out( (: eventEndForce, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("durability", -amt, dur);
    target->AddStatBonus("strength", -amt, dur);
    if (target == who) {
      send_messages( ({ "falter", "" }), "$agent_possessive_noun faith falters and "
        "$agent_possessive God curses $agent_objective causing $agent_objective to become weak and "
        "sluggish.", who, 0,
        environment(who));
    }
    else {
      send_messages( ({ "falter", "" }), "$agent_possessive_noun faith falters and "
        "$agent_possessive God curses $target_name causing $target_objective to become weakened "
        "sluggish", who, target,
        environment(target));
    }
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

  if (target == who) {
    send_messages( ({ "call" }), "$agent_name $agent_verb out to the heavens "
                  "and the Gods hear $agent_possessive_noun cry, blessing "
                   "$agent_objective with divine powers. ", who, 0, environment(who));
  }
  else {
    send_messages( ({ "call" }), "$agent_name $agent_verb out to the heavens "
                  "and the Gods hear $agent_possessive_noun cry, blessing "
                   "$target_name with divine powers. ", 
                   who, target, environment(target));
  }
    target->AddBlessed(amt);
  target->AddStatBonus("durability", amt, dur);
  target->AddStatBonus("strength", amt, dur);
  return 1;
}

int eventEndForce(object who) {
        if (!who) {
                return 1;
        }
        who->RemoveProperty("divine_power");
        who->RemoveProperty("planar_strength");
        who->RemoveProperty("planar_durability");
        who->RemoveStatBonus("strength");
        who->RemoveStatBonus("durability");
        who->eventPrint("%^BOLD%^YELLOW%^The Gods blessing leaves you.%^RESET%^");
        return 1;
}

