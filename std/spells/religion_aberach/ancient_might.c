#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
	spell::create();
	SetSpell("ancient might");
	SetSpellType(SPELL_OTHER);
	SetRules("", "LIV");
	SetSkills(  ([
                "faith" : 30,
                "necromancy" : 30,
		])  );
	SetMagicCost(30, 30);
  SetMaximumMorality(-200);
	SetStaminaCost(15, 10);
	SetDifficulty(15);
  SetHelp(
		"With this spell the caster calls on the deity to "
		"infuse the caster with the strength of a hero of "
		"long ago.  The duration of the spell and the amount "
		"of strength recieved depends on the caster's mastery "
		"of the spell.  ");
  SetReligions( ({ "Aberach" }) );
}

int CanCast(object who, int level, mixed limb, object array targets) {
   object target = targets[0];

   if(target->GetProperty("ancient_might") || target->GetProperty("planar_strength")) {
      message("system","For some reason the spell refuses "
		"to work.  ", who);
      return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets)  {
  object target = targets[0];
  int amt = (level + who->GetSkillLevel("faith") + who->GetSkillLevel("necromancy"))/20;
  int dur = level * 7 + 5;
  
  if (target==who) {
	send_messages("infuse",
		"$agent_name $agent_verb $agent_reflexive with the " +
		"strength of the ancients.  ",
		who, 0, environment(who));
	}
  else {
	send_messages("infuse",
		"$agent_name $agent_verb $target_name with the " +
		"strength of the ancients.  ",
		who, target, environment(target));
  }

  target->AddStatBonus("strength",amt);
   target->SetProperty("planar_strength", 1);
   target->SetProperty("ancient_might", 1);

 call_out(function(object target) {
	if(target) {
        message("system","%^RED%^The strength leaves you.  %^RESET%^",
		target);
	target->RemoveStatBonus("strength");
        target->RemoveProperty("planar_strength");
	target->RemoveProperty("ancient_might");
	}
   }, dur, target);
   return 1;
}


/* Approved by Zaxan on Wed Feb 11 00:37:17 1998. */
