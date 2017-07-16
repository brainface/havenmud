#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;
inherit LIB_FEAR;

static void create(){
	spell::create();
	SetSpell("phantom army");
	SetSpellType(SPELL_COMBAT);
	SetRules("", "LIV");
	SetSkills(  ([
         "faith" : 30,
       "necromancy" : 30,
		])  );
  SetReligions( ({ "Aberach" }) );
  SetMaximumMorality(-200);
	SetDifficulty(20);
  SetHelp(
		"This spell causes the target to see an army of undead "
		"coming towards them. This can result in paralysis "
		"due to fear. Chances depend on "
		"the casters spell level, faith, and the fear resistance "
		"of the target.  ");
}

int CanCast(object who, int level, mixed limb, object array targets) {
   object target = targets[0];

   if (target->GetParalyzed()) {
       who->eventPrint("That target is already paralyzed!");
       return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, string limb, object array targets) {
   object target = targets[0];
   int dur = level - target->GetLevel();    
  // int dur = 1 + random(who->GetSkillLevel("necromancy"));
   int chance = level + who->GetSkillLevel("faith") + who->GetSkillLevel("necromancy");
   int rnd = random(100);
/* modified to not be super bs by Melchezidek 20110831 */
      if ( dur <= 0 ) {
		dur = 5;
	}
      if ( dur >= 20 ) {
		dur = 20;
	}  
/* end mod */
      if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
        } 
       
   chance -= target->GetSkillLevel("faith") + target->GetStatLevel("wisdom") + (target->GetLevel() * 2);

   if (chance >= rnd) {
	send_messages(({"freeze"}), "$target_name $target_verb in "
		"%^RED%^fear %^RESET%^of the approaching army.  ",
		who, target, environment(who));
	target->SetProperty("phant_army", 1);
	SetFearType("army");
	eventCauseFear(target, dur);
	return 1;
   } else {
	message("system","The spell fails.", who);
   }
}


/* Approved by Zaxan on Wed Feb 11 00:39:41 1998. */
