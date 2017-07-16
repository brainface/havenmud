#include <lib.h>
#include <damage_types.h>
inherit LIB_GERM;

int eventSuffer();

static void create() {
  ::create();
  SetKeyName("trog flu");
  SetLifeSpan(5);
  SetContagious(60);
  SetCureChance(65);
  SetSuffer( (: eventSuffer :) );
  SetWarmth(20);
}

int eventSuffer() {
  object who = environment();
  if (!who) return 0;

  message("system",
    "The troglodyte flu takes it toll on you.",
    who);
  who->AddStaminaPoints(-15);
  who->AddMagicPoints(-15);
  message("system", 
    who->GetCapName() + " looks feverish.", 
    environment(who), who);
  return 1;
}

