/* A minor opponent for Arcanith
 * mahkafel october '10         
 */                             

#include <lib.h>
#include <damage_types.h>
//#include "../arc_library.h"
inherit LIB_NPC;             

static void create() {
  npc::create();      
  SetKeyName("fire mephit");
  SetId( ({ "mephit"}) );   
  SetAdjectives( ({ "fire" }) );
  SetShort("a fire mephit");    
  SetLong(                      
    "This imp-like creature is a bright bundle of flame forced into a "
    "vaguely humanoid shape. His face is contorted into a wicked, gleeful "
    "grin below twin eyes full of malfeance."
  );
  SetGender("male");
  SetRace("demon","mephit");
  SetBaseLanguage("Archaic");
  SetClass("mystic");
  AddLimb("tail", "torso", 4);
  AddLimb("left wing", "torso", 4);
  AddLimb("right wing", "torso", 4);
  SetLevel(35);
  SetAction(5, ({
    "!speak Ashes, ashes, they all fall down!",
    "!speak Words on a page? What is that worth?",
    "!emote ignites an priceless tome with a jet of flame.",
    "!emote knocks over a surviving bookshelf, before setting it on "
      "fire for good measure.",
    "!emote soars above the stacks on burning wings."
  }) );
  SetMorality(-100);
  SetCombatAction(20, ({
    "!cast natural veil",
    "!cast fireball",
  }) );
  SetDie("");
  SetFirstCommands( ({ "cast natural veil" }) );
  SetMeleeAttackString("%^BOLD%^BLACK%^flaming%^RESET%^ claw");
  SetMeleeDamageType(HEAT);
  SetResistance(ALL_DAMAGE, "low"); // reset resistances
  SetResistance(ALL_PHYSICAL, "medium");
  SetResistance(WATER|COLD, "weakness");
}

