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
 if (random(2)) return;
  send_messages(({ "appear" }), 
    "%^CYAN%^With a glowing body, $agent_name $agent_verb "
    "rejuvenated.%^RESET%^", 
    environment(), 0, environment(environment()));
 environment()->AddStaminaPoints(25 + random(25));
}
