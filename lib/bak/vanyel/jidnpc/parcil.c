//
// Parcil, Diviner Trainer
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../jidoor.h"

inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetKeyName("parcil");
   SetShort("Parcil Privara");
   SetId( ({ "parcil", "privara", "parcil privara" }) );
   SetClass("evoker");
   SetLevel(20);
   SetMorality(80);
   AddTrainingSkills("blunt defense");
   AddTrainingSkills("divination");
   AddTrainingSkills("blunt attack");
   SetGender("male");
   SetRace("sprite");
   SetLong("Parcil Privara is of the legendary Privara "
           "family. His skillfulness is world renowned.");
   SetReligion("Magildan","Magildan");
   SetInventory( ([ 
      JID_OBJ + "/clothing/diviner_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
}
