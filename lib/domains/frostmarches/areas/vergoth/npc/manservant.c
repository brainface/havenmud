#include <lib.h>
#include "../vergoth.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("manservant");
  SetRace("human");
  SetId( ({ "manservant","servant" }) );
  SetClass("rogue");
  SetGender("male");
  SetShort("a manservant");
  SetLevel(1);
  SetLong("The manservant is a very mild looking man.  He stands about "
        "five feet and a few inches.  He is dressed in a black suit and "
        "is wearing a red bow tie.");
  SetInventory( ([ V_OBJ + "ring" : "wear ring on left hand" ]) );
  SetMorality(-300);
  SetCombatAction(30, ({ 
     "!emote swings wildly about.",
     "!emote loosens his bowtie.",
    }) );
  SetAction(10, ({
    "!say welcome to Vergoth",
    "!say please enjoy your stay",
    "!say the master will be down shortly",
    "!emote looks snootily down his nose.",
   }) );
  SetDie( "Manservant gasp out one last breathe as he dies." );
 }
