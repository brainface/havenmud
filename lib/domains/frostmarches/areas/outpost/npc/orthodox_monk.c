#include <lib.h>
#include "../outpost.h"

inherit LIB_SENTIENT;

void DoSomething();
void DoCombatSomething();

static void create() {
  sentient::create();
  SetKeyName("monk");
  SetId( ({ "kylin invader", "monk" }) );
  SetAdjectives( ({"kylin","monk"}) );
  SetReligion("Kylin");
  SetShort("a monk of Orthodox Kylin");
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetFriends( ({ "kylin invader", "ice bear" }) );
  SetClass("priest");
  SetSkill("fire magic",1,2);
  SetSkill("combat rage",1,1);
  SetSkill("dodge",1,3);
  SetSkill("parry",1,3);
  SetSkill("accuracy",1,3);
  SetLevel(180 + random(25));
  SetMorality(2000);
  SetGender("male");
  SetLong("This tall and stocky human is one of the elite clerics from the "
          "Principality of Gurov. Like all members of his order, his long "
          "dark hair is uncut and hangs down his back. This monk has been "
          "trained in skill of arms and his faith in his Lord is adamant "
          "which is the reason why he has been chosen for this mission "
          "in the ruins of Durgoroth." );
  SetInventory( ([
     OP_OBJ + "monk_armour" : "wear armour",
     OP_OBJ + "rhason"      : "wear cassock",
     OP_OBJ + "boots"       : "wear boots",
     OP_OBJ + "monk_sword"  : "wield sword",
     ]) );
  SetAction(1, (: DoSomething :) );
  SetCombatAction(60, (: DoCombatSomething :));
  SetSpellBook( ([
     "superior wall of force" : 100,
     "hand of judgement"      : 100,
     "divine power"           : 100,
     "clarity of thought"     : 100,
     "perfect recovery"       : 100,
     ]) );
   SetFirstCommands( ({ 
    "cast divine power",
    "cast superior wall of force",
    "cast superior wall of force",
    "cast superior wall of force",
    }) );
 }

void DoSomething() {
  object who = this_object();
  if(!(who->GetProperties("divine power"))) {
    eventForce("cast divine power");
    return;
  }
        
  if ((sizeof(GetMagicProtection()) < 3)) {
    eventForce("cast superior wall of force" );
    return;
  }
}

void DoCombatSomething() {
  object target = GetCurrentEnemy();
  object who = this_object();

  if(who->GetRecoveryTime() > 500) { 
    eventForce("cast clarity of thought");
    return;
  }
     
  if((sizeof(GetMagicProtection())) < 5) {
    eventForce("cast superior wall of force");
    return;
  }
  
  if((who->GetHealthPoints()) < ((who->GetMaxHealthPoints())/2)) {
    eventForce("cast perfect recovery");
    return;
  }
  
  switch(random(6)) {
    case 0:
      if(target->GetUndead(1))
        eventForce("cast perfect recovery on " + target->GetKeyName());
      break;
    default:
      eventForce("cast hand of judgement");
      break;
    }
}   