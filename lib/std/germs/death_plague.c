/*  The death plague
 *  To be released.
 */
#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;

int eventSuffer();

static void create() {
  ::create();
  SetKeyName("death plague");
  SetLifeSpan(50);
  SetContagious(175);
  SetCureChance(5);
  SetSuffer( (: eventSuffer :) );
  }

int eventSuffer() {
  object who = environment();
  if (!who) return 0;

  message("system",
    "The death plague takes it toll on you.",
    who);
  who->eventReceiveDamage(this_object(), DISEASE, 100, 1);
  who->AddStaminaPoints(-100);
  message("system", 
    who->GetCapName() + " looks ill.", 
    environment(who), who);
  return 1;
 }
