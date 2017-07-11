#include <lib.h>
#include "../averath.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("theodore");
  SetShort("Theodore the Master of Combat");
  SetId( ({"theodore", "master"}) );
  SetAdjectives( ({"master"}) );
  SetLong("Theodore is a huge man, with bulging muscles. He is well known "
          "in Averath for his expert skills in battle. His name is also "
          "well known in the neighbouring city of Dalnairn, where he is "
          "greatly feared.");
  SetTown("Averath");
  SetRace("human");
  SetGender("male");
  SetClass("fighter");
  SetSkill("melee combat",1,1);
  SetLevel(200);
  SetBaseLanguage("Avera");
  SetCurrency( ([
       "ducats" : random(150) + 100,
        ]) );
  SetMorality(200);
  SetAction(7,
      "!say I long for battle. Have there been any Duergar spotted near the "
        "gates of late?"
        );
  SetCombatAction(5, ({
                "!disorient",
                "!disarm",
                }) );
  SetInventory( ([        
        "/std/weapon/knife/small_knife" : 2,
                ]) );
  SetFirstCommands( ({ "wield knives" }) );
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("knife combat");
  AddTrainingSkills("projectile combat");    
  AddTrainingSkills("metal working");
  AddTrainingSkills("mithril working");
  AddTrainingSkills("leather working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("weapon smithing");
}
