//
// With code stolen from the cloud kill spell by Zaxan
// Amelia@Haven
// "joyful rain"--Heals good, kinda heals neutral, and hurts baddies.  Area effect.

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

void eventHealGood(object who, int level, object target, int length, int i);
void eventHealNeutral(object who, int level, object target, int length, int i);
void eventHarmEvil(object who, int level, object target, int length, int i);
void eventGeneralMessages(object who, int level, object target, int length, int i);

static void create() {
   spell::create();
   SetSpell("joyful rain");
   SetRules("");
   SetAreaSpell(1);
   SetSpellType(SPELL_OTHER);
   SetMagicCost(125, 50);
   SetSkills( ([
          "natural magic" : 150,
           "enchantment" : 150,
    ]) );
   SetMorality(55);
   SetDifficulty(75);
  SetHelp("Eclats can call upon nature to bring a joyful rain that heals their "
	"friends and harms their enemies.");
}

int CanCast(object who, int level, string limb, object array targets) {
   if(environment(who)->GetProperty("joyful_rain")) {
	who->eventPrint("A joyful rain is already falling here.");
        return 0;
   }
   if(who->GetMorality() < 500) {
	who->eventPrint("The blessing of the joyful rain eludes your skill, "
		"for your are not morally strong enough to handle the "
		"power.");
        return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object array targets) {
   int i = 0;
   int length = (level/10)+1;
      send_messages("call","$agent_name $agent_verb "
                    "rain from the sky, soaking everything "
	            "in the area.",who,0,environment(who));
      environment(who)->SetProperty("joyful_rain",1);
      foreach(object targ in targets) {
		targ->SetProperty("joyful_rain",1);
		switch(targ->GetMorality()) {
			case 200..2500:
			eventHealGood(who, level, targ, length, i);
			break;
			case -200..199:
			eventHealNeutral(who, level, targ, length, i);
			break;
			case -2500..-201:
			eventHarmEvil(who, level, targ, length,i);
			targ->AddEnemy(who);
			break;
		}
      }
      eventGeneralMessages(who, level, targets[0], length,i);
      return 1;
}


void eventHarmEvil(object who, int level, object target, int length, int i) {
   int damage = (GetDamage() * level)/100;
   if(target->GetRace() == "orc") damage = damage*1.05;
   damage = damage*( ((target->GetMorality())/1250000) +1);
   if(!environment(target)->GetProperty("joyful_rain")) {
	target->eventPrint("You have safely moved outside of the blessed rain, and "
		"its pure joy will hurt you no longer.");
	target->RemoveProperty("joyful_rain");
	return;
   }
   if(target && (i < length)) {
      send_messages("","The rain fizzes like acid as it hits "
		"$target_possessive_noun face.",0,target,environment(target));
      target->eventReceiveDamage(0, ACID, damage, GetAutoDamage(), 0);
      i = i+1;
      call_out((: eventHarmEvil($(who),$(level),$(target),$(length),$(i)) :), 60);
      return;
   }
   target->RemoveProperty("joyful_rain");
   return;
}

void eventHealGood(object who, int level, object target, int length, int i) {
   int damage = (GetDamage() * level)/100;
   if(!environment(target)->GetProperty("joyful_rain")) {
	target->eventPrint("You have left the protection of the joyful rain.");
	target->RemoveProperty("joyful_rain");
	return;
   }
   if(target && (i < length)) {
      send_messages("","Ecstatic joy crosses $target_possessive_noun face as "
		"the joyful rain hits $target_objective.",
		0,target,environment(target));
      target->eventCompleteHeal(damage);
      i = i+1;
      call_out((: eventHealGood($(who),$(level),$(target),$(length),$(i)) :), 60);
      return;
   }
   target->RemoveProperty("joyful_rain");
   return;
}

void eventHealNeutral(object who, int level, object target, int length, int i) {
   int damage = (GetDamage() * level)/100;
   if(!environment(target)->GetProperty("joyful_rain")) {
	target->eventPrint("You have left the joyful rain behind.");
	target->RemoveProperty("joyful_rain");
	return;
   }
   if(target && (i < length)) {
      send_messages("","A slightly happy expression crosses "
		"$target_possessive_noun face as "
		"the joyful rain hits $target_objective.",
		who,target,environment(target));
      target->eventCompleteHeal(damage/2);
      i = i+1;
      call_out((: eventHealNeutral($(who),$(level),$(target),$(length),$(i)) :), 60);
      return;
   }
   target->RemoveProperty("joyful_rain");
   return;
}

void eventGeneralMessages(object who, int level, object target, int length, int i) {
	if(i<length) {
		i++;
		send_messages("","$agent_possessive_noun joyful rain soaks the "
			"area.",who,0,environment(who));
		call_out( (: eventGeneralMessages($(who),$(level),$(target),
					$(length),$(i)) :), 60);
		foreach(object targ in all_inventory(environment(who))) {
			if((living(targ)) && !targ->GetProperty("joyful_rain")) {
				targ->SetProperty("joyful_rain",1);
				switch(targ->GetMorality()) {
					case 200..2500:
					eventHealGood(who, level, targ, length, i);
					break;
					case -200..199:
					eventHealNeutral(who, level, targ, length, i);
					break;
					case -2500..-201:
					eventHarmEvil(who, level, targ, length,i);
					targ->AddEnemy(who);
					break;
				}
			}
		}
		return;
	}
	send_messages("","$agent_possessive_noun joyful rain slowly dissipates, returning the "
		"weather to normal.",who,0,environment(who));
	environment(who)->RemoveProperty("joyful_rain");
	return;
}