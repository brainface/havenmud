#include <lib.h>
#include "../outpost.h"

inherit LIB_SENTIENT;

void DoSomething();
void DoCombatSomething();

static void create() {
  sentient::create();
  SetKeyName("dwarven templar");
  SetId( ({ "worker", "templar","dwarf" }) );
  SetAdjectives( ({" dwarven"}) );
  SetReligion("Kylin");
  SetShort("a dwarven Templar");
  SetRace("dwarf");
  SetFriends( ({ "kylin invader", "templar" }) );
  SetClass("priest");
  SetSkill("fire magic",1,2);
  SetLevel(180);
  SetMorality(1500);
  SetGender("male");
  SetLong("Assigned to help the Kylin Inquisitors, this dwarven templar is "
          "building the fortifications and towers surrounding the ruins "
          "of Durgoroth. This faithful cleric of Kylin is ready and able to "
          "defend the outpost if and when the daemons decide to attack." );
  SetInventory( ([
     OP_OBJ + "boots_small" : "wear boots",
     OP_OBJ + "robe_small"  : "wear robe",
     OP_OBJ + "mallet"      : "wield mallet",
     ]) );
  SetCurrency("nuggets",random(1000) + 50);
  SetAction(1, (: DoSomething :) );
  SetCombatAction(60, (: DoCombatSomething :));
  SetSpellBook( ([
     "superior wall of force" : 100,
     "hand of judgement"      : 100,
     "divine power"           : 100,
     "clarity of thought"     : 100,
     "perfect recovery"       : 100,
     ]) );
 }

void DoSomething() {
  object who = this_object();
  if(!(who->GetProperties("divine power"))) {
    eventForce("cast divine power");
    return;
  }
        
  if ((sizeof(GetMagicProtection()) < 2)) {
    eventForce("cast superior wall of force" );
    return;
  }
  switch(random(8)) {
    case 0:
      eventForce("say we need to finish building the towers.");
      break;
    case 1:
      eventForce("say These towers will not build themselves!");
    default:
      eventForce("say we have to be prepared.");
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
  
  switch(random(6)) {
    case 0:
      if(target->GetUndead(1))
        eventForce("cast perfect recovery on " + target->GetKeyName());
      break;
    default:
      eventForce("cast hand of judgement on " + target->GetKeyName());
      break;
    }
}   