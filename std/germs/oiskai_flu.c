/*  Oiskai Flu, a nicer version of the wasting sickness */
/*  Amelia Aug 2004 */
#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;
int eventSuffer();

static void create() {
  germ::create();
  SetKeyName("oiskai flu");
  SetShort("the oiskai flu");
  SetContagious(40);
  SetCureChance(25);
  SetLifeSpan(30);
  SetSuffer( (: eventSuffer :) );
  }

int eventSuffer() {
  object who = environment();

  if (!who) return 0;
  send_messages("suffer",
     "$agent_name $agent_verb from the oiskai flu.",
     who, 0, environment(who) );
  who->eventReceiveDamage(this_object(), HUNGER, 20, 1);
  who->AddStaminaPoints(-30);
if(!random(4)) who->eventCollapse();
  return 1;
 }
