/*  A mana parasite */
#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;
int eventSuffer();

static void create() {
  germ::create();
  SetKeyName("mana leech");
  SetShort("the mana leech");
  SetContagious(75);
  SetCureChance(75);
  SetLifeSpan(120);
  SetSuffer( (: eventSuffer :) );
}

int eventSuffer() {
  object who = environment();
  if(GetLifeSpan()>30) return 1;

  if (!who) return 0;
  send_messages("suffer",
     "$agent_name $agent_verb from the mana leech.",
     who, 0, environment(who) );
//  who->eventReceiveDamage(this_object(), HUNGER, 45, 1);
  who->AddMagicPoints(-(30-GetLifeSpan())*10);
  who->AddStaminaPoints(-(30-GetLifeSpan())*10);
  if(!random(4)) who->eventCollapse();
    return 1;
}

