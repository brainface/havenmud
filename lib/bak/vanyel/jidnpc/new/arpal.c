//
// Arpal, Evoker Trainer
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../jidoor.h"

inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetKeyName("arpal");
   SetShort("Arpal Privara");
   SetId( ({ "arpal", "privara", "arpal privara" }) );
   SetClass("evoker");
   SetLevel(20);
   SetMorality(80);
   AddTrainingSkills("pole defense");
   AddTrainingSkills("evokation");
   AddTrainingSkills("conjuring");
   SetGender("male");
   SetRace("sprite");
   SetLong("Arpal, of the Privara family, is one of the "
           "smartest men in the world. His head bulges with "
           "skill and power.");
   SetInventory( ([ 
      JID_OBJ + "/clothing/evoker_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
}
