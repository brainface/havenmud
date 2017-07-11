#include <lib.h>
#include <damage_types.h>
#include <std.h>
#include "../outpost.h"


inherit LIB_NPC;

void DoSomething(); 
void DoCombatSomething();
void Blast(object target);
void HeadBash(object target);

static void create() {
  ::create();
  SetKeyName("effigy");
  SetId( ({ "effigy", "kylin_invader" }) );
  SetShort("a pure white effigy of Kylin");
  SetAdjectives( ({ "pure", "white", "kylin" }) );
  SetLong(
    "This pure white creature stands with a pale glow about it. "
    "From its eyes of pure gold, a cold stare that is resplendant "
    "of martial glory and magic penetrates the soul of those around. "
    );
  SetRace("demon");
  SetClass("fighter");
  SetSkill("fire magic",1,1);
  SetSkill("faith", 1,1);
  SetSkill("enchantment",1,1);
  SetLevel(210);
  SetReligion("Kylin");
  SetMorality(2000);
  SetMeleeDamageType(BLUNT|MAGIC);
  AddLimb("right wing", "torso", 4);
  AddLimb("left wing", "torso", 4);
  SetSpellBook( ([
    "hand of judgement"      : 100,
    "superior wall of force" : 100,
    "divine power"           : 100,
    ]) );
  SetCombatAction(50, (: DoCombatSomething :) ); 
  SetAction(1, (: DoSomething :) );
  SetNoCorpse(1);
  SetDie("%^BOLD%^WHITE%^With a golden flash, the effigy returns to its home plane.%^RESET%^");
  SetInventory( ([
    OP_OBJ + "large_sword"   : "wield sword",
    OP_OBJ + "warhammer"     : "wield hammer",
    OP_OBJ + "effigy_armour" : 
      "wear armour on torso and left leg and right leg and right arm and left arm",
                               
    ]) );
  SetFriends( ({"kylin invader"}) );
  SetFirstCommands( ({ 
    "cast divine power",
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
  if ((sizeof(GetMagicProtection()) < 2)) {
    eventForce("cast superior wall of force" );
    return;
  }
}

void DoCombatSomething() {
  object target = GetCurrentEnemy();
  object effigy = this_object();
  int rnd = random(5);
  
  if ((sizeof(GetMagicProtection()) < 5)) {
    eventForce("cast superior wall of force" );
    return;
  }

  switch(rnd) {
    case 0:
      eventForce("disorient");
      break; 
    case 1:
      effigy->Blast(effigy,target);
      break;
    case 2:
      effigy->HeadBash(effigy,target);
      break;
    default:
      eventForce("cast hand of judgement");
      break;
  }
}

void HeadBash(object who, object target) {
  if(present(target)) {
    if(target->GetPosition() < 3) {
      send_messages("rush", "%^BOLD%^%^BLUE%^ $agent_name $agent_verb forward bashing "
        "$agent_possessive head against $target_possessive_noun head knocking "
        "$target_objective down! %^RESET%^", who, target, environment() );
       target->eventCollapse(1);
      }
    else {
      send_messages("rush", "%^BOLD%^%^BLUE%^ $agent_name $agent_verb forward kicking "
        "$target_name in the head! %^RESET%^", who, target, environment() );
      }
    //debug("target HP: " + target->GetHealthPoints());
    //debug("target head HP: " + target->GetHealthPoints("head"));
    target->SetParalyzed(5);
    target->AddRecoveryTime(500);
    target->eventReceiveDamage(who, BLUNT, 500, 0, "head");
    //debug("target HP: " + target->GetHealthPoints());
    //debug("target head HP: " + target->GetHealthPoints("head"));
   
  }
}
    
void Blast(object who, object target) {
  if(GetMagicPoints() > 300) {
    send_messages("close", "%^YELLOW%^ $agent_name $agent_verb $agent_possessive "
      "eyes for a moment and then suddenly opens them striking $target_name with "
      "a golden flash. %^RESET%^", who, target, environment() );
      target->eventReceiveDamage(who, SHOCK, 1000, 0, "torso");
      who->AddMagicPoints(-300); 
  }
}