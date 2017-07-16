
#include <lib.h>
#include "../camp.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("musician");
  SetShort("a talented musician");
  SetId( ({ "musician"}) );
  SetAdjectives( ({ "talented" }) );
  SetLong(
    "The musician plays with a skill and passion "
    "that is rarely seen.  His dark eyes flash with each note."
  );  
  SetGender("male");  
  SetRace("human");
  SetClass("bard");
  SetLevel(30);
  SetSongBook( ([
  	"warrior's honor" : 100,
  	"aria of fire"    : 100,
  	"magical lullaby" : 100,
  	]) ); 
  SetCombatAction(30, ({
    "!sing warrior's honor",
    "!sing aria of fire",
    "!sing magical lullaby",
    }) );   
  SetMorality(150);
  SetCurrency("rupies", random(50));
  SetAction(5, ({ 
  	"The musician plays the dulcimer skillfully." 
  	}));

  SetInventory( ([
    C_OBJ + "pants2" : "wear pants",
    C_OBJ + "shirt3" : "wear shirt",
    C_OBJ + "dulcimer1" : 1,
    C_OBJ + "dagger1" : "wield dagger",
  	]) );
}

