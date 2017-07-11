#include <lib.h>
#include "../vergoth.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("guest");
  SetRace("half-elf");
  SetId( ({ "guest" }) );
  SetClass("rogue");
  SetGender("female");
  SetShort("a guest of the tower");
  SetLevel(4);
  SetLong("The guest is about five and a half feet tall.  She is very dark "
	"skinned and appears to be partly elven in heritage.  She is very "
	"calm looking and appears to pose no threat.");
  SetInventory( ([
	V_OBJ + "dress" : "wear dress",
    ]) );
  SetCurrency("imperials", 150);
  SetMorality(300);
  SetCombatAction(30, ({ 
     "!emote attempts to behead.",
     "!emote swings wildly about.",
     "!emote runs in small circles.",
     "!emote prepares to cast a spell.",
    }) );
  SetAction(10, ({
    "!emote twirls around in a dress.",
    "!emote walks about the room.",
   }) );
  SetDie( "The guest wonders what she did to deserve this." ); 
}