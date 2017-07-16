/*  A mana parasite */
#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;
void eventSuffer();

static void create() {
  ::create();
  SetKeyName("mana leech");
  SetShort("the mana leech");
  SetContagious(0);
  SetCureChance(75);
  SetLifeSpan(10);
  SetSuffer( (: eventSuffer :) );
}

void eventSuffer() {
  object who = environment();
  if (!who) return;
  
  send_messages("",
     "$agent_possessive_noun magical energies dissipate into the air.",
     who, 0, environment(who) );
  who->AddMagicPoints(-(GetLifeSpan())*10);
  who->AddStaminaPoints(-(GetLifeSpan())*5);
  if(!random(4)) who->eventCollapse();
}
