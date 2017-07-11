//Alex@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../area.h"
inherit LIB_SENTIENT;

static void create(){
  sentient::create();
  SetKeyName("child");
  SetShort("an unwashed child");
  SetId( ({"child"}) );
  SetAdjectives( ({"unwashed"}) );
  SetRace("human");
  SetBaseLanguage("Barian");
  SetClass("fighter");
  SetSkill( "projectile combat", 2, 1);
  SetLevel(10);
  SetLong(
    "This child is a mangy, wild, naked beast that could do with a "
    "good spanking. He is indestinguishable from his brother under "
    "the dirt and matted hair. He has a mischievious gleam in his "
    "eyes, and seems like he would fight you in an instant, if he "
    "felt like it.");
  SetGender("male");
  SetCurrency("chits", 10);
  SetInventory( ([
    AREA_OBJ "dirtball" : "wield dirtball",
  ]) );
  SetAction(10, ({
    "!yell He's touching me!",
    "The child jumps on one of the mats boisterously.",
    "The child runs screaming around the room.",
    "The child makes obscene faces at you.",
  }) );
  
  SetMorality(-50);
  SetSmell( "He smells like any unwashed little boy.");
}
