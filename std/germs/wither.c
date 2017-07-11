/* Withering Sickness, an STD */
#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;

int eventSuffer();
static void create() {
  ::create();
  SetKeyName("withering touch");
  SetContagious(50);
  SetCureChance(40);
  SetLifeSpan(40);
  SetSuffer( (: eventSuffer :) );
}

int eventSuffer() {
  object who = environment();

  if (!who) return 0;
  if(!who->GetSleeping()) {
    who->eventForce("shiver");
  who->AddStaminaPoints(-GetLifeSpan());
  }
    switch(random(4)) {
      case 0:
         send_messages( ({ "choke", "cough" }),
             "$agent_name $agent_verb and $agent_verb.",
             who, 0, environment(who));
          who->eventReceiveDamage(this_object(), BLUNT, random(20), 1);
         break;
     default:
         message("system", "You feel miserable.", who);
         break;
      }
 return 1;
}
