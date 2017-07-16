// Fighter Trainer for Karak and Argoth
// Taigis
// April 2005

#include <lib.h>
#include "../argoth.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("borgan");
  SetId( ({ "borgan", "trainer" }) );
  SetAdjectives( ({ "orc", "fighter" }) );
  SetShort("borgan, the Taskmaster");
  SetLong(
    "Borgan is an orc of moderate size, standing approximately five feet "
    "tall. His posture is slouched slightly forward, his arms hanging "
    "loosely down. Short fangs protrude upwards from the front corners of "
    "his bottom lip, curling slightly backwards. From either side of his "
    "somewhat flat skull rise pointed ears, somewhat canine in shape. "
    "The many scars scattered across his arms and shoulders suggest that "
    "he has significant combat experience and might be willing to <train> "
    "those who wish to learn."
  );
  SetRace("orc");
  SetGender("male");
  SetClass("fighter");
  SetTown("Karak");
  SetLevel(45);
  SetAction(5, ({
    "!speak You could <ask borgan to train>",
    "Borgan's ears swivel slightly, taking in the surrounding area.",
    "Borgan growls slightly, low in his throat.",
  }) );
  AddTrainingSkills("slash combat");
  AddTrainingSkills("hack combat");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("weapon smithing");
  AddTrainingSkills("leather working");
  AddTrainingSkills("metal working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("pierce combat");
  AddTrainingSkills("blunt combat");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("skinning");
  AddTrainingSkills("melee combat");
}
