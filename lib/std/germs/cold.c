#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;
void eventSuffer();

static void create() {
  ::create();
  SetKeyName("common cold");
  SetShort("the common cold");
  SetInvis(4);
  SetId( ({ "cold" }) );
  SetContagious(25);
  SetLifeSpan(20);
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
  switch (random(3)) {
    case 0:
      send_messages("sneeze", "$agent_name $agent_verb.", environment(), 0, environment(environment()));
      environment()->AddStaminaPoints(-20);
      break;
    case 1:
      send_messages("cough", "$agent_name $agent_verb.", environment(), 0, environment(environment()));
      environment()->AddStaminaPoints(-30);
      environment()->eventReceiveDamage(this_object(), DISEASE, random(10), 1);
      break;
    case 2:
      send_messages(({ "sniffle", "wipe" }), "$agent_name $agent_verb and $agent_verb $agent_possessive nose.",
                     environment(), 0, environment(environment()));
      environment()->eventReceiveDamage(this_object(), DISEASE, random(10), 1);
      environment()->AddStaminaPoints(-30);
      break;
    }
}

