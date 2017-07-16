#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("ivan");
  SetShort("Ivan the Mad, a Battle Scarred Veteran");
  SetId( ({ "ivan", "veteran", }) );
  SetAdjectives( ({ "mad", "battle", "scarred" }) );
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetTrainingSkills( ({
    "pierce combat", 
    "multi-weapon",
    "slash combat", 
    "melee combat", 
    "weapon smithing", 
    "armour smithing", 
    "metal working", 
    "textile working",
    "mithril working",
    "leather working", 
    "wood working", 
    "natural working",
    "hack combat", 
    "pole combat", 
    "knife combat", 
    "blunt combat",
    "projectile combat",
    }) );
  SetTown("Gurov");
  SetGender("male");
  SetClass("fighter");
  SetLevel(12);
  SetCurrency("rubles", 200);
  SetMorality(-50);
  SetLong(
    "Ivan the Mad has seen battle.  Lots of battle.  He would be "
    "an excellent trainer in all things combat oriented. His physique "
    "suggests there is no form of combat that is unknown to him."
    );
  SetAction(6, ({
    "!speak Did you need me to teach you?",
    "!speak Young Pup, when I was your age I was pounding the Ninjas into dirt.",
  }) );
  SetInventory( ([
    STD_SLASH "sword" : 2,
    ]) );
  SetFirstCommands( ({ "wield all" }) );
  SetLimit(1);
}
