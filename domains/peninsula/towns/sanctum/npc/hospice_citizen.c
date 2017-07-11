#include <lib.h>
#include "../rome.h"
#include <std.h>
#include <position.h>
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("citizen");
  SetRace("human");
  SetPosition(POSITION_LYING);
  SetParalyzed(100);
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetGender(random(2) ? "male" : "female");
  SetShort("a " + GetGender() + " citizen of Sanctum");
   SetId( ({ "citizen", "wander" }) );
  SetAdjectives( ({ GetGender() }) );
  SetMorality(50);
  SetClass("fighter");
  SetLong(
    "This person lies prostrate on one of the beds here.  Various "
     "possible reasons for being here could result in their condition."
  );
  
  SetSkill("melee combat", 1, 1);
  SetLevel(2);
  SetLimit(6);
  switch(random(3)) {
    case 0:
       AddBleeding(10);
       break;
    case 1:
        eventReceiveDamage(0, 4, 100, 1);
        break;
    case 2:
        new(STD_GERMS "cold")->eventInfect(this_object());
        break;
    }
}
