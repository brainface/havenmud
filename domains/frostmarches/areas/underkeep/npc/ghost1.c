//
// a friendly female ghost
// created by Ranquest@Haven
//
#include <lib.h>
#include <damage_types.h>
#include "main.h"
 inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetShort("a flickering ghost");
  SetLong(
    "A flickering ghost stands here, the lost spirit of a woman"
    " unable to accept her fate in peace. Her translucent face"
    " and body are clothed in a writhing mist. Her face seems"
    " careworn and saddened by the meaningless destruction and"
    " violence that surrounds her.");
  SetKeyName("ghost");
  SetId("ghost");
  SetAdjectives("flickering");
  SetRace("human");
  SetClass("necromancer");
  SetMorality(50);
  SetGender("female");
  SetSkill("melee combat",1,1);
  SetLevel(30);
  SetSpellBook( ([
    "acid blast" : 100,
    "cloud kill" : 100,
    ]) );
  SetMeleeAttackString("cold fingers");
  SetMeleeDamageType(COLD);
  SetAction(5, 
    "The ghost lets out an unearthly lament."
     );
  SetCombatAction(7, ({
    "!cast acid blast",
    "!cast cloud kill",
    }) );
  SetDie("The spectre vanishes without a trace.");
  SetWander(20);
  SetUndead(1);
  SetUndeadType("ghost");
  SetNoCorpse(1);
  SetResistance(SLASH, "immune");
  SetResistance(PIERCE, "immune");
  SetResistance(BLUNT, "immune");
}
