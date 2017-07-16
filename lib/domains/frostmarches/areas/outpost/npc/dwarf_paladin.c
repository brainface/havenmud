#include <lib.h>
#include "../outpost.h"

inherit LIB_SENTIENT;

void DoSomething();
void DoCombatSomething();

static void create() {
  sentient::create();
  SetKeyName("knight templar");
  SetId( ({ "knight", "kylin invader", "knight-templar", "templar" }) );
  SetAdjectives( ({"kylin", "templar", "dwarven", "knight"}) );
  SetReligion("Kylin");
  SetShort("a knight-templar of Kylin");
  SetRace("dwarf");
  SetFriends( ({ "kylin invader", "templar" }) );
  SetClass("priest");
  SetClass("cavalier");
  SetSkill("fire magic",1,2);
  SetLevel(210);
  SetMorality(2500);
  SetGender("male");
  SetLong("This dwarf is one of the famous knights-templar of Kylin. He has "
          "dedicated his life, body and soul to keep the balance for his "
          "Lord. As a faithful of Kylin, this dwarf has no higher duty than "
          "to protect this outpost from the daemons." );
  SetInventory( ([
     OP_OBJ + "plate_armour_small"  : "wear armour",
     OP_OBJ + "kylin_surcoat_small" : "wear surcoat",
     OP_OBJ + "plate_boots_small"   : "wear boots",
     OP_OBJ + "warhammer_twohanded" : "wield hammer",
     OP_OBJ + "plate_helmet_small"  : "wear helmet",
     OP_OBJ + "gauntlet_small"      : 2,
         ]) );
  SetCurrency("nuggets",random(1000) + 500);
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
     
  if((sizeof(GetMagicProtection())) < 3) {
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
    case 2:
      eventForce("cast desert banishment on " + target->GetKeyName());
      break;
    default:
      eventForce("cast hand of judgement on " + target->GetKeyName());
      break;
    }
}   