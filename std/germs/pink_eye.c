// mahkefel 2011
//   a lot like common cold
//   but it's pinkeye, look out.
#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;
void eventSuffer();

static void create() {
  ::create();
  SetKeyName("pink-eye");
  SetShort("pink-eye");
  SetInvis(4);
  SetId( ({ "pink-eye" }) );
  SetContagious(10);
  SetLifeSpan(30);
  SetCureChance(80);
  SetSuffer( (: eventSuffer :) );
}

void eventSuffer() {
  if (!environment()) {
    eventDestruct();
    return;
  }
  if (!living(environment())) {
    eventDestruct();
    return;
  }

  // cut down messages/hurt to 33%
  if( GetLifeSpan() % 3 ) return;

  switch (random(3)) {
    case 0:
      send_messages("", "$agent_possessive_noun eyes water uncontrollably.",
        environment(), 0, environment(environment()));
      environment()->AddStaminaPoints(-20);
      break;
    case 1:
      send_messages("blink", "$agent_name $agent_verb.", environment(), 0, environment(environment()));
      environment()->AddStaminaPoints(-30);
      environment()->eventBlind(5);
      environment()->eventReceiveDamage(this_object(), DISEASE, random(10), 1);
      break;
    case 2:
      send_messages(({ "rub", "wipe" }), "$agent_name $agent_verb matter out of $agent_possessive "
        "blood shot eyes.", environment(), 0, environment(environment()));
      environment()->eventBlind(10);
      environment()->AddStaminaPoints(-30);
      break;
    }
}

