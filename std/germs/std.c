#include <lib.h>

inherit LIB_GERM;

void eventSuffer();

static void create() {
  germ::create();
  SetKeyName("nymphen syphilis");
  SetId( ({ "nymphen syphilis" }) );
  SetLifeSpan(30);
  SetCureChance(50);
  SetSuffer( (: eventSuffer :) );
}

void eventSuffer() {

  switch (random(4)) {
  case 0:
    environment()->AddHealthPoints(-8);
    environment()->AddStaminaPoints(-6);
    send_messages("squirm", "$agent_name $agent_verb uncomfortably.",
      environment(), 0, environment(environment()));    
    break;
  case 1:
    environment()->AddHealthPoints(-10);
    environment()->AddStaminaPoints(-10);
    send_messages(({"groan", "hold"}), "$agent_name $agent_verb in pain and $agent_verb $agent_possessive "
    "stomach.",
      environment(), 0, environment(environment()));    
    break;
  case 2:
    environment()->AddHealthPoints(-15);
    environment()->AddStaminaPoints(-15);
    send_messages("shiver", "$agent_name $agent_verb slightly.",
      environment(), 0, environment(environment()));    
  break;
  case 3:
    environment()->AddHealthPoints(-15);
    environment()->AddStaminaPoints(-20);
    send_messages(({"stumble", "faint"}), "$agent_name $agent_verb and $agent_verb.",
      environment(), 0, environment(environment()));
    environment()->SetSleeping(1);    
  break;
  }
}

