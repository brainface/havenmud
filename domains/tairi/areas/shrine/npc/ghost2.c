#include <lib.h>
#include <damage_types.h>
#include "../shrine.h"

inherit LIB_SENTIENT;

string DoDie();
static void create() {
  sentient::create();
  SetShort("a shrieking yurei");
  SetLong("Small and almost dainty, this yurei"
          " appears to have once been a beautiful"
          " woman. However beautiful she may have"
          " been, the pain and misery of her life"
          " has been etched into her face by way"
          " of permanently tear streaked cheeks.");
  SetKeyName("shrieking yurei");
  SetId("yurei");
  SetAdjectives("shrieking");
  SetRace("human");
  SetClass("fighter");
  SetBaseLanguage("Tai");
  SetMorality(0);
  SetGender("female");
  SetSkill("melee combat",1,1);
  SetLevel(8 + random(5) );
  SetMeleeAttackString("%^BLUE%^icy%^RESET%^ touch");
  SetMeleeDamageType(COLD);
  SetDie( (: DoDie :) );
  SetUndead(1);
  SetUndeadType("ghost");
  SetNoCorpse(1);
  SetAction(15, ({
          "!emote wails uncontrollably.",
          "!yell Please! No! Not again!!",
          "!emote shrieks.",
          "!emote cries.",
     }) );
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
