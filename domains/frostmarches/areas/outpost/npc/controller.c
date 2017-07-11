#include <lib.h>
#include <domains.h>
#include "../outpost.h"

inherit LIB_CONTROLLER;

void DoSomething();
void DoCombatSomething();

static void create() {
  ::create();
  SetKeyName("gideon");
  SetShort("Inquisitor Gideon, Vanguard Commander of the Assault"); 
  SetId( ({ "inquisitor", "gideon" }) );
  SetAdjectives( ({ "assault", "vanguard", "commander", }) );
  SetRace("elf");
  SetClass("priest");
  SetSkill("fire magic",1,2);
  SetLevel(230);
  SetGender("male");
  SetTown("Durgoroth");
  SetReligion("Kylin");
  SetLong(
    "Gideon is an Inquisitor of Kylin. Grand Master Banewulf has assigned him "
    "to coordinate the attacks on the daemons remaining in the ruins of "
    "Durgoroth. If you are interested in helping the Inquisitors, <request "
    "quest from gideon> or <ask gideon for quest>." );
  SetMorality(2000);
  SetInventory( ([
    OP_OBJ + "chain_armour"  : "wear armour",
    OP_OBJ + "kylin_surcoat" : "wear surcoat",
    OP_OBJ + "boots"         : "wear boots",
    OP_OBJ + "mace"          : "wield mace",
    ]) );
  SetAction(1, (: DoSomething :) );
  SetCombatAction(60, (: DoCombatSomething :));
  SetSpellBook( ([
     "superior wall of force" : 100,
     "hand of judgement"      : 100,
     "divine power"           : 100,
     "clarity of thought"     : 100,
     "perfect recovery"       : 100,
     "bless"                  : 100,
     ]) );
   SetFirstCommands( ({ 
    "cast divine power",
    "cast superior wall of force",
    "cast superior wall of force",
    "cast superior wall of force",
    }) );   
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );
}

void DoSomething() {
  object who = this_object();
  switch(10) {
    case 0:
      if(!(who->GetProperties("divine power"))) 
        eventForce("cast divine power");
      break;
    case 1:
      if ((sizeof(GetMagicProtection()) < 3))
        eventForce("cast superior wall of force" );
      break;
    case 2:
      eventForce("say the time is coming near to strike.");
      break;
    case 3:
      eventForce("yell We must prepare for the assault.");
      break;
    case 4:
      eventForce("yell May our Lord bless us!");
      break;
    default:
      eventForce("say Have you come here to join the assault?");
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
    default:
      eventForce("cast hand of judgement");
      break;
    }
}   
