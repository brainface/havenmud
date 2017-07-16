/*  A wasting sickness */
#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;
int eventSuffer();

static void create() {
  germ::create();
  SetKeyName("wasting sickness");
  SetShort("the wasting sickness");
  SetContagious(75);
  SetCureChance(15);
  SetLifeSpan(20);
  SetSuffer( (: eventSuffer :) );
}

int eventSuffer() {
  object who = environment();

  if (!who) return 0;
  send_messages("suffer",
     "$agent_name $agent_verb from the wasting sickness.",
     who, 0, environment(who) );
  who->eventReceiveDamage(this_object(), HUNGER, 45, 1);
  who->AddStaminaPoints(-80);
  if(!random(4)) who->eventCollapse();
    return 1;
}
