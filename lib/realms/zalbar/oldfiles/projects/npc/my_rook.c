/*  
 *  Rook
 *  A silver dragon for the WestWood region
 *  Good aligned, aid to the good in times of trouble
 *  Started by Gaby 08/31/99
 *  Finished by Gaby 09/03/99
 */
#define FRIENDS ({ "bugger", "pfria" }) 
#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include <damage_types.h>
//#include "../rook.h"

inherit LIB_SENTIENT;
inherit LIB_FEAR;

void PossibleAttack();
void eventRook();
void eventBreatheL(object target);
void eventBreatheG();
void eventBuffet();
void eventBite(object target);
void eventTailStrike(object target);
void eventTailSwipe();
int CheckEncounter(string args);

static void create() {
  sentient::create();
  SetKeyName("Brook");
  SetId( ({ "dragon", "Brook" }) );
  SetShort("Brook, a gargantuan silver dragon");
  SetAdjectives( ({ "gargantuan", "silver", "brook", "dragon" }) );
  SetLong(
    "This huge dragon that stands here is known as Brook.  She is gargantuan "
    "in size and has silvery scales covering her entire body.  There is a set of "
    "large, curved horns on her head with smaller horns scattered around them.  "
    "Small horns also run down the length of her back to the tip of her tail which"
    " is spiked with horns the size of longswords.  Her eyes reveal a high level "
    "of intelligence and power as well as age beyond that of any mortal being.  "
    "She has a set of large wings tucked in tight to her body at the moment, but "
    "they appear large enough to easily move this gargantuan creature through the "
    "air at breakneck speeds.");
  SetAdjectives( ({ "silver" }) );
  SetRace("dragon");
  SetGender("female");
  SetMorality(2000);
  SetReligion("Eclat");
  SetClass("animal");
  SetSkill("faith",         1, 1);
  SetSkill("evokation",     1, 1);
  SetSkill("enchantment",   1, 1);
  SetSkill("pierce combat",1, 1);
  SetSkill("slash combat", 1, 1);
  SetSkill("melee combat",  1, 1);
  SetSkill("natural magic",  1, 1);
  SetLevel(750);
  SetSpellBook( ([
    //"supernova" : 100,
    //"solar charge" : 100,
    "blizzard" : 100,
    //"solar flare" : 100,
    "barrier of faith" : 100,
    "divine cataclysm" : 100,
  ]) );
  SetLanguage("Eltherian", 100);
  SetMeleeAttackString("claws");
  SetMeleeDamageType(PIERCE);
  SetFearType("%^BOLD%^WHITE%^DRAGONFEAR%^RESET%^");
  SetFearLength(40 + random(40));
  SetResistLevel(200);
  SetAction(10, (: PossibleAttack :) );
  SetEncounter( (: CheckEncounter :) );
  SetCombatAction(55, (: eventRook :) );
  SetResistance(GAS,   "immune");
  SetResistance(MAGIC, "high");
  AddFood(-2400);
}

void eventEnemyDied(object who) {
  eventForce("eat corpse");
  sentient::eventEnemyDied(who);
}

void init() {
  sentient::init();
  fear::init();
}

/*varargs int eventDie(object agent) {
  object horn;
  object inv;
object inv2;
object inv3;
  horn = new(R_OBJ + "horn");
  horn->eventMove(this_object());
  horn = new(R_OBJ + "horn");
  horn->eventMove(this_object());
  agent->AddTitle("the LightsBane");

  agent->SetMorality(agent->GetMorality()-500);
  inv = new(DIR_INVASIONS + "/soleil_demon/dis_inv");
  INVASION_D->eventRegisterInvasion(inv, agent);
  inv2 = new(DIR_INVASIONS + "/soleil_demon/dis_2_inv");
  INVASION_D->eventRegisterInvasion(inv2, agent);
  inv3 = new(DIR_INVASIONS + "/soleil_demon/dis_3_inv");
  INVASION_D->eventRegisterInvasion(inv3, agent);
  return sentient::eventDie(agent);
}
 */
int CheckEncounter(string arg) {
  object visitor;
  eventForce("cast solar charge");
  visitor = previous_object();
  if( 
    present("feather",   visitor)  ||
    present("dark cloak",visitor)  ||
    present("stick",     visitor)    ) {
      eventBite(visitor);
      return 1;
    }
  return 0;
}

void PossibleAttack() {
  object *people;
  people = filter(all_inventory(environment()), (: living :));
  people -= ({ this_object() });
  foreach(object thing in people)  {
    if (member_array(thing->GetKeyName(), FRIENDS) != -1)  {
      people -= ({ thing });
      }
    if (thing->GetReligion() == "Eclat")  {
      people -= ({ thing });
      }

  }
  foreach(object thing in people) {
    eventForce("attack " + thing->GetKeyName());
  }
  return;
}

void eventRook() {
  int rook = random(12);
  object dragon = this_player();
  object target = GetCurrentEnemy();

  switch(rook) 
  {
    case 1:
      eventForce("cast blizzard");
    break;
    case 2:
      eventForce("cast barrier of faith");
    break;
    case 3:
      eventForce("cast divine cataclysm");
    break;
    case 4:
      eventBuffet();
    break;
    case 5:
      dragon->eventBite(target);
    break;
    case 6:
      dragon->eventBreatheG();
    break;
    case 7:
      dragon->eventBreatheL(target);
    break;
    case 8:
      dragon->eventTailStrike(target);
    break;
    case 9:
      eventTailSwipe();
    break;
    case 0:
      eventForce("cast divine cataclysm");
    break;
    case 10:
      eventForce("cast barrier of faith");
    break;
    case 11:
      eventForce("cast blizzard");
    break;
  }
}

void eventBreatheL(object target) {
  int sp = GetStaminaPoints();

  if (sp > 100) {
    this_object()->AddStaminaPoints(-100);
    send_messages("breath", 
      "%^WHITE%^Rook $agent_verb a long streak of white lighting at $target_name!%^RESET%^", 
      this_object(), target, environment());
    target->eventReceiveDamage(this_object(), SHOCK, GetHealthPoints(), 0);
    }  
}

void eventBreatheG() {
  int sp = GetStaminaPoints();

  if (sp > 80) {
    this_object()->AddStaminaPoints(-80);
    send_messages("breath", 
      "%^YELLOW%^Rook $agent_verb out a long billowing cloud of gas that quickly fills the room!%^RESET%^",
      this_object(), 0, environment());
    environment()->AddPoisonGas(125);
  }
}

void eventTailStrike(object target) {
  int damage = (GetHealthPoints()/10);
  int health = target->GetHealthPoints();
  int sp = GetStaminaPoints();

  if (sp > 65) {
    this_object()->AddStaminaPoints(-65);
    if(damage > health) {
      send_messages( ({"swing","strike"}),
        "%^ORANGE%^Rook $agent_verb $agent_possessive tail over $agent_possessive head and $agent_verb $target_name, impaling "
        "$target_possessive body!%^RESET%^", 
        this_object(), target, environment());
      target->eventReceiveDamage(this_object(), PIERCE, damage, 0);
      return;
    }
    else 
    {
      send_messages( ({"swing","strike"}),
        "%^ORANGE%^Rook $agent_verb $agent_possessive tail over "
        "$agent_possessive head and $agent_verb $target_name!%^RESET%^", 
        this_object(), target, environment());
      target->eventReceiveDamage(this_object(), BLUNT, damage, 0);
      return;
    }
  }
  else 
  {
    return;
  }
}

void eventTailSwipe()
{
  int damage = (GetHealthPoints()/25);
  int sp = GetStaminaPoints();
  string *target;
  target = filter(all_inventory(environment())-({this_object()}),(: living :));

  if (sp > 45) 
  {
    this_object()->AddStaminaPoints(-45);
    send_messages("swing",
      "%^ORANGE%^Rook $agent_verb $agent_possessive tail around $agent_possessive"
      " body in a sweeping arc!%^RESET%^", this_object(), target, environment());
    target->eventCollapse();
    target->eventReceiveDamage(this_object(), PIERCE, damage, 0);
    return;
  }
  else 
  {
    return;
  }
}

void eventBuffet()
{
  int sp = GetStaminaPoints();
  string *target;
  target = filter(all_inventory(environment())-({this_object()}),(: living :));

  if (sp > 75) 
  {
    this_object()->AddStaminaPoints(-75);
    send_messages("buffet", "%^BLUE%^Rook rears up on her hind legs, flaps her "
      "wings, and $agent_verb you with wind!%^RESET%^", this_object(), 0, environment());
    target->eventCollapse();
    return;
  }
  else 
  {
    return;
  }
}

void eventBite(object target) 
{
  string limb = target->GetRandomLimb("torso");
  int damage = GetHealthPoints();
  int limb_hp = target->GetLimb(limb)["health"];
  string *exits;  
  string NewLoc;
  if(environment() != environment(target)) return;
  damage /= 2;

  if(damage > limb_hp && limb != "head" && limb != "torso") {
    send_messages("sever",
        "%^RED%^Rook $agent_verb $target_possessive_noun " + limb + " with $agent_possessive viscious bite!%^RESET%^",
        this_object(), target, environment());
    target->RemoveLimb(limb);
    return;
  }
  else if(damage > limb_hp && limb == "head")   {
    send_messages("bite",
        "%^CYAN%^Rook $agent_verb $target_possessive_noun " + limb + " off in one vicious bite killing $target_name "
        "instantly!%^RESET%^", this_object(), target, environment());
    target->RemoveLimb(limb);
    return;
  }
  else if(damage > limb_hp && limb == "torso")  {
    send_messages( ({"pick","throw"}),
        "%^CYAN%^Rook $agent_verb $target_name up in $agent_possessive "
        "massive jaw and thrashes about viciously, then $agent_verb $target_name "
        "away from the battle!%^RESET%^", this_object(), target, environment());
    target->RemoveLimb(limb);
    target->eventCollapse();
    return;
  }  else   {
    send_messages( ({ "attempt", "succeed" }),
      "%^RED%^Rook $agent_verb to bite $target_name but $agent_verb only in "
      "doing massive damage to $target_possessive_noun " + limb + ".%^RESET%^",
      this_object(), target, environment());
      target->eventReceiveDamage(this_object(), PIERCE, damage, 0, limb);
      target->eventCollapse();
    return;
  }
}

