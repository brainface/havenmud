// Torak@Haven
// 11/11/12
// fiiiiiiiiiiiiiiiish

#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include <damage_types.h>
#include <size.h>
#include "../path.h"

inherit LIB_SENTIENT;

static void create() {

  string pronoun = "He";
  string objective = "him";
  string possessive = "his";
  ::create();
  if(random(2)) { 
    SetGender("male"); 
    }
  else  {
    SetGender("female");
    pronoun = "She"; 
    objective = "her";
    possessive = "her";
    }

  SetKeyName("penguin");
  SetShort("a zombie rockhopper penguin");
  SetId( ({"penguin", "rockhopper", "zombie", "bird"}) );
  SetAdjectives( ({"zombie", "rockhopper"}) );
  SetLong("The zombie penguin has yellow crested plumage on " 
    +possessive+ " head where the skin has not yet fallen off. "
    "Blood and muck smear the once black coat and white belly. "
    "Vicious holes show the bones through " +possessive+ " skin.");
  SetMorality(0);
  SetFriends( ({
    "penguin",
    }) );
  SetRace("bird");
  SetSize(SIZE_SMALL);
  SetUndead(1);
  SetNoCorpse(1);
  SetDie("The zombie penguin crumbles to dust.");
  SetClass("animal");
  SetSkill("dodge", 1, 1);
  SetSkill("brawling", 1, 1);
  SetSkill("accuracy", 1, 1);
  SetSkill("swimming", 1, 1);
  SetSkill("stealing", 1, 1);
// SetProperty("swimmer", 1);
  SetEncounter(100);
  SetWander(20);
  SetLimit(15);
  SetLanguage("Archaic", 100, 1);
  RemoveLanguage("Birdish");
  SetLevel(250);
  SetCombatAction(10, ({
    "!headbutt",
    }) );
  SetInventory( ([
    ]) );
  AddFood(-3000);
  SetResistance(HUNGER, "immune");
  SetResistance(COLD, "immune");
  SetMeleeAttackString("%^CYAN%^ice cold beak%^RESET%^");
  SetMeleeDamageType(PIERCE|COLD);
}
