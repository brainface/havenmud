#include <lib.h>
#include "../path.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("delga");
  SetId( ({ "delga", "trainer","dwarf" }) );
  SetRace("dwarf");
  SetGender("female");
 
  SetTown("Glimmerdin");
  SetLevel(45);
  SetMorality(100);
  SetShort("Delga, a trainer of combat skills");
  SetLong("Delga is a fighter of some reknown.  She is also a "
    "teacher in the ways of combat. Perhaps you could ask her to "
    "teach you something?");
  SetAdjectives( ({ }) );
  SetAction(5, ({
    "!speak You could <ask delga to train>",
    "Delga stretches to prevent muscle cramping.",
    "Delga surveys the scene confidently.",
  }) );

  SetTown("Glimmerdin");
  SetSkill("dodge",1,2);
  SetSkill("accuracy",1,2);
  SetSkill("combat rage",1,2);
  
  AddTrainingSkills("slash combat");
  AddTrainingSkills("knife combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("blunt combat");
  AddTrainingSkill("pole combat");
  AddTrainingSkill("projectile combat");
  AddTrainingSkills("multi-weapon"); 
  AddTrainingSkill("melee combat");
  SetLevel(45);
   
}
