#include <lib.h>
#include "../grymxoria.h"
inherit LIB_TRAINER;     

static void create()
{                   
  trainer::create();
  SetKeyName("vyper");
  SetShort("vyper, the Mistress of Aberach");
  SetId( ({ "mistress of aberach", "nosferatu", "vyper", }) );
  SetAdjectives( ({ "mistress", "aberach" }) );               
  SetLong(                                                    
    "Vyper is the Mistress of the Initiates of Aberach. "     
    "It is her job to see that the faithful recieve the "     
    "training they need."                                     
  );                                                          
                                                              
  SetRace("nosferatu");                                       
  SetGender("female");                                        
  SetClass("priest");                                         
  SetSkill("faith",1,1);                                      
  SetSkill("evokation",1,1);                                  
  SetSkill("necromancy",1,1);                                 
  SetSkill("blunt combat",1,1);                               
  SetLevel(80);                                               
                                                              
  SetTown("Grymxoria");                                       
  SetReligion("Aberach","Aberach");                           
  SetMorality(-2500);                                         
  SetSpellBook( ([                                            
    "aura of terror"   : 100,                                 
    "barrier of faith" : 100,                                 
    "pain touch" : 100,                                       
                ]) );                                         
  SetAction(20, ({
    "!sneer derisively",
    "!grumble nastily",                                            
  }) );                                                       
  SetCombatAction(40, ({
    "!cast aura of terror",
    "!cast pain touch",
          }) );
  SetInventory( ([
    G_OBJ + "nosf_mace" : "wield mace",
  ]) );
  SetFirstCommands( ({
    "cast barrier of faith",
    "cast barrier of faith",
    "cast barrier of faith",
    "cast barrier of faith",
    "cast barrier of faith",
  }) );
  AddTrainingSkill("slash combat");
  AddTrainingSkill("cooking");
  AddTrainingSkill("mining");
  AddTrainingSkill("bargaining");
  AddTrainingSkill("armour smithing");
  AddTrainingSkill("weapon smithing");
  AddTrainingSkill("metal working");
  AddTrainingSkill("wood working");
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast barrier of faith");
  }
}

