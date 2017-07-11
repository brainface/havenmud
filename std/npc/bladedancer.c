/*  A blade dancer combat style trainer */
#include <lib.h>
#include <std.h>
inherit LIB_STYLE_TRAINER;

static void create() {
  ::create();
  SetKeyName("vincent");

  SetId( ({ "vincent", "rogue" }) );
  SetAdjectives( ({ "viscious" }) );
  SetShort("a viscious looking rogue");
  SetLong(
    "Vincent is a rogue without abandon.  There is a slightly "
    "crazed look to his eye that shows he isn't quite all right."
    );
  SetRace("human");
  SetClass("rogue");
  SetCombatStyleLevel("blade dancing", 75);
  SetLevel(35);
  SetAction(5, ({
    "!say In my youth, I was the greatest blade dancer there was.",
    "!emote twirls his knife in his hands.",
    "!giggle maniacially",
    "!emote tosses his knife into the air and catches it again.",
     }) );
  SetCombatStyle("blade dancing");
  SetGender("male");
  SetCurrency("crystals", 500);
  SetMorality(-800);
  SetInventory( ([
    STD_CLOTHING + "boot/high_boots" : "wear boots",
    STD_CLOTHING + "pant/fencing_breeches" : "wear breeches",
    STD_WEAPON + "knife/pocket_knife" : "wield knife",
    ]) );
}
