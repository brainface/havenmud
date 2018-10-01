/*  A massive blue dragon */
#include <lib.h>
#include <damage_types.h>
inherit LIB_FEAR;
inherit LIB_SENTIENT;

void eventDragonBreath();

static void create() {
  sentient::create();
  SetKeyName("starfire");
  SetMorality(-800);
  SetShort("Starfire, a huge blue draco-lich");
  SetResistLevel(90);
  SetRace("dragon");
  SetLanguage("Padashi", 100);
  SetGender("female");
  SetUndead(1);
  SetUndeadType("draco-lich");
  SetEncounter(101);
  SetClass("evoker");
  SetSkill("melee combat", 0, 1);
  SetLevel(600);
  SetFearLength(100);
  SetFearType("%^RED%^DRAGONFEAR!%^RESET%^");
  SetId( ({ "starfire", "dragon", "lich" }) );
  SetAdjectives( ({ "blue", "huge", "draco" }) );
  SetLong("Starfire was once the largest of the blue dragons of Kailie. "
          "After her untimely death, she was restored into the form of a "
          "huge draco-lich by evil necromancers. Her undead form is a "
          "striking contrast to her mortal form, with pure evil radiating "
          "from the entire body. Her skeletal ribcage bears the scars "
          "of the death inflicted on her by the OrcFighter's Guild in "
          "that epic battle, yet some of her flesh remains as a grisly "
          "reminder of her mortal days.");
  SetSpellBook( ([
     "chain lightning" : 100,
     "disintegrate" : 100,
     "fireball" : 100,
     "aura" : 100,
     "enhanced aura" : 100,
     "enhanced fireball" : 100,
     "yossarian's flamestrike" : 100,
    ]) );
  SetAction(5, ({
      "Starfire idly whips her tail about the room.",
      "Starfire seems to almost purr with her power.",
      "Starfire gives you a quick look and decides you are no threat.",
    }) );
  SetCombatAction(5, (: eventDragonBreath :) );
  }

void init() {
  add_action("cmdBreath", "breathe");
  fear::init();
  sentient::init();
 }

int cmdBreath() {
  if (this_player() != this_object() ) return 0;
  eventDragonBreath();
  return 1;
  }

void eventDragonBreath() {
  object toast = GetCurrentEnemy();
  if (!present(toast, environment(this_object()))) { return 0; }
  send_messages("breathe", 
     "$agent_name $agent_verb %^YELLOW%^BOLD%^a huge gout of "
     "lightning%^RESET%^ which annihilates $target_name.",
     this_object(), toast, environment());
  toast->eventReceiveDamage(this_object(), SHOCK,
     GetHealthPoints());
  return;
 }


