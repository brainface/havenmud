//
//  Ayla the medicine woman
//  kyla 11-97
//  Modified by Rhakz - Angel Cazares
//  Date: 10/13/98 
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_HEALER;

static void create() {
  healer::create();
  SetKeyName("ayla");
  SetShort("Ayla the Medicine Woman");
  SetId( ({ "ayla", "woman","medicine woman","ayla the medicine woman"}) );
  SetLong("This woman is quite tall and beautiful. A white aura "
          "surrounds her body, transmitting peace to everyone "
          "near her. She could tend to someone's wounds if "
          "paid the right amount."
         );
  SetAdjectives( ({"tall","beautiful"}) );
  SetGender("female");
  SetMorality(random(200) - 100);
  SetRace("human");
  SetClass("shaman");
  SetSkill("fire magic",1,2);
  SetLevel(90);
  SetStat("wisdom", 10000, 1);
  SetTown("Baria");
  
  SetCombatAction(80, ({ 
     "!cast flamestrike",
     "!cast wither",
     "!cast umbral shield",
  	 }) );
  SetAction(15, ({
  	 "!cast umbral shield",
  	 }) );
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
  ]) );
  SetLocalCurrency("chits");
  SetCurrency( ([ 
     "chits" : random(250) + 250,
  ]) );
}

