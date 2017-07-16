#include <lib.h>
#include <daemons.h>
#include <damage_types.h>
inherit LIB_NPC;
inherit LIB_FEAR;
varargs void eventRip(object who); 

static void create() {
  npc::create();
  SetKeyName("hedge");
  SetResistance(ALL_PHYSICAL, "immune");
  SetDie("The hedge sinks back into its surroundings.");
  SetNoCorpse(1);
  SetRace("elemental");
  SetInvis(1);
  SetEncounter(100);  
  SetResistLevel(random(400));
  SetFearLength(10);
  SetFearType("forest rage");
  SetClass("valkyr");
  SetLevel(random(300));
  SetCombatAction(5, (: eventRip :) );
  SetShort("a raging forest elemental");
  SetAdjectives( ({ "raging" }) );
  SetId( ({ "hedge", "elemental" }) );
  SetLong("This hedge has come to life, and is out for blood. It is a magical "
    "creature, with strong branches quite capable of ripping a man in two.");  
  }
  
varargs void eventRip(object who)
{
  if(!who) who = GetCurrentEnemy();
  if(present(who))  {
    string limb = who->GetRandomLimb("torso");  	    
    send_messages("rip", 
      "$agent_name lifts $target_name off the ground and %^GREEN%^ "
      "$agent_verb%^RESET%^ $target_possesive " + limb + " from "
      "$target_possesive body!",
      this_object(), who, environment());
    who->RemoveLimb(limb);    
  }
  return;
}

void init() {
  npc::init();
  fear::init();
 }
