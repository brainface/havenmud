/*  This worker is a modified version
    of the lesser water elemental from
    the lagoon.  ninja vs fighter acid vs water
    and no fear.  Torak Dec 2011/Jan 2012 */

#include <lib.h>
#include <size.h>
#include "../minaret.h"
#include <damage_types.h>
inherit LIB_SENTIENT;


void eventSpecial();

static void create() {
  string pronoun = "He";
  string objective = "him";
  string possessive = "his";
  sentient::create();
  if(random(2)) { SetGender("male"); }
   else  {
   SetGender("female");
   pronoun = "She"; 
   objective = "her";
   possessive = "her";
  }
  SetKeyName("worker");
  SetProperty("minaretnoleave", 1);
  SetId( ({ "worker", "thri-kreen" }) );          
  SetAdjectives( ({ "thri-kreen" }) );
  SetShort("a thri-kreen worker");      
  SetLong(
    "The thri-kreen worker is an insectoid creature with an "
    "extra set of arms growing from "+possessive+" torso.  "
    +pronoun+" has been bred to create different kinds of resin "
    "from "+possessive+" mouth in order to build and maintain structures.  The "
    "outer layer of "+possessive+" skin is covered in an exosekelton "
    "of hard armour."
  );                                                             
  SetAction(15, ({
    "!emote checks the minaret for weaknesses.",
    "!emote chews on something with its mandibles.",
    "!emote spits out a strange resin substance into a small "
    "crack, sealing the imperfection from erosion.",
    	}) );
  SetFirstCommands( ({
    "wield all",
  }) );
  SetRace("thri-kreen");
  SetReligion("Magildan");
  SetResistance(ACID, "immune");
  SetSize(SIZE_LARGE);
  SetInventory( ([
    MIN_OBJ "/claws" : 4,
  MIN_OBJ "/yellow_exo" : "wear exoskeleton on torso and "
        "upper right arm and right leg and upper left arm and left leg",
    ]) );
  SetClass("ranger");
  SetSkill("natural armour", 1, 1);
  SetLevel(200);
  SetResistance(COLD, "weakness");
  SetSkill("natural magic", 1, 1);
  SetCombatAction(5, (: eventSpecial :) );
  SetMeleeAttackString("fierce clawed hand");
  SetMeleeDamageType(PIERCE);
}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();

  if (!who || !target) return;
  send_messages("spit",
      "$agent_name%^GREEN%^ $agent_verb%^RESET%^ upon $target_name with currosive effect!",
      who, target, environment() );
  target->eventReceiveDamage(who, ACID, GetDamage(GetSkillLevel("melee combat"),
    "melee combat", target->GetDefense()) * 3, 0,  target->GetRandomLimb() );

  if(sizeof(all_inventory(target))) {
    object thing = (all_inventory(target)[random(sizeof(all_inventory(target)))]);
      if(thing->GetMealType()) {
         send_messages("corrode",
           "$agent_name%^GREEN%^ $agent_verb%^RESET%^ away $target_possessive_noun "
            + remove_article(thing->GetShort())
            + " with $agent_possessive volitile saliva!",
            who, target, environment(who));
            thing->eventDestruct();
       } else {
         send_messages("erode",
           "$agent_name%^GREEN%^ $agent_verb%^RESET%^ $target_possessive_noun "
            + remove_article(thing->GetShort())
            + " with $agent_possessive volitile saliva!",
            who, target, environment(who));
         thing->eventDeteriorate(ACID);
       }
    }
  return;
}

void init() {
  sentient::init();
}
