

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
  SetResistLevel(200);
  SetRace("dragon");
  SetBaseLanguage("Padashi");
  SetGender("female");
  SetUndead(1);
  SetUndeadType("draco-lich");
  SetEncounter(300);
  SetClass("necromancer");
  SetSkill("melee combat", 0, 1);
  SetSkill("dodge", 1, 1);
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
    "fortress of solitude" : 100,
    "death" : 100,
    "poison explosion" : 100,
   ]) );
  SetFirstCommands( ({ 
    "cast fortress of solitude",
    "cast fortress of solitude",
    "cast fortress of solitude",
   }) );
  SetAction(5, ({
      "Starfire idly whips her tail about the room.",
      "Starfire seems to almost purr with her power.",
      "Starfire gives you a quick look and decides you are no threat.",
    }) );
  SetCombatAction(10, (: eventDragonBreath :) );
  }

void init() {
  fear::init();
  sentient::init();
 }

void eventDragonBreath() {
  object toast = GetCurrentEnemy();
  if (!present(toast, environment(this_object()))) { return 0; }
  send_messages("breathe", 
     "$agent_name $agent_verb %^YELLOW%^BOLD%^a huge streak of lightning%^RESET%^ which annihilates $target_name.",
     this_object(), toast, environment());
  toast->eventReceiveDamage(this_object(), SHOCK, GetHealthPoints(), 0, toast->GetTorso());
  return;
 }

