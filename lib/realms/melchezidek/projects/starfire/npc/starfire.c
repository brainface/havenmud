/*  A massive blue dragon */
#include <lib.h>
#include <damage_types.h>
#include <position.h>
#include <armour_types.h>

inherit LIB_FEAR;
inherit LIB_SENTIENT;

void eventDragonBreath();
void DragonStuffs();
void eventSnap();
void eventElectricSlide();
void eventScream();
void IdleDragonStuffs();

static void create() {
  sentient::create();
  SetKeyName("starfire");
  SetMorality(-800);
  SetShort("Starfire, a huge blue draco-lich");
  SetResistLevel(250);
  SetRace("dragon");
  SetBaseLanguage("Padashi");
  SetGender("female");
  SetUndead(1);
  SetUndeadType("draco-lich");
//  SetEncounter(300);
  SetClass("evoker");
  SetSkill("melee combat", 0, 1);
  SetSkill("dodge", 0, 1);
  SetLevel(600);
  //SetLevel(50); /* testing level */
  SetFearLength(100);
  SetFearType("%^RED%^DRAGONFEAR!%^RESET%^");
  SetId( ({ "starfire", "dragon", "lich" }) );
  SetAdjectives( ({ "blue", "huge", "draco" }) );
  SetPosition(POSITION_LYING);
  SetLong("Starfire was once the largest of the blue dragons of Kailie. "
          "After her untimely death, she was restored into the form of a "
          "huge draco-lich by evil necromancers. Her undead form is a "
          "striking contrast to her mortal form, with pure evil radiating "
          "from the entire body. Her skeletal ribcage bears the scars "
          "of the death inflicted on her by the OrcFighter's Guild in "
          "that epic battle, yet some of her flesh remains as a grisly "
          "reminder of her mortal days.");
  SetSpellBook( ([
   ]) );
  SetAction(10, (: IdleDragonStuffs :) );
  SetCombatAction(100, (: DragonStuffs :) );
  SetFirstCommands( ({
      "cast enhanced energy wall",
      "cast enhanced energy wall",
   }) );
  }

void init() {
  fear::init();
  sentient::init();
 }


void DragonStuffs() {
   int choice = random(10);
   //debug("DragonStuffs called: " + choice);

   //choice = 9;  /* testing */
   switch(choice) {
     case 0:
       eventForce("cast enhanced energy wall");
       break;
     case 1:
       eventDragonBreath();
       break;
     case 2:
       eventForce("cast advanced chain lightning");
       break;
     case 3:
       eventForce("cast fireburst");
       break;
     case 4:
       eventForce("cast frostbite");
       break;
     case 5:
       eventForce("cast ice lance");
       break;
     case 6:
       eventForce("cast fireball");
       break;
     case 7:
       eventSnap();
       break;
     case 8:
       eventElectricSlide();
       break;
     case 9:
       eventScream();
       break;
   }
}


/* Damaged scaled based on current HP of starfire, this means as she
 * gets worn down, she does less damage in theory
 */

void eventDragonBreath() {
  /* Attack single target w/ lightning breath */
  object who = GetCurrentEnemy();
  int dmg = GetHealthPoints() + random(GetMaxHealthPoints());

  if (!present(who, environment(this_object()))) { return; }

  send_messages("breathe", 
       "$agent_name $agent_verb %^YELLOW%^BOLD%^a huge streak of lightning%^RESET%^"
       " which annihilates $target_name.",
       this_object(), who, environment());
  who->eventReceiveDamage(this_object(), SHOCK, dmg, 0, who->GetTorso());
  return;
}


void eventSnap() {
  /* Either direct bite face or miss and cause some blindness and poison in room */
  object who = GetCurrentEnemy();
  int dmg = GetHealthPoints() + random(GetMaxHealthPoints());
  int chance = random(10);
  array *occupants = ( (filter(all_inventory(environment())-({this_object()}),(: living :))) -
                       (filter(all_inventory(environment())-({this_object()}),(: creatorp :))) );

  //debug("Snap Chance: " + chance);
  if (chance > 3) {
    send_messages(({"rear", "snap" }),
        "$agent_name $agent_verb her head back and $agent_verb at $target_name crushing"
        " $target_objective in $agent_possessive maw!",
        this_object(), who, environment());
    who->eventReceiveDamage(this_object(), PIERCE, dmg, 0, who->GetTorso());
  } else {
    send_messages(({"rear", "snap" }),
        "$agent_name $agent_verb her head back and $agent_verb at $target_name but misses"
        " and disrupts a large amount of soot from the wall!",
        this_object(), who, environment());
    environment(this_object())->AddPoisonGas(random(10));

    foreach (object o in occupants) {
      o->eventBlind(this_object(), random(10));
      o->eventPrint("The soot has blinded you!");
    }
  }
}


void eventElectricSlide() {
  /* Starfire's electic breath AoE */
  /* Stupid players for bringing friends */
  int passes = random(3) + 1; // always do at least 1, max 3
  array *occupants = ( (filter(all_inventory(environment())-({this_object()}),(: living :))) -
                       (filter(all_inventory(environment())-({this_object()}),(: creatorp :))) );

  send_messages("rear",
                "$agent_name $agent_verb her head back and to the left before unleashing a"
                " terrifying %^YELLOW%^BOLD%^streak of lightning%^RESET%^ across the room"
                " from east to west!",
                this_object(), 0, environment());
  while (passes > 0) {
      foreach (object o in occupants) { 
        /* random damange for each target, halfed vs normal directed strike */
        int dmg = ( GetHealthPoints() + random(GetMaxHealthPoints()) )/2;
        send_messages("roast",
                      "$agent_name $agent_verb $target_name with her %^YELLOW%^BOLD%^lightning breath%^RESET%^!",
                      this_object(), o, environment());
        o->eventReceiveDamage(this_object(), SHOCK, dmg, 0, o->GetTorso()); 
       }
      passes-=1;
  }
}


void eventScream() {
  /* Scream and cause massive disorient and some paralysis */
  int rec_time = random(GetLevel());
  // any time you're paralyzed w/ a dragon attacking you will suck, but we just want this to be an
  // annoyance not necessarily a death sentence hence such a low value
  int paralyze_time = random(5);
  array *occupants = ( (filter(all_inventory(environment())-({this_object()}),(: living :))) -
                       (filter(all_inventory(environment())-({this_object()}),(: creatorp :))) );
 
 
  send_messages(({"pause","scream"}),
                "$agent_name $agent_verb her assault and%^RED%^ $agent_verb %^RESET%^!",
                this_object(), 0, environment());

  foreach (object o in occupants) {
    int chance = 100 + random(500);
    int chutzpah = o->GetLuck() * random(o->GetLevel());

    // Everyone gets dazed
    o->eventPrint("The sound of Starfire's scream assaults you!");
    o->AddRecoveryTime(rec_time);

    // Not Everyone gets paralyzed
    if (chance > chutzpah) {
      send_messages(({"are"}),
                    "$target_name $target_verb paralyzed by $agent_possessive_noun scream!",
                    this_object(), o, environment());
      o->AddParalyzed(paralyze_time);
    }
  }
}


void IdleDragonStuffs() {
  switch(random(4)) {
    case 0:
      if (sizeof(GetMagicProtection()) < 3) eventForce("cast enhanced energy wall" );
      break;
    case 1:
      eventForce("emote idly whips her tail about the room.");
      break;
    case 2:
      eventForce("emote seems to almost purr with her power.");
      break;
    case 3:
      eventForce("emote gives you a quick look and decides you are no threat.");
      break;
  }
}

