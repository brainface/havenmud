#include <lib.h>
#include "../outpost.h"

inherit LIB_SENTIENT;

void DoSomething();
void DoCombatSomething();

static void create() {
  sentient::create();
  SetKeyName("rurik");
  SetId( ({ "archdeacon", "kylin invader", "rurik" }) );
  SetAdjectives( ({"kylin","reverend","monk","orthodox"}) );
  SetReligion("Kylin");
  SetShort("Archdeacon Rurik, the Reverend Monk of the Orthodox Kylin");
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetFriends( ({ "kylin invader", "inquisitor" }) );
  SetClass("priest");
  SetSkill("fire magic",1,2);
  SetSkill("combat rage",1,1);
  SetSkill("dodge",1,3);
  SetSkill("parry",1,3);
  SetSkill("accuracy",1,3);
  SetLevel(245);
  SetMorality(2500);
  SetGender("male");
  SetLong("Archdeacon Rurik is a very tall man with long black hair which has "
          "not been cut since he became a monk. The Patriarch of Orthodox Kylin "
          "has sent this highly respected reverend monk to help the Inquisitors "
          "contain the daemon horde from escaping the ruins of Durgoroth. Rurik "
          "is confindent in his skill in defeating the daemons and all that "
          "oppose his duty." );
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