#include <lib.h>
#include "../path.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("elgad");
  SetId( ({ "elgad", "trainer", "dwarf"}) );
  SetRace("dwarf");
  SetGender("female");
  SetClass("priest");

  SetSkill("faith", 1, 1);
  SetSkill("enchantment", 1, 1);
  SetSkill("melee combat", 1, 1);
  AddTrainingSkills("cooking");
 
  SetTown("Glimmerdin");
  SetReligion("Kylin","Kylin");
  SetLevel(45); 
  SetMorality(1100);
  SetShort("Elgad, a trainer of magical skills");
  SetLong("Elgad is a cleric of some reknown.  She is also a "
    "teacher in the ways of faith. Perhaps you could ask her to "
    "teach you something?");
  SetAdjectives( ({ }) );
  SetFriends( ({"dwarf"}) );
  SetSpellBook( ([
    "wall of force"     : 100,
    "kylin touch"       : 100,
    "desert banishment" : 100,
  ]) );
  SetAction(5, ({
    "!speak You could <ask elgad to train>",
    "!cast wall of force",
    "!cast wall of force",
  }) );
  SetCombatAction(60, ({
    "!cast wall of force",
    "!cast kylin touch",
    "!cast desert banishment",
  }) );
  AddTrainingSkills("healing");
}
