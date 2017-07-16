#include <lib.h>
#include "../outpost.h"

inherit LIB_SENTIENT;

void DoSomething();
void DoCombatSomething();

static void create() {
  sentient::create();
  SetKeyName("jalal");
  SetId( ({ "jalal", "kylin invader", "imam" }) );
  SetAdjectives( ({"kylin","imam","tahmid","ayman","hajji"}) );
  SetReligion("Kylin");
  SetShort("Hajji Jalal Tahmid Ayman the Imam of Desert Kylin");
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetFriends( ({ "kylin invader", "honor guard" }) );
  SetClass("imam");
  SetSkill("fire magic",1,2);
  SetLevel(230);
  SetMorality(2500);
  SetGender("male");
  SetLong(" " );
  SetInventory( ([
      OP_OBJ + "robe"                : "wear robe",
      OP_OBJ + "warhammer_twohanded" : "wield hammer",
      OP_OBJ + "boots"               : "wear boots",
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
        
  if ((sizeof(GetMagicProtection()) < 5)) {
    eventForce("cast superior wall of force" );
    return;
  }
  eventForce("say My monks are in place and prepared to attack!");
  
}

void DoCombatSomething() {
  object target = GetCurrentEnemy();
  object who = this_object();

  if(who->GetRecoveryTime() > 500) { 
    eventForce("cast clarity of thought");
    eventForce("say the Lord of Balance will calm my mind!");
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