#include <lib.h>
#include "../yozrath.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("ahkmed");
  SetShort("Ahkmed the Trainer");
  SetId( ({ "trainer", "ahkmed" }) );
  SetAdjectives( ({ }) );
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetTrainingSkills( ({
    "stealth", 
    "swimming",
    "skinning",
    "weapon smithing", 
    "armour smithing",
    "textile working", 
    "metal working",
    "leather working",
    "mithril working",
    "melee combat",
    "slash combat",
    "pierce combat",
    "blunt combat", 
    "pole combat",
    "hack combat", 
    "projectile combat",
    "knife combat",
    "bargaining",
    "multi-weapon",
        }) );
  SetLong(
    "Ahkmed the Trainer serves as the teacher for skills that are not "
    "generally taught to new members of the professions of Yozrath. His "
    "skills are unmatched."
    );
  SetTown("Yozrath");
  SetClass("janissary");
  SetLevel(30);
  SetLimit(1);
  SetMorality(250);
  SetGender("male");
  SetInventory( ([
    YOZRATH_OBJ "thobe" : "wear thobe",
    ]) );
}

