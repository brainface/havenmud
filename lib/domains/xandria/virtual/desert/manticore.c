/* A flesh eating manticore for xandria
// Poisons as a special
// mahkafel september '10
*/

#include <lib.h>
#include <damage_types.h>
#include <domains.h>
#include <armour_types.h>
inherit LIB_NPC;
inherit LIB_FEAR;

void eventSpecial();
int eventCheckPlayer();

static void create() {
  npc::create();
  SetKeyName("manticore");
  SetId( ({ "manticore" }) );
  SetAdjectives( ({ "flesh-eating", "flesh", "eating" }) );
  SetShort("a flesh-eating manticore");
  SetLong(
    "This is a manticore, a flesh-eating monster with a feline body, "
    "whiplike spiked tail, and feathered wings. It is said Nefyth "
    "created the first manticores from her most devoted followers, as "
    "it bears the face of a cruel, sneering gnoll."
  );
  SetGender("male");
  SetRace("dragon","manticore"); // right body structure
  // dragons currently don't have tails, but dammit they should.
  DestLimb("tail",);
  AddLimb( "tail","torso",4,({A_WEAPON}) );
  SetReligion("Enniae");
  SetBaseLanguage("Rehshai");
  SetClass("priest");
  SetSkill("knife combat",1,1); // for spike
  SetLevel(75+random(20));
  SetMorality(-1700);
  SetAction(20, ({
    "!roar",
    "!emote sneers arrogantly.",
    "!emote flaps his wings lazily.",
    "!emote circles in the air, searching for prey.",
    "!emote soars higher in the sky."
  }) );
  SetCombatAction(15, (: eventSpecial :) );
  SetEncounter( (: eventCheckPlayer :) );
  SetFearLength(10);
  SetFearType("primal fear");
  SetFirstCommands( ({"wield spike", "cast wall of souls", "cast pious obstructions"}) );
  SetInventory(([ XANDRIA_VIRTUAL "desert/poison_spine" : "wield spine in tail" ]));
  SetDie("The manticore drops from the sky and impacts with the crashing sound of "
    "breaking bones.");
  SetMeleeAttackString("tiger claws");
  SetMeleeDamageType(PIERCE);
  SetResistance(COLD, "weakness");
  SetResistance(HEAT|MAGIC, "medium");
  SetResistLevel(12);
  SetSpellBook( ([
    "creeping doom" : 100,
    "summon asp" : 100,
    "wall of souls" : 100,
    "pious obstructions" : 100,
  ]) );
}

// 50% chance to cast priest spell
//  or poison with spines
void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();
  if (random(2)) {
    eventForce("cast creeping doom");
    return;
  }
  send_messages("hurl",
    "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ spines at $target_name, "
    "impaling $agent_objective with the poisonous barbs!",
     who, target, environment() );
  target->eventReceiveDamage(who, PIERCE, random(500), 0,
    target->GetRandomLimb() );
  target->AddPoison(20+random(20));
  return;
}

void init() {
  fear::init();
  npc::init();
}

// now on a new snake free diet.
int eventCheckPlayer() {
  object who = this_player();
  if (playerp(who)) {
    if (who->GetStatLevel("charisma") < 100) {
      SetAttack(who);
      return 1;
    }
  }
  return 0;
}
