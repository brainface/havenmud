//
// Bird Flu
// Thoin@Haven
//
#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;
int eventSuffer();

static void create() {
  germ::create();
  SetKeyName("bird flu");
  SetShort("the bird flu");
  SetInvis(1);
  SetContagious(115);
  SetCureChance(15);
  SetLifeSpan(50);
  SetSuffer( (: eventSuffer :) );
  }

int eventSuffer() {
  object who = environment();

  if (!who) return 0;

  if (who->GetRace() == "bird") {
  SetLifeSpan(300);
  return 0;
  }

  if (GetLifeSpan()>50) return 1;
  
  switch (random(4)) {
    case 0:
      send_messages("sniffle", "$agent_name $agent_verb.", environment(), 0, environment(environment()));
      environment()->AddStaminaPoints(-20);
      environment()->eventReceiveDamage(this_object(), DISEASE, 5+random(15), 1);
      break;
    case 1:
      send_messages("sneeze", "$agent_name $agent_verb.", environment(), 0, environment(environment()));
      environment()->AddStaminaPoints(-25);
      environment()->eventReceiveDamage(this_object(), DISEASE, 10+random(15), 1);
      if(!random(4)) who->eventCollapse();
      break;
    case 2:
      send_messages("cough", "$agent_name $agent_verb.", environment(), 0, environment(environment()));
      environment()->AddStaminaPoints(-30);
      environment()->eventReceiveDamage(this_object(), DISEASE, 20+random(25), 1);
      if(!random(3)) who->eventCollapse();
      break;
    case 3:
      send_messages(({ "double", "vomit" }), "$agent_name $agent_verb over and $agent_verb.",
                     environment(), 0, environment(environment()));
      environment()->eventReceiveDamage(this_object(), DISEASE, 20+random(40), 1);
      environment()->AddStaminaPoints(-35);
      who->eventCollapse();
      break;
    }
 }
