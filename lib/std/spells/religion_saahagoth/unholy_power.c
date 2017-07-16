// Unholy Power
// increases str and dur
// Thoin@Haven

#include <lib.h>
#include <magic.h>

int eventEndForce(object);
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("unholy power");
  SetSpellType(SPELL_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
     "faith" : 75,
     "necromancy" : 75,
  ]) );
  SetMagicCost(120, 120);
  SetDifficulty(130);
  SetReligions("Saahagoth");
  SetHelp(
          "A powerful Saahagoth faithful may call upon the Lord of Chaos to bestow themself or others "
          "with unholy powers. This spell greatly increases the strength and "
          "durability of the target. This spell cannot be cast on heretics."
     );
}
int CanCast(object who, int level, mixed limb, object array targets)
{
  object target = targets[0];
  if(target->GetProperty("unholy_power") && (who == targets[0]))
  {
    message("system", "You have already been touched by the Gods."
            , who);
    return 0;
  }
  else if( target->GetProperty("unholy_power"))
  {
    message("system", "That person has already been touch by the Lord of Chaos."
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
  if(target->GetReligion() != "Saahagoth" ) {
    message("system", "This spell can only be cast on those of the Saahagoth "
            "faith.", who);
    return 0;
  }
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets)  {
  int amt, dur, amt2;
  object target = targets[0];
  amt = (level + who->GetSkillLevel("necromancy") +
    who->GetSkillLevel("faith"))/15;
   dur = (level * (15 + 10 + who->GetSkillLevel("necromancy")/20));
  target->SetProperty("unholy_power", 1);
  target->SetProperty("planar_durability", 1);
    target->SetProperty("planar_strength", 1);
  amt2 = target->GetCaffeine();
  amt2 = (amt*15) - amt2;
if (target->GetCaffeine() > target->GetStatLevel("durability") * 10) { amt2 = target->GetStatLevel("durability") * 10;}
  call_out( (: eventEndForce, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("durability", -amt, dur);
    target->AddStatBonus("strength", -amt, dur);
    if (target == who) {
      send_messages( ({ "falter", "" }), "$agent_possessive_noun faith falters and "
        "the Lord of Chaos curses $agent_objective causing $agent_objective to become weak and "
        "sluggish for $agent_possessive_noun heresy.", who, 0,
        environment(who));
    }
    else {
      send_messages( ({ "falter", "" }), "$agent_possessive_noun faith falters and "
        "the Lord of Chaos curses $target_name causing $target_objective to become weakened "
        "sluggish.", who, target,
        environment(target));
    }
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

  if (target == who) {
    send_messages( ({ "call" }), "$agent_name $agent_verb out to the Lord of Chaos "
                  "who upon hearing $agent_possessive_noun cry, bestows "
                   "$agent_objective with unholy powers. ", who, 0, environment(who));
  }
  else {
    send_messages( ({ "call" }), "$agent_name $agent_verb out to the Lord of Chaos "
                  "who upon hearing $agent_possessive_noun cry, bestows "
                   "$target_name with unholy powers. ", 
                   who, target, environment(target));
  }
  target->AddBlessed(amt);
  target->AddCaffeine(amt2);
  target->AddStatBonus("durability", amt, dur);
  target->AddStatBonus("strength", amt, dur);
  return 1;
}

int eventEndForce(object who) {
        if (!who) {
                return 1;
        }
        who->RemoveProperty("unholy_power");
        who->RemoveProperty("planar_strength");
        who->RemoveProperty("planar_durability");
        who->RemoveStatBonus("strength");
        who->RemoveStatBonus("durability");
        who->eventPrint("%^BOLD%^YELLOW%^The Unholy Power leaves you.%^RESET%^");
        return 1;
}
