#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
	spell::create();
	SetSpell("incite violence");
	SetSpellType(SPELL_OTHER);
	SetRules("LIV");
	SetSkills(  ([
      "faith" : 70,
      "necromancy" : 70,
		])  );
	SetRequiredMagic(100);
  SetReligions( ({ "Aberach" }) );
  SetMagicCost(150,100);
  SetMaximumMorality(-1000);
	SetDifficulty(20);
  SetHelp(
		"This spell will cause the target to attack everyone "
		"in the room, including the caster.  The chances of "
		"success depend on the caster's mastery of the spell and "
		"the level of the target.  ");
	
}

int CanCast(object who, int level, mixed limb, object array targets)  {
   object target = targets[0];

   if (target == who) {
      message("system","Cast it on yourself?", who);
      return 0;
   }
   if(newbiep(target))  {
      message("system", "You can't cast that on a newbie!"
              ,who);
      return 0;
      }
   return spell::CanCast(who, level, limb, targets);

}

int eventCast(object who, int level, string limb, object array targets)  {
  object target = targets[0];
  int chance = level + random(who->GetSkillLevel("faith"));
  chance -= target->GetLevel();

  if (chance > (random(10) + 30) ) {
	send_messages("point",
		"$agent_name $agent_verb at $target_name "
		"and $target_nominative is filled with %^BOLD%^RED%^"
		"RAGE!"
		"%^RESET%^", who, target, environment(who));
	target->eventForce("attack all");
	return 1;
	}
  else {
	who->eventForce("say Uh oh .........");
	who->eventForce("attack all");
	return 1;
	}
}


