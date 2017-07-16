#include <lib.h>
#include <damage_types.h>

inherit LIB_GERM;
void eventSuffer();

static void create() {
  ::create();
  SetKeyName("pestilentia");
  SetShort("pestilentia");
  SetInvis(2);
  SetId( ({ "pestilentia", "pestilence" }) );
  SetContagious(0);
  SetLifeSpan(45);
  SetCureChance(350);
  SetSuffer( (: eventSuffer :) );
  }

void eventSuffer() {
 int amt = environment()->GetThirst();
   
if (!environment()) {
    eventDestruct();
    return;
  }
if (!living(environment())) {
   eventDestruct();
   return;
  }
switch (random(5)) {
case 0:
send_messages("vomit", "$agent_name $agent_verb blood.",
            environment(), 0, environment(environment()));
environment()->AddFood(-50);
environment()->AddDrink(-50);
break;
case 1:
send_messages("writhe", "$agent_name $agent_verb is pain as"
              " boils appear on $agent_possessive body.",
              environment(), 0, environment(environment()));
      environment()->AddBleeding(15);
      environment()->eventReceiveDamage(this_object(), DISEASE, random(45), 1);
      break;
    case 2:
    send_messages("scream", "$agent_name $agent_verb as blood"
                  " erupts from every oriface on $agent_possessive"
                  " body.", environment(), 0, environment(environment()));
    environment()->AddBleeding(25);
    environment()->eventReceiveDamage(this_object(), DISEASE, random(45), 1);
    break;
    case 3:
    send_messages("shake", "$agent_name $agent_verb violently as overwhelming"
                  " thirst consumes $agent_objective.", 
                  environment(), 0, environment(environment()));
    environment()->AddThirst(-amt);
    break;
    case 4:
    send_messages("vomit", "$agent_name $agent_verb uncontrollably.",
                    environment(), 0, environment(environment()));
      environment()->AddHunger(-200);
      break;
    }
 } 
