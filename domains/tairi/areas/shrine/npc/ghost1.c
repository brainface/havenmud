#include <lib.h>
#include <damage_types.h>
#include "../shrine.h"

inherit LIB_SENTIENT;

string DoDie();
static void create() {
  sentient::create();
  SetShort("a translucent yurei");
  SetLong("From the appearance of this yurei, the body"
          " it once inhabited was a powerfully built man"
          " with broad soldiers and abnormally sized thigh"
          " muscles. Although nearly transparent, this"
          " yurei looks more than capable of delivering a"
          " powerful blow or running a great distance.");
  SetKeyName("translucent yurei");
  SetId("yurei");
  SetAdjectives("translucent");
  SetRace("human");
  SetClass("fighter");
  SetBaseLanguage("Tai");
  SetMorality(0);
  SetGender("male");
  SetSkill("melee combat",1,1);
  SetLevel(8 + random(15) );
  SetMeleeAttackString("%^BLUE%^icy%^RESET%^ touch");
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
