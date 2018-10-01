// mahkefel 2013
#include <lib.h>
#include <damage_types.h>
inherit LIB_SENTIENT;
void eventSpecial();

static void create() {
  ::create();
  SetKeyName("thing");
  SetShort("a terrible animated thing");
  SetId( ({"thing"}) );
  SetDie("The terrible thing disintegrates into twitching meat.");
  SetNoCorpse(1);

  // note that racial resistances will override this e.g. mummy demons/angels.
  SetResistance(ALL_PHYSICAL, "low"); 
  SetResistance(HEAT, "vulnerable");
  SetResistance(SHOCK, "vulnerable");  
  
  SetWanderSpeed(5);
 /* SetCombatAction(5,
    (: eventSpecial :)
  );*/
}

// TODO:
//   make infection special
/*
void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();
  send_messages("curse",
    "$agent_name%^MAGENTA%^ $agent_verb%^RESET%^ $target_name "
    "with a touch of $agent_possessive bandaged hands!", who, target, environment() );
  target->eventReceiveDamage(who, MAGIC, random(100), 0,
    target->GetRandomLimb("head") );
  if (target->GetCursed() < 50) {
    target->AddCursed(random(20));
  }
  return;
}
*/
