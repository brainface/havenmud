// An area poison type spell for thorians
// thoin@Haven
// 

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("venomous wind");
  SetSkills( ([
     "necromancy" : 130,
     "faith" : 130,
  ]) );
  SetRecoveryTime(random(2)+2);
  SetRules("");
  SetMorality(-15);
  SetAreaSpell(1);
  SetSpellType(SPELL_COMBAT);
  SetReligions("Thorian");
  SetEnhanceSkills( ({ "poison magic" }) ); 
  SetHelp(
     "Using the necromantic powers of his faith, a Thorian cleric can summon "
     "forth a poisonous wind to poison all in a room as well as hurting them. "
     "The effectiveness of this spell depends on the casters skill. "
  );
  }

varargs int eventCast(object who, int level, mixed limb, object array targets) {
	int damage, damageboost;
  object env = environment(who);
  damage = GetDamage(level);
	damageboost = who->GetSkillLevel("poison magic") / (GetSpellLevel() * 2);
	if (damageboost > 3) damageboost = 3;
	damage += damage * damageboost;
        
  if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
        } 
        
  send_messages("summon", "$agent_name $agent_verb a gust of "
     "%^BOLD%^%^BLACK%^black smoke%^RESET%^ "
     "that blows into the room filling it completely!",
     who, 0, env);
  who->eventForce("cackle evil");
  foreach(object thing in all_inventory(env)) {
    if(living(thing) && !userp(thing)) {
      thing->AddEnemy(who);
      thing->eventForce("cough");
      thing->AddPoison(level/4);
      thing->eventReceiveDamage(who, POISON, damage, 0, limb);
     }
   }
  return 1;
  }
