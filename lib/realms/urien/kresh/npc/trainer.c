#include <lib.h>
#include "../goblins.h"
inherit LIB_TRAINER;

static void create() {
  trainer::create();
  SetKeyName("jagatai");
  SetShort("Jagatai the Bloodrider of the Horde");
  SetId( ({ "jagatai", "bloodrider", "trainer","goblin" }) );
  SetAdjectives( ({ "bloodrider" }) );
  SetLong(
    "Jagatai is a Bloodrider for the Horde, meaning he is a personal guardian "
    "of the Khan. His training is offered to those who wish to learn.  His "
    "lessons are not cheap, nor are they without cost in development."
    );
  SetRace("goblin");
  SetGender("male");
  SetClass("fighter");
  SetMorality(-500);
  SetFriends( ({ "goblin" }) );
  SetInventory( ([
    GOBLIN_OBJ "orcslayer" : "wield orcslayer",   
    ]) );
    
  SetSkill("disarm",1,2);
  SetSkill("dodge",1,2);
  SetSkill("accuracy",1,2);
  SetSkill("parry",1,2);
  SetSkill("disorient",1,2);
  
  
  AddTrainingSkills("metal working");
  AddTrainingSkills("wood working");
  AddTrainingSkills("leather working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("natural working");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("weapon smithing");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("knife combat");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("pole combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("pierce combat");
  SetLevel(100);
  SetCurrency("rounds", random(3000));
  SetTown("Kresh");
  SetLimit(1);
  
  SetCombatAction(25, ({
  	"!disorient",
  	"!disarm",
  	}) );
  	
}
