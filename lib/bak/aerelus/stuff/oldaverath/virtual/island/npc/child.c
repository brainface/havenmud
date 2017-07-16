#include <lib.h>
#include <damage_types.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {

  ::create();
  SetKeyName("child");
  SetShort("a small sulky child");
  SetId( ({ "child" }) );
  SetAdjectives( ({ "small", "sulky" }) );
  SetLong("The face of this small child is downcast, and tears "
           "occasionally fall down her cheek.");
  SetRace("human");
  SetGender("female");
  SetLevel(1);
  SetCombatAction(3, ({
    "!say Waaaaaaaaaa! Why are you so mean to me!",
    "!say You big bully!",
    "!say Mommy!",
    }) );
  SetAction(3, ({
    "!emote sniffles pitifully.",
      "!emote wipes a tear from her eye.",
    "!say Noone will play wif me...",
    }) );
  SetMorality(50);
}
