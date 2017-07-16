/*  Red Bull
 *  Ela 8/3/98
 *  Edited by Gaby so
 *  poor little Matus
 *  wasnt killed by level 34
 *  dark elf cleric with
 *  bof
*/

#include <lib.h>
#include <damage_types.h>
#include "../wood.h"
inherit LIB_FEAR;
inherit LIB_NPC;

void eventStomp();

static void create() {
  npc::create();
  SetKeyName("Matus");
  SetShort("Matus, the Red Bull");
  SetId( ({
       "bull", "matus", "beast", "demon",
        }) );
  SetAdjectives( ({
        "red", "Red", "legendary", "huge", 
        }) );
  SetRace("cow","demon");
  SetMorality(-2500);
  SetClass("animal");
  SetGender("male");
  SetAction(5, ({
        "The Red Bull casts a black look at you, death in his eyes.",
        }) );
  SetLong("The Red Bull is a huge beast who strikes terror "
         "in the hearts of even the most courageous. He "
         "is rumored to be the malicious creation of the Fae, " 
         "meant to keep their kingdom free from invaders. "
         "A gleam "
         "of deadly intent shines madly in his glowing red "
         "eyes. His sharp deadly horns bare the stains of "
         "old blood.");
  SetEncounter(100);
  
  // This stuff added to reflect demonic nature of this beast.
  
  SetStat("agility",87,2);
  SetStat("charisma",40,2);
  SetStat("coordination",76,2);
  SetStat("durability",135,1);
  SetStat("intelligence",120,1);
  SetStat("luck",47,2);
  SetStat("speed",91,2);
  SetStat("strength",135,1);
  SetStat("wisdom",51,2);
  
  SetResistance(BLUNT,"high");
  SetResistance(SLASH,"med");
  SetResistance(PIERCE,"med");
  SetResistance(WATER,"low");
  SetResistance(SHOCK,"high");
  SetResistance(COLD,"high");
  SetResistance(HEAT,"high");
  SetResistance(GAS,"immune");
  SetResistance(ACID,"low");
  SetResistance(MAGIC,"high");
  SetResistance(HUNGER,"weakness");
  SetResistance(DISEASE,"immune");
  SetResistance(POISON,"high");
  
  // End of demonic additions

  SetSkill("evokation",240,1);
  SetSkill("necromancy",240,1);
  SetSkill("enchantment",240,1);
  SetSkill("conjuring",240,1);
  SetSpellBook( ([
      "flamestrike"       : 100,
      "poison explosion"  : 100,
      "fireball"          : 100,
      "temperature shield": 100,
      "acid blast"        : 100,
      ]) );
  SetCombatAction(20, ({
      "!cast flamestrike",
      "!cast poison explosion",
      "!cast fireball",
      "!cast temperature shield",
      "!cast acid blast",
       }) );
  SetFearType("evil radiating from the demonic scourge of the Fae");
  SetResistLevel(70);
  SetFearLength(25);
  SetInventory( ([
      WOOD_OBJ + "diadem" : 1,
      WOOD_OBJ + "armlet" : 2,
      ]) );
  SetLevel(200);
  SetCurrency("imperials", 10000);
}

void init() {
npc::init();
fear::init();
}

/*varargs int eventDie(object killer) {
  if (killer) killer->AddTitle("the Butcher of Kailie");
  return::eventDie(killer); 
  }
 */
  

void eventStomp() {
  object target = GetCurrentEnemy();
  int num = random(8);
  if (num < 6){
	  if(present(target)) {
		send_messages( ({"stomp","toward"}),
		  "%^YELLOW%^ $agent_name $agent_verb $agent_possessive hoof against the ground "
		  "creating a shockwave $agent_verb $target_name knocking $target_objective down!%^RESET%^",
		  this_object(), target, environment(target) );
		target->eventCollapse(1);
		target->SetParalyzed(5);
		target->eventReceiveDamage(this_object(),BLUNT, GetDamage(500, "melee combat", target->GetDefense()), 0, target->GetTorso());
		}
  }
  else {
	  if(present(target)){
		send_messages( ({"ram","toward"}),
		  "%^CYAN%^ $agent_name $agent_verb $agent_possessive head against $target_name "
		  "piercing $target_objective with $agent_possessive horns!%^RESET%^",
		this_object(), target, environment(target) );
		target->eventReceiveDamage(this_object(), PIERCE, GetDamage(500, "melee combat", target->GetDefense()), 0, target->GetTorso());
		}
  }
  return;
}
