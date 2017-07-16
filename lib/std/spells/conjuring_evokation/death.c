/*  A spell of death */
#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("death");
  SetUniqueSpell(1);
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
    "evokation" : 250,
    "conjuring" : 250,
    ]) );
  SetDifficulty(250);
  SetMorality(-50);
  SetEnhanceSkills( ({ "necromancy" }) );
  SetHelp(
    "This ultimate combat spell has only one aim: utter destruction of the target. "
    "This spell is a vile, evil attack directly upon the body of the target in an "
    "attempt to get the body to immediately surrender life with no further resistance. "
    "It is very costly and very difficult."
    );
  SetStaminaCost((random(250)+250));
}

varargs int eventCast(object who, int level, mixed x, object *t) {
  object target = t[0];
  string race   = (target->GetRace());
  int dead      = (target->GetUndead());
  int chance    = who->GetSkillLevel("evokation") + who->GetSkillLevel("necromancy");
  chance = chance * level/100;
  if( CanAttack(who, t, GetSpellLevel() + level/5) == - 1 ) {
	    who->eventPrint("Your powers fail you.");
	    return 0;
	}  
  if (dead == 1) { who->eventPrint("But that creature is already dead!");  return 1;  }
  if (random(chance) > target->GetMagicResistance() * 4 )  {
     send_messages("strike",
          "$agent_name $agent_verb $target_name %^RED%^BOLD%^dead " 
          "%^RESET%^with the power of $agent_possessive magic!",
          who, target, environment(who) );
     target->eventDie(who);
     return 1;
     }
  send_messages("summon",
        "$agent_name $agent_verb %^RED%^BOLD%^deadly%^RESET%^ "
        "magical power against $target_name!",
        who, target, environment(target) );
  target->eventReceiveDamage(who, MAGIC, GetDamage(level), 0, target->GetTorso());
  return 1;
}
