#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;
void eventSuffer();

static void create() {
  ::create();
  SetKeyName("breath");
  SetShort("breath of the ancestors");
  SetInvis(4);
  SetId( ({ "breath" }) );
  SetContagious(0);
  SetLifeSpan(50);
  SetCureChance(15);
  SetSuffer( (: eventSuffer :) );
}

void eventSuffer() {
  object who = environment();
  send_messages(({ "appear" }), 
    "%^CYAN%^$agent_name $agent_verb invigorated by the breath of "
    "$agent_possessive_noun ancestors.%^RESET%^", 
    environment(), 0, environment(environment()));
  environment()->AddStaminaPoints(25 + random(25));
}

