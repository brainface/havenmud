#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
	::create();
	SetSpell("rejuvenation");
	SetRules("", "LIV");
	SetSkills( ([
          "faith"   : 30,
          "healing" : 30,
	  ]) );
	SetSpellType(SPELL_HEALING);
	SetDifficulty(20);
	SetHelp("By means of this spell, the caster attempts to restore stamina to "
	        "himself or a target.");
}

varargs int eventCast(object who, int level, mixed x, object *t) {
	object target = t[0];
	int rej;
	
	if (target->GetStaminaPoints() >= target->GetMaxStaminaPoints()) {
		who->eventPrint("That person needs no stamina.");
		return 1;
	}
	rej = who->GetSkillLevel("faith")/4;
         if(rej > 10) { rej = 10; }
	
	send_messages( ({ "touch" }),
	  "$agent_name $agent_verb $target_name lightly, restoring some " +
	  "%^GREEN%^energy%^RESET%^ to $target_objective.", 
	  who, target, environment(who) );
  target->AddStaminaPoints(rej);
  return 1;
}

	  
	
	
