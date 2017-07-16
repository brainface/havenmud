#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;

int eventSuffer();

static void create() {
  ::create();
  SetKeyName("flu");
  SetLifeSpan(15);
  SetContagious(40);
  SetCureChance(15);
  SetSuffer( (: eventSuffer :) );
  }

int eventSuffer() {
  object who = environment();
  if (!who) return 0;

  message("system",
    "The flu takes it toll on you.",
    who);
  who->AddStaminaPoints(-50);
  message("system", 
    who->GetCapName() + " looks ill.", 
    environment(who), who);
  return 1;
 }
