/* A minor opponent for Arcanith
 * mahkafel october '10         
 */                             

#include <lib.h>
#include <damage_types.h>
//#include "../arc_library.h"
inherit LIB_NPC;             

void eventSpecial();

static void create() {
  npc::create();      
  SetKeyName("wind mephit");
  SetId( ({ "mephit"}) );   
  SetAdjectives( ({ "wind" }) );
  SetShort("a wind mephit");    
  SetLong(                      
    "This imp-like creature is a thin, whispy figure surrounded by a "
    "small whirlwind of debris. Occassionally razor-sharp teeth and " 
    "crooked claws flash ominously amidst the roiling air."           
  );
  SetGender("male");
  SetRace("demon","mephit");
  SetBaseLanguage("Archaic");
  SetClass("mystic");
  AddLimb("tail", "torso", 4);
  AddLimb("left wing", "torso", 4);
  AddLimb("right wing", "torso", 4);
  SetLevel(15);
  SetAction(5, ({
    "!flail",
    "!emote flits about the room on flimsy wings.",
    "!speak Turning and turning in the widening gyre!",
    "!emote gnaws on the remains of a book.",
    "!go up",
    "!go down",
  }) );
  SetMorality(-100);
  SetCombatAction(20, ({
    "!cast wind wall",
    "!cast ice ball",
  }) );
  SetDie("");
  SetLimit(20);
  SetFirstCommands( ({ "cast wind wall" }) );
  SetMeleeAttackString("%^BOLD%^BLACK%^needle-like%^RESET%^ teeth");
  SetMeleeDamageType(SLASH);
  SetResistance(ALL_DAMAGE, "low"); // reset resistances
  SetResistance(ALL_PHYSICAL, "medium");
  SetResistance(SOUND, "weakness");
}

