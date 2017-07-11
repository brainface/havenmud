#include <lib.h>
#include "../gurov.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("pavel");
  SetShort("Pavel the Sot");
  AddAlcohol(75);
  SetId( ({ "pavel" }) );
  SetAdjectives( ({ "sot" }) );
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetGender("male");
  SetTrainingSkills( ({
  	"sailing", 
  	"navigation", 
  	"knife combat",
  	"fishing", 
  	"swimming",
  }) );
  SetClass("sailor");
  SetLevel(20);
  SetMorality(50);
  SetLong("Pavel was a sailor... once.  But a few too many "
          "bottles of rum and he's no longer saying \"Yo ho ho\". "
          "However, he's always willing to teach someone and tell "
          "his tales of the sea.");
  SetInventory( ([
    GUROV_OBJ "rum" : 1,
    ]) );
  SetAction(5, ({
  	"!speak Yo ho ho!",
  	"!yell Ahoy Mateys!",
  	"!drink my rum",
  	"!speak Aye, I can teach you about sailing!",
  }) );
  SetLimit(1);
  SetTown("all");
}

  	
  	
