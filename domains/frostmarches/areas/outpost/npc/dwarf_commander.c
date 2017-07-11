#include <lib.h>
#include <damage_types.h>
#include "../outpost.h"

inherit LIB_SENTIENT;

void DoSomething();
void DoCombatSomething();

static void create() {
  sentient::create();
  SetKeyName("euan");
  SetId( ({ "commander", "kylin invader", "euan","euan tunnelbreaker" }) );
  SetAdjectives( ({"kylin", "lord", "inquisitor", "commander", "knight",
                   "templar", "knight-templar", "tunnelbreaker"}) );
  SetReligion("Kylin");
  SetShort("Lord Euan Tunnelbreaker, Commander of Knights-Templar");
  SetRace("dwarf");
  SetFriends( ({ "kylin invader", "inquisitor" }) );
  SetClass("priest");
  SetClass("cavalier");
  SetStat("wisdom",40,1);
  SetSkill("fire magic",1,2);
  SetLevel(240);
  SetMorality(2500);
  SetGender("male");
  SetLong("Standing at four feet five inches this stocky dwarf has a deep "
          "red beard which is braided in four braids hanging down below "
          "his waist. Lord Euan has been placed in charge of the dwarven "
          "knight-templar which are helping the Inquisitors hold the daemons "
          "at bay in the ruins of Durgoroth." );
  SetInventory( ([
     OP_OBJ + "mithril_plate_small" : "wear armour",
     OP_OBJ + "kylin_surcoat_small" : "wear surcoat",
     OP_OBJ + "mithril_boots"       : "wear boots",
     OP_OBJ + "warhammer"           : 2,
     OP_OBJ + "mithril_helmet"      : "wear helmet",
     OP_OBJ + "mithril_gauntlet"    : 2,
     ]) );
  SetCurrency("nuggets",random(2100) + 50);
  SetAction(1, (: DoSomething :) );
  SetCombatAction(50, (: DoCombatSomething :));
  SetSpellBook( ([
     "superior wall of force" : 100,
     "hand of judgement"      : 100,
     "divine power"           : 100,
     "clarity of thought"     : 100,
     "perfect recovery"       : 100,
     ]) );
   SetFirstCommands( ({ 
    "wield hammers",
    "wear 1st gauntlet on left hand",
    "wear 1st gauntlet on right hand",
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
    eventForce("cast superior wall of force");
    return;
  }
  switch(random(4)){
    case 0:
      eventForce("say my workers are done with the first tower.");
      break;
    default:
      eventForce("say my paladins are ready.");
      break;
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
  
  switch(random(5)) {
    case 0:
      if(target->GetUndead(1))
        eventForce("cast perfect recovery on " + target->GetKeyName());
      break;
    case 1:
      eventForce("say you are foolish to attack us.");
      break;
    default:
      eventForce("growl");
      eventForce("cast hand of judgement");
      break;
    }
}   

