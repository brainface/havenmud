#include <lib.h>
#include "../battlegrounds.h"
#include <damage_types.h>
#include <size.h>
#include <armour_types.h>
inherit LIB_SENTIENT;

static void create() {
  string pronoun = "He";
  string objective = "him";
  string possessive = "his";
  sentient::create();
  if(random(2)) { SetGender("male"); }
   else  {
   SetGender("female");
   pronoun = "she"; 
   objective = "her";
   possessive = "her";
  }

  SetKeyName("Warrior");
  SetId( ({ "warrior" }) );          
  SetAdjectives( ({ "Warrior", "Cloaked" }) );
  SetShort("A Cloaked Warrior");      
  SetLong(
    "The look on the warriors face appears to be very confident. "
    ""+pronoun+" is covered with glimmering cloak that is almost "
    "blinding to the eye. What can be seen of "+possessive+" face "
    "appears to be chiseled from stone. From the end of both "
    "sleeves appears to be the edge of very sharp and shiny weapons. "
  );                                                             
   SetAction(5, ({
    "!grin evil",
    "!say You're my challenger?? HAHAHA!",
    "!emote shakes "+possessive+" head in disbelief.",
    }) );
  SetRace("human");
  SetReligion("Aberach");
  SetMorality(-2500);
  SetResistance(ACID, "immune");
  SetResistance(HEAT, "low");
  SetResistance(WATER, "immune");
  SetResistance(POISON, "immune");
  SetResistance(COLD, "immune");
  SetResistance(BLUNT, "medium");
  SetResistance(SLASH, "medium");
  SetResistance(PIERCE, "medium");
  SetSize(SIZE_LARGE);
SetInventory( ([
    BAT_OBJ "/frost_blade" : "wield blade",
    BAT_OBJ "/full_chainmail" : "wear armour",
    BAT_OBJ "/mithril_glove" : 2,
    BAT_OBJ "/mithril_boots" : "wear boots",
    BAT_OBJ "/mithril_helmet" : "wear helmet",
    ]) );

  SetClass("fanatic");
  SetStat("wisdom", 125);
  SetStat("intelligence", 120);
  SetStat("charisma", 120);
  SetSkill("cold magic", 550, 1);
  SetSkill("melee combat", 200, 1);
  SetSkill("knife combat", 550, 1);
  SetSkill("accuracy", 550, 1);
  SetSkill("evokation", 550, 1);
  SetSkill("necromancy", 550, 1);
  SetSkill("faith", 550, 1);
  SetSkill("dodge", 300, 2);
  SetSkill("combat rage", 400, 2);
  SetSkill("chain armour", 400, 2);
  SetSkill("dodge", 300, 2);
  SetSkill("accuracy", 350, 2);
  SetSkill("parry", 300, 2);
  SetSkill("disarm", 1, 2);
/*SetCombatAction("dirty tricks", 300);
*/ 
  SetLevel(350);
  SetDie("The warrior falls face down with blood flowing from his mouth.");
  SetCurrency("imperials", 15000);
  SetSpellBook( ([
    "divine intervention" : 100,
    "ancient might" : 100,
    "banefire" : 100,
    "black circle" : 100,
  ]) );  
  SetFirstCommands( ({
    "wear first glove on right hand",
    "wear first glove on left hand",
    "cast ancient might on me",
    "cast divine intervention",
    "cast divine intervention",
    "cast divine intervention",
  }) );
  SetCombatAction(5, ({
    "!cast black circle",
    "!cast banefire",
    "!disarm"
    "!cast banefire",
    "!cast banefire",
  }) );
}


void init() {
  sentient::init();
}



/*void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 3) {
    eventForce("cast divine intervention");
  }
}
*/

varargs int eventDie(object killer) {
  if (killer) killer->AddTitle("the Ground Breaker");
  return::eventDie(killer); 
  }

