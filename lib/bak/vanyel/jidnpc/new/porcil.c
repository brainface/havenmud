//
// Porcil, Enchanter Trainer
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../jidoor.h"

inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetKeyName("porcil");
   SetShort("Porcil Privara");
   SetId( ({ "porcil", "privara", "porcil privara" }) );
   SetClass("enchanter");
   SetLevel(20);
   SetMorality(80);
   AddTrainingSkills("conjuring");
  AddTrainingSkills("healing");
   AddTrainingSkills("enchantment");
   SetGender("female");
   SetRace("sprite");
   SetLong("This is Porcil, local teacher of "
           "various skills to all enchanters.");
   SetInventory( ([ 
      JID_OBJ + "/clothing/enchanter_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );

}
