// Planar Durability type spell
// increases str and dur
// Davantalus@Haven 20040903

#include <lib.h>
#include <magic.h>

int eventEndForce(object);
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("force of nature");
  SetSpellType(SPELL_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
     "natural magic" : 125,
     "enchantment" : 125,
  ]) );
  SetMagicCost(120, 120);
  SetDifficulty(152); 
  SetHelp(
          "Using this spell, a powerful druid may call upon the forces "
          "of nature to empower their target with increased strength and "
          "durability.  However, the forces of nature is not easily "
          "harnessed and mishaps have been known to occur."
     );
}
int CanCast(object who, int level, mixed limb, object array targets)
{
  object target = targets[0];
  if(target->GetProperty("nature_force") && (who == targets[0]))
  {
    message("system", "You have already been imbued with the "
            "forces of nature.", who);
    return 0;
  }
  else if( target->GetProperty("nature_force"))
  {
    message("system", "That person has already been imbued with the "
            "forces of nature.", who);
    return 0;
  }
  else if(target->GetUndead())
  {
    message("system", "The undead cannot be imbued by the forces of "
            "nature.", who);    
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
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets)  {
  int amt, dur;
  object target = targets[0];
  amt = (level + who->GetSkillLevel("enchantment") +
    who->GetSkillLevel("natural"))/12;
  dur = level * 10 + 5;
  target->SetProperty("nature_force", 1);
  target->SetProperty("planar_durability", 1);
    target->SetProperty("planar_strength", 1);
  call_out( (: eventEndForce, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("durability", -amt, dur);
    target->AddStatBonus("strength", -amt, dur);
    if (target == who) {
      send_messages( ({ "lose", "cause" }), "$agent_name $agent_verb control "
        "of the natural forces and $agent_verb $agent_possessive_noun to become weak and "
        "sluggish.", who, 0,
        environment(who));
    }
    else {
      send_messages( ({ "lose", "cause" }), "$agent_name $agent_verb control "
        "of the natural forces and $target_verb $target_possessive_noun to become weak and "
        "sluggish.", who, target,
        environment(target));
    }
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

  if (target == who) {
    send_messages( ({ "harness", "bend" }), "$agent_name $agent_verb "
                  "the forces of nature around $agent_reflexive and "
                   "$agent_verb them to enhance $agent_possessive_noun physical prowess. ", who, 0, environment(who));
  }
  else {
    send_messages( ({ "harness", "bend" }), "$agent_name $agent_verb "
                  "the forces of nature around $agent_reflexive and "
                   "$agent_verb them to enhance $target_possessive_noun physical prowess. ", 
                   who, target, environment(target));
  }
  target->AddStatBonus("durability", amt, dur);
  target->AddStatBonus("strength", amt, dur);
  return 1;
}

int eventEndForce(object who) {
        if (!who) {
                return 1;
        }
        who->RemoveProperty("nature_force");
        who->RemoveProperty("planar_strength");
        who->RemoveProperty("planar_durability");
        who->RemoveStatBonus("strength");
        who->RemoveStatBonus("durability");
        who->eventPrint("%^BOLD%^GREEN%^You return to normal.%^RESET%^");
        return 1;
}
