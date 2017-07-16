#include <lib.h>
#include <std.h>
#include <daemons.h>
#include <size.h>
#include "../durgoroth.h"

inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("Shalnarleth");
  SetRace("maralith");
  SetSize(SIZE_LARGE);
  SetClass("fighter");

  AddTrainingSkills("hack combat");
  AddTrainingSkills("berserking");

  SetLevel(300);
  SetGender("female");
  SetShort("Shalnarleth, the Aspect of War");
  SetId( ({ "shalnarleth","aspect","war" }) );
  SetBaseLanguage("Gryshnak");
  SetLong(
    "This maralith towers over others of her kind, and her coal-black scales "
    "and skin attest to a different origin or stage of evolution. The maddened "
    "look in her eyes contrasts with her pleasant, reasonable sounding voice, "
    "and she looks over those she passes as if weighing their worth for some "
    "grand experiment."
  );
  SetAction(5, ({
    "!emote roars defiantly at the heavens.",
    "!speak Do you wish to crush your enemies--see them driven before you?",
    "!speak You seek the powers of chaos. Allow me to share them.",
    "!emote juggles her axes around in a whir of steel and limbs.",
    "!speak I will merely show you how to harness your own rage. I am sure "
      "you possess the willpower to control what you unleash.",
  }) );
  SetCombatAction(50, ({
    "!cleave",
    "!reave",
    "!reave",
    "!massacre",
    "!frenzy", // yes, my npc kills herself.
    "!rattle",
    "!speak You hope to defeat war itself?!",
    "!speak Come, whelp! Learn what it means to battle for your own existance!",
  }) );
  SetTown("all");
  SetMorality(-2000);
  SetInventory( ([
     DURG_OBJ "obs_hatchet" : "wield hatchet in upper right hand",
     DURG_OBJ "silver_glaive" : "wield glaive in lower right hand and lower left hand",
     DURG_OBJ "magma_axe" : "wield axe in upper left hand",
     "/domains/planes/obj/bone_armour" : "wear armour on torso and upper right arm and upper left arm",
     "/domains/planes/obj/scale_shield" : 2,
  ]) );
  SetFirstCommands( ({
    "wear first shield on middle right hand",
    "wear first shield on middle left hand",
  }) );
  SetCurrency("crystals", 5000);
}

