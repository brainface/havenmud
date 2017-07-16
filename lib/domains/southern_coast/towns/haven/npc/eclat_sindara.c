#include <lib.h>
inherit LIB_TRAINER;
#include "../haven.h"

static void create() {
   ::create();
   SetKeyName("sindara");
   SetShort("Sindara of Haven, Spirtual Teacher of Eclat");
   SetId( ({ "sindara","teacher","priest" }) );
   SetAdjectives( ({ "spiritual", "teacher", "of", "eclat" }) );
   SetLong("Sindara smiles happily, having retained the joy of her "
           "youth while becoming Eclat by faith.  She loves dealing "
           "with nature and the surrounding world, so has worked "
           "hard at improving her skills.  It appears as if she "
           "has succeeded in many ways.");
   SetRace("elf");
   SetGender("female");
   SetReligion("Eclat","Eclat");
   SetTown("Haven");
   SetSkill("natural magic",1,1);
   SetSkill("evokation",1,1);
   SetSkill("enchantment",1,1);
   SetLevel(48);
   SetTrainingSkills( ({
"farming",
"pole combat",
    }) );
   SetSpellBook( ([
  	"soothe"		   : 100,
  	"natural veil" : 100,
  	"terra"        : 100,
  	"color spray"  : 100,  
  	"vine wall"    : 100,
    ]) );
  SetCombatAction(50, ({
  	"!cast soothe",
  	"!cast natural veil",
  	"!cast terra",
  	"!cast color spray",
  	"!cast vine wall",
    }) );
   SetMorality(1500);
   SetLimit(1);
}
