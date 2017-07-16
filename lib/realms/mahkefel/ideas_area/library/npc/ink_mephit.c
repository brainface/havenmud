/* A minor opponent for Arcanith
 * mahkafel october '10         
 */                             

#include <lib.h>
#include <damage_types.h>
//#include "../arc_library.h"
inherit LIB_NPC;             

static void create() {
  npc::create();      
  SetKeyName("ink mephit");
  SetId( ({ "mephit"}) );   
  SetAdjectives( ({ "ink" }) );
  SetShort("an ink mephit");    
  SetLong(                      
    "This strange imp seems to have internalized the writing of the library. "
    "Entire epics worth of ink cover his pale, papyrus-like skin in "
    "writhing words. "
    "Whatever use he once had to the summoners of Arcanith is indescernable "
    "now."
  );
  SetGender("male");
  SetRace("demon","mephit");
  SetBaseLanguage("Archaic");
  SetClass("mystic");
  AddLimb("tail", "torso", 4);
  AddLimb("left wing", "torso", 4);
  AddLimb("right wing", "torso", 4);
  AddSkill("enchantment",1,1);
  SetLevel(35);
  SetAction(5, ({
    "!speak Ages of history, lost in an instant of flame.",
    "!speak Weep, weep mortal, for what was lost.",
    "!speak My bones are soaked in prose, my wings formed of poem.",
    "!emote douses a burning book with a jet of black ink.",
    "!emote leaks onto the floor below him.",
  }) );
  SetMorality(100);
  SetCombatAction(20, ({
    "!cast blindness",
    "!cast sphere",    
  }) );
  SetDie("The ink mephit collapses to the ground in a wad of gangly limbs, "
    "as a puddle of black ink slowly stains the floor beneath him.");
  SetFirstCommands( ({ "cast sphere" }) );
  SetMeleeAttackString("%^BOLD%^BLACK%^oily%^RESET%^ claw");
  SetMeleeDamageType(PIERCE);
  SetResistance(ALL_DAMAGE, "low"); // reset resistances
  SetResistance(ALL_PHYSICAL, "medium");
  SetResistance(HEAT, "weakness");
}

