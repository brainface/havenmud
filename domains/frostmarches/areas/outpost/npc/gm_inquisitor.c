#include <lib.h>
#include <damage_types.h>
#include "../outpost.h"

inherit LIB_SENTIENT;

void DoSomething();
void DoCombatSomething();

static void create() {
  sentient::create();
  SetKeyName("atariel");
  SetId( ({ "grand master", "kylin invader", "inquisitor", "atariel",
            "atariel banewulf" }) );
  SetAdjectives( ({"kylin", "grand", "inquisitor", "master", "banewulf"}) );
  SetReligion("Kylin");
  SetShort("Grand Master Atariel Banewulf, Inquisitor of Kylin");
  SetRace("elf");
  SetFriends( ({ "kylin invader", "inquisitor" }) );
  SetClass("priest");
  SetClass("cavalier");
  SetStat("wisdom",40,1);
  SetSkill("fire magic",1,2);
  SetLevel(250);
  SetMorality(3000);
  SetGender("female");
  SetLong("Grand Master Atariel Banewulf stands six feet tall with long black "
          "hair which hangs to the middle of her back. Her beauty is reknown "
          "around Kailie just as much as her faith in her Lord, Duuktsaryth. "
          "She has turned her back on her family to strive for this high position "
          "within the Kylin church, and she is the youngest elf to attain the "
          "position of Grand Master Inquisitor." );
  SetInventory( ([
     OP_OBJ + "mithril_plate" : "wear armour",
     OP_OBJ + "flame_rapier"  : "wield rapier",
     OP_OBJ + "mace"          : "wield mace",
     OP_OBJ + "kylin_surcoat" : "wear surcoat",
     OP_OBJ + "boots"         : "wear boots",
     ]) );
  SetCurrency("imperials",random(2000) + 200);
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
  eventForce("say are we prepared to attack the daemon horde.");
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
    case 2:
      eventForce("yell Lord of Balance, I will smite your enemies!");
      break;
    default:
      eventForce("cast hand of judgement");
      break;
    }
}   
