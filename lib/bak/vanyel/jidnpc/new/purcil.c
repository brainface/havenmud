//
// Purcil, Necromancer Trainer
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../jidoor.h"

inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetKeyName("purcil");
   SetShort("Purcil Privara");
   SetId( ({ "purcil", "privara", "purcil privara","teacher" }) );
   SetClass("necromancer");
   SetMorality(-50);
   SetLevel(20);
   AddTrainingSkills("pole attack");
   AddTrainingSkills("conjuring");
   AddTrainingSkills("necromancy");
   SetGender("male");
   SetRace("sprite");
   SetLong("This is Purcil, local teacher of "
           "various skills to all necromancers.");
   SetReligion("Magildan","Magildan");
   SetInventory( ([ 
      JID_OBJ + "/clothing/necro_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
}
