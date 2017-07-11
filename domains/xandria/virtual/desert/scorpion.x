/* A minor enemy for xandrian desert
// poisons as a special                  
// mahkafel september '10               
*/                                      

#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <damage_types.h>
#include <domains.h>     
inherit LIB_NPC;         

void eventSpecial();

static void create() {
  npc::create();      
  SetKeyName("sand scorpion");
  SetId( ({ "scorpion" }) );
  SetAdjectives( ({ "sand" }) );       
  SetShort("a sand scorpion");            
  SetLong("This vicious little scorpion is colored a mottled brown and tan, "
    "making it extremely hard to spot for unsuspecting prey. The size "
    "of a small child, they have been known to stalk travellers weakened "
    "by the deserts sun. The thick, black venom dripping from its stinger "
    "assists it in this task.");                                               
  SetGender("female");                                                         
  SetRace("arachnid","scorpion");
  SetSize(SIZE_SMALL);
  AddLimb("tail","torso",2,({A_WEAPON}));                                                      
  AddLimb("left pincer","torso",2);
  AddLimb("right pincer","torso",2);                                                                                                            
  SetClass("fighter");                                                         
  SetLevel(25);                                                              
  SetAction(20, ({
    "!emote scitters along frantically.",
    "!emote buries itself in the sand.",
  }) );
  SetCombatAction(15, (: eventSpecial :) );
  SetEncounter(50);
  SetFirstCommands( ({"wield khopesh"}) );
  SetInventory(([ XANDRIA_VIRTUAL "desert/stinger" : "wield stinger in tail" ]));
  SetMeleeAttackString("jagged pincer");
  SetMeleeDamageType(PIERCE);
  SetResistance(BLUNT|COLD, "weakness");
  SetResistance(SLASH|PIERCE, "low");
}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();
  send_messages("clutch",
    "$agent_name%^ORANGE%^ $agent_verb%^RESET%^ $target_name "
    "with a jagged pincer, immobilizing $target_objective!",
    who, target, environment() );
  target->eventReceiveDamage(who, BLUNT|PIERCE, random(50), 0,
    target->GetRandomLimb("torso") );
  target->AddParalyzed(random(3)+1);
  return;
}

void init() {
  npc::init();
}

