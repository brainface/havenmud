#include <lib.h>
#include "../grymxoria.h"
inherit LIB_TRAINER;     

static void create()
{                   
  trainer::create();
  SetKeyName("karn");
  SetShort("Karn Resnar, a dark mage");
  SetId( ({ "karn resnar", "nosferatu", "resnar", "karn", 
    "mage", }) );                                         
  SetLong(                                                
    "Karn Resnar is a master of all magic related "       
    "skills that pertain to necromancy and the dark arts. "
    "Karn may be willing to share this knowledge "         
    "with young necromancers."                             
  );                                                       
                                                           
  SetRace("nosferatu");                                    
  SetGender("male");                                       
  SetClass("necromancer");                                 
  SetSkill("conjuring",1,1);                               
  SetSkill("evokation",1,2);
  SetSkill("necromancy",1,1);
  SetLevel(35);

  SetTown("Grymxoria");
  SetReligion("Aberach");
  SetMorality(-2000);
  SetFriends( ({ "agnod", "guard" }) );

  AddTrainingSkill("pole combat");
  AddTrainingSkill("leather working");
  AddTrainingSkill("natural working");
  AddTrainingSkill("mithral working");
  AddTrainingSkill("textile working");
  SetInventory( ([
    G_OBJ + "nosf_staff" : "wield staff",
    G_OBJ + "nosf_armor" : "wear armor",
                ]) );
  SetSpellBook( ([
    "necromantic shield" : 100,
    "fireball"           : 100,
    "drain soul"         : 100,
    "wound"              : 100,
    "acid rain"          : 100,
  ]) );
  SetCombatAction(10, ({
    "!cast fireball",
    "!cast drain soul",
    "!cast necromantic shield",
    "!cast acid rain",
    "!cast wound",
    "!speak You will die.",
    "!speak You Dare !",
  }) );
}

