#include <lib.h>
#include "../path.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("farmer");
  SetShort("a blissfully happy farmer");
  SetId( ({ "farmer", "trainer" }) );
  SetAdjectives( ({ "blissfully", "blissful", "happy" }) );
  SetRace("halfling");
  SetTown("Lloryk");

  SetLong("This short halfling seems to be moderately happy in his "
          "life as a farmer in the Shire. Though content with his "
          "work, he would be willing to spend some time teaching "
          "anyone who was interested in farming.");
  SetTrainingSkills( ({ 
  	"farming", 
  	"stealing", 
  	"stealth", 
    "knife combat", 
    "bargaining", 
    "lockpicking",  
    "skinning",
    "cooking",
    }) );
  
  SetClass ("merchant");
  SetSkill("pole combat", 1, 1);
  SetLevel(5);
  SetCurrency( ([
    "rounds" : 20,
    ]) );
  SetMorality(200);
  SetGender("male");
  SetInventory( ([
    LLORYK "obj/hoe" : "wield hoe",
    ]) );
  SetAction(5, ({
    "!whistle",
    "!farm with my hoe",
    "!speak I'd like to teach you how to farm.",
    "!speak Ask me to teach you.",
    "!speak Oh farming is for me.",
    }) );
}
