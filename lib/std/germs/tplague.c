//
// Thorian Plague
// Thoin@Haven
//
#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;
int eventSuffer();

static void create() {
  germ::create();
  SetKeyName("blessed blight");
  SetShort("the blessed blight");
  SetInvis(1);
  SetContagious(250);
  SetCureChance(250);
  SetLifeSpan(25);
  SetSuffer( (: eventSuffer :) );
  }

int eventSuffer() {
  object who = environment();

  if (GetLifeSpan()>10) return 1;
  if (!who) return 0;
  if (who->GetReligion() != "Thorian") {
    SetContagious(0);
    SetLifeSpan(1);
    return 0;
  }

  switch (random(4)) {
    case 0:
      send_messages("sniffle", "$agent_name $agent_verb.", environment(), 0, environment(environment()));
      environment()->AddStaminaPoints(-20);
      environment()->AddHealthPoints(random(50)+50);
      who->eventPrint("You feel closer to Thoin");
      break;
    case 1:
      send_messages("sneeze", "$agent_name $agent_verb.", environment(), 0, environment(environment()));
      environment()->AddStaminaPoints(-40);
      environment()->AddMagicPoints(random(250)+250);
      who->eventPrint("You feel closer to Thoin");
      break;
    case 2:
      send_messages("cough", "$agent_name $agent_verb.", environment(), 0, environment(environment()));
      environment()->AddStaminaPoints(-60);
      environment()->AddBlessed(20);
      who->eventPrint("You feel closer to Thoin");
      break;
    case 3:
      send_messages(({ "scream" }), "$agent_name $agent_verb in pain as "
      "skin and muscle melts off $agent_possessive body.",
                     environment(), 0, environment(environment()));
      environment()->AddBleeding(1+random(10));
      environment()->AddStaminaPoints(80+random(80));
      who->eventPrint("You feel closer to Thoin");
      break;
    }
 }

