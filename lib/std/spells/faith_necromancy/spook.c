// Title: Saahagoth Clerical Spells
// File: spook.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: Scares the target out of the room, if the target is not
//                      a player, it will return automatically after a short time
//
// Revision History: 
//

#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

int Return(object who, string OldRoom);

static void create() {
	spell::create();
	SetSpell("spook");
	SetRules("", "LIV");
	SetSpellType(SPELL_COMBAT);
	SetSkills( ([
     "necromancy" : 5,
     "faith"      : 5,
		]) );
	SetDifficulty(20);
  SetHelp(
		"Using this spell the necromancers draw on "
		"the darks powers to fill the target with "
		"fear, causing them to flee from the caster for a short time."
		);
	}

varargs int eventCast(object who, int level, mixed limb, object array targets) {
	object target = targets[0];
	object environ;
	string *exits;
	float agentLevel, targetLevel;
	agentLevel = who->GetLevel() * (who->GetSpellLevel("spook") + 10);
	targetLevel = target->GetLevel() * (100 + random(21));
  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
	    who->eventPrint("Your powers fail you.");
	    return 0;
	}
 	if( !(agentLevel >= targetLevel) ) {
		send_messages(({"attempt","are",}), "$agent_name "
			"$agent_verb to spook $target_name, but $target_name "
			"$target_verb unfazed.", who, target, environment(who));
		if(!userp(target))
			target->AddEnemy(who);
		return 1;
		}
	else if( target->GetParalyzed() ) {
		send_messages(({"attempt","are"}),"$target_name is spooked by "
			"$agent_possessive_noun spell and $target_verb "
			"to flee, but $target_nominative $target_verb unable "
			"to move.", who, target, environment(who));
		if(!userp(target))
			target->AddEnemy(who);
		return 1;
		}
	else {
		environ = environment(who);
		exits = environ->GetExits();
		if( !sizeof(exits) ) {
			send_messages(({"are","attempt","have"}), "$target_name "
				"$target_verb spooked by $agent_possessive_noun "
				"spell and $target_verb to flee, but "
				"$target_nominative $target_verb nowhere to go.",
				who, target, environment(who));
			if(!userp(target))
				target->AddEnemy(who);
			return 1;
			}
		else {
			string NewRoom, OldRoom;
			NewRoom = exits[random(sizeof(exits))];
			NewRoom = environment(who)->GetExit(NewRoom);
			OldRoom = base_name(environment(who));
			send_messages(({"are","flee"}),"$target_name "
				"$target_verb spooked by $agent_possessive_noun "
				"spell and $target_verb out of the room.",
				who, target, environment(who));
			if(!userp(target))
				target->AddEnemy(who);
			if( !target->eventMove(NewRoom) ) {
				send_messages("are", "$target_name $target_verb "
					"knocked back into the room.", who, target,
					environment(who));
				return 1;
				}
			target->eventDescribeEnvironment(0);
			if( !userp(target) ) {
				call_out( (: call_other, this_object(), "Return",
					target, OldRoom :),
					(who->GetSpellLevel("spook") / 10) +
					(who->GetSkillLevel("necromancy") / 2));
				}
			}
		}
	return 1;
	}

int Return(object who, string OldRoom) {
	if( !who )
		return 0;
	who->eventMoveLiving(OldRoom, "$N leaves angrily.",
		"$N enters angrily.");
	return 1;
	}


