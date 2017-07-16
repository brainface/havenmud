// The 'poison explosion' spell
// Zeratul@Haven
// 11/05/2001

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("poison explosion");
  SetSkills( ([
     "necromancy" : 200,
     "conjuring"  : 200,
  ]) );
  SetRecoveryTime(random(2)+2);
  SetRules("");
  SetMorality(-15);
  SetAreaSpell(1);
  SetSpellType(SPELL_COMBAT);
  SetEnhanceSkills( ({ "poison magic" }) );
  SetHelp(
     "Using necromantic powers, the caster summons up a ball of poison that "
     "explodes, poisoning everyone in the room other than the caster. "
     "The effectiveness of this spell depends on the casters skill. "
  );
}

varargs int eventCast(object who, int level, mixed b, object array targets) {
  object env = environment(who);
  send_messages("summon", "$agent_name $agent_verb a ball of %^RED%^poison%^RESET%^ "
     "that %^ORANGE%^BOLD%^explodes%^RESET%^, filling the entire room!",
     who, 0, env);
  who->eventForce("cackle");
    if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
          }
  foreach(object thing in all_inventory(env)) {
    if(living(thing) && !userp(thing)) {
      thing->eventReceiveDamage(who, POISON, GetDamage(level), 0, thing->GetRandomLimb(thing->GetTorso()));
      thing->AddPoison(level);
      thing->AddEnemy(who);
     }
   }
  return 1;
}
