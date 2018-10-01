#include <lib.h>
#include "../outpost.h"

inherit LIB_SENTIENT;

void DoSomething();
void DoCombatSomething();

static void create() {
  sentient::create();
  SetKeyName("kylin inquisitor");
  SetId( ({ "templar", "kylin invader", "inquisitor" }) );
  SetAdjectives( ({"kylin"}) );
  SetReligion("Kylin");
  SetShort("an Inquisitor of Kylin");
  SetRace("elf");
  SetFriends( ({ "kylin templar", "kylin inquisitor" }) );
  SetClass("cleric");
  SetStat("wisdom",40,2);
  SetSkill("fire magic",1,2);
  SetLevel(180 + random(30));
  SetMorality(2000);
  SetGender(random(2)? "male" : "female");
  SetLong("This Kylin cleric is one of the most perfect of elven specimens. " 
          "Trained and breed to be one of the elite Kylin clerics, " 
          + nominative(this_object()) + " is an Inquisitor of Kylin.");
  SetInventory( ([
    OP_OBJ + "c_armour"      : "wear armour",
    OP_OBJ + "kylin_surcoat" : "wear surcoat",
    OP_OBJ + "boots"         : "wear boots",
    OP_OBJ + "mace"          : "wield mace", 
    ]) );
  SetCurrency("imperials",random(1500) + 500);
  SetAction(1, (: DoSomething :) );
  SetCombatAction(60, (: DoCombatSomething :));
  SetSpellBook( ([
     "superior wall of force" : 100,
     "hand of judgement"      : 100,
     "divine power"           : 100,
     "clarity of thought"     : 100,
     "perfect recovery"       : 100,
     "summon lesser effigy"   : 100,
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
     
  if((sizeof(GetMagicProtection())) < 3) {
    eventForce("cast superior wall of force");
    return;
  }
  
  if((who->GetHealthPoints()) < ((who->GetMaxHealthPoints())/2)) {
    eventForce("cast perfect recovery");
    return;
  }
  
  switch(random(4)) {
    case 0:
      if(target->GetUndead(1))
        eventForce("cast perfect recovery on " + target->GetKeyName());
      break;
    case 1:
      eventForce("cast summon lesser effigy");
      break;
    default:
      eventForce("cast hand of judgement");
      break;
    }
}   