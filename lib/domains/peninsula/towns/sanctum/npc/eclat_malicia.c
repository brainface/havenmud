
#include <lib.h>
inherit LIB_TRAINER;
#include "../rome.h"

static void create() {
   ::create();
   SetKeyName("Malicia");
   SetShort("Malicia, Spirtual Teacher of Eclat");
   SetId( ({ "malicia","teacher","priest" }) );
   SetAdjectives( ({ "spiritual", "teacher", "of", "eclat" }) );
   SetLong("Malicia smiles happily, having retained the joy of her "
           "tribe while becoming Eclat by faith.  She loves dealing "
           "with nature and the surrounding world, so has worked "
           "hard at improving her skills.  It appears as if she "
           "has succeeded in many ways.");
   SetRace("human");
   SetGender("female");
   RemoveLanguage("Enlan");
   SetLanguage("Imperial", 100, 1);
   SetReligion("Eclat","Eclat");
   SetLevel(48);
   SetSkill("natural magic",1,1),
   SetSkill("evokation",1,1),
   SetSkill("enchantment",1,1),
   SetSkill("dodge",1,2),
   SetSkill("parry",1,2),
   SetSkill("melee combat",1,1),
   SetTrainingSkills( ({
    	}) );
   SetSpellBook( ([
   		"soothe" : 100,
   		"vine wall" : 100,
   		"forest banishment" : 100,
   	  ]) );
   SetCombatAction(40, ({
   		"!cast soothe",
   		"!cast vine wall",
   		"!cast forest banishment",			
    	}) );
   SetTown("Sanctum");
   SetMorality(1000);
   SetLimit(1);
}
