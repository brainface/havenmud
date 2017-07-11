#include <lib.h>
#include <damage_types.h>
#include "../shrine.h"

inherit LIB_SENTIENT;

string DoDie();
static void create() {
  sentient::create();
  SetShort("a fearsome yurei");
  SetLong("What was once an abnormally large male"
          " is now an apparition that obscures the"
          " entire area he inhabits. His entire"
          " body was once a finely tuned face bashing"
          " machine and his watermelon sized fists"
          " look as though they could easily break"
          " a sturdy door down in one punch.");
  SetKeyName("fearsome yurei");
  SetId("yurei");
  SetAdjectives("fearsome");
  SetRace("human");
  SetClass("fighter");
  SetBaseLanguage("Tai");
  SetMorality(0);
  SetGender("male");
  SetSkill("melee combat",1,1);
  SetLevel(10 + random(25) );
  SetMeleeAttackString("%^BLUE%^icy%^RESET%^ bash");
  SetMeleeDamageType(COLD);
  SetDie( (: DoDie :) );
  SetUndead(1);
  SetUndeadType("ghost");
  SetNoCorpse(1);
  SetResistance(SLASH, "immune");
  SetResistance(PIERCE, "immune");
  SetResistance(BLUNT, "immune");
  SetResistance(HUNGER, "immune");
  SetResistance(DISEASE, "immune");
}


string DoDie() {
 new(SHRINE_OBJ "token")->eventMove(environment());
 message("die",
      "The apparation dissolves into a thin mist leaving"
      " behind a spirit token.",
      environment() );
 return "";     
}
