
#include <lib.h>
#include "../camp.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("fortune teller");
  SetShort("a fortune teller");
  SetId( ({ "fortuneteller", "teller"}) );
  SetAdjectives(({"fortune"}) ); 
  SetLong(
    "This fortuneteller has long gray hair and "
    "black eyes. Not much escapes her knowing gaze."
  );
  SetClass("necromancer");
  SetLevel(90);
  SetRace("human");  
  SetGender("female");  
  SetMorality(-50);
  SetCurrency("rupies", random(100));
  SetAction(15, ({
    "!speak beware the coming of a bloody Holy War.",
    "!speak I see great prejudice and hate. ",
    "!speak those who cannot forgive shall suffer. "
  }) );
  SetSpellBook( ([
    "boneshell"  : 100,
    "wound"      : 100,
    "acid blast" : 100
  ]) );
  SetCombatAction(50, ({ 
    "!cast boneshell",
    "!cast wound",
    "!cast acid blast"
  }) );
  SetInventory( ([
    C_OBJ + "dagger1" : "wield dagger",
    C_OBJ + "skirt1" : "wear skirt",
    C_OBJ + "blouse1" : "wear blouse",
  ]) );
  
}
