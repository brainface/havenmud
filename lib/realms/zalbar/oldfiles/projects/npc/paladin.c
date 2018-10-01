#include <lib.h>
#include "../outpost.h"

inherit LIB_SENTIENT;

void DoSomething();
void DoCombatSomething();

static void create() {
  sentient::create();
  SetKeyName("paladin");
  SetId( ({ "paladin", "kylin invader", "inquisitor" }) );
  SetAdjectives( ({"kylin", "paladin", "inquisitor"}) );
  SetReligion("Kylin");
  SetShort("a Paladin Inquisitor of Kylin");
  SetRace("elf");
  SetFriends( ({ "kylin invader", "inquisitor" }) );
  SetClass("cleric");
  SetClass("cavalier");
  SetStat("wisdom",40,2);
  SetSkill("fire magic",1,2);
  SetLevel(200);
  SetMorality(2000);
  SetGender("male");
  SetLong("This tall elf is a champion of justice and a keeper of balance. "
          "His strength and faith in the Lord of Balance has made it "
          "possible for him to strive for this elite position with the "
          "Kylin Inquisitors." );
  SetInventory( ([
     OP_OBJ + "plate_armour"  : "wear armour",
     OP_OBJ + "kylin_surcoat" : "wear surcoat",
     OP_OBJ + "plate_ boots"  : "wear boots",
     OP_OBJ + "mithril_sword" : "wield sword",
     OP_OBJ + "plate_helmet"  : "wear helmet",
     OP_OBJ + "gauntlet"      : 2,
     ]) );
  SetCurrency("imperials",random(1000) + 200);
  SetAction(1, (: DoSomething :) );
  SetCombatAction(60, (: DoCombatSomething :));
  SetSpellBook( ([
     "superior wall of force" : 100,
     "hand of judgement"      : 100,
     "divine power"           : 100,
     "clarity of thought"     : 100,
     "perfect recovery"       : 100,
     "desert banishment"      : 100,
     ]) );
   SetFirstCommands( ({ 
    "wear 1st gauntlet on left hand",
    "wear 1st gauntlet on right hand",
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