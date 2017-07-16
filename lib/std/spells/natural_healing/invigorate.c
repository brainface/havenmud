// Title: Invigorate spell
// File: invigorate.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: A natural magic and healing spell which gives the caster sp
//
// Revision History: 
//

#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
	spell::create();
	SetSpell("invigorate");
	SetRules("", "LIV");
  SetSpellType(SPELL_OTHER);
	SetSkills( ([
     "natural magic" : 10,
     "healing" : 10,
		]) );
	SetMagicCost(15, 10);
	SetDifficulty(20);
	SetHelp( 
		"Allows the caster to use draw on the energy of nature and "
		"their own energy reserves to invigorate the target, giving "
		"them more stamina."
		);
	}
varargs int CanCast(object who, int level, string limb, object array targets) {
	object target = targets[0];
	if( target->GetStaminaPoints() == target->GetMaxStaminaPoints()) {
		if( target == who )
			write("You do not need any more stamina.", who);
		else
			write(target->GetName()+" does not need any more stamina.",who);
		return 0;
		}
	return spell::CanCast(who, level, limb, targets);
	}

varargs int eventCast(object who, int level, mixed limb, object array targets) {
	int healing, modifier;
	object target = targets[0];
	modifier = (who->GetSkillLevel("healing") +
               who->GetSpellLevel("invigorate") )/ 40;
	if( modifier < 1 )
		modifier = 1;
        healing = (GetMagicCost(who) * modifier);
        if( healing > GetMagicCost(who) * 4 )
                healing = GetMagicCost(who) * 4;
	if( target == who )
		write("You invigorate yourself.",who);
	else {
		message("","You invigorate "+target->GetName()+".",who);
		message("",who->GetName()+" invigorates you.", target);
		message("",who->GetName()+" invigorates "+target->GetName()+
			".",environment(who), ({ target, who }));
		}
        target->AddStaminaPoints(to_int(healing/5));      
	return 1;
}


/* Approved by Morgoth on Mon Jul 13 16:31:17 1998. */
