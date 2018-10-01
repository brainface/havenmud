#include <lib.h>
#include <daemons.h>
#include "../defs.h"
inherit LIB_BARKEEP;

static void create() {
 ::create();
 SetKeyName("Frederick");
 SetShort("Frederick, a tobacco merchant");
 SetId( ({ "frederick", "merchant", "Frederick" }) );
 SetAdjectives( ({ "tobacco", "human"}) );
 SetRace("human");
 SetGender("male");
 SetClass("merchant");
 SetLimit(1);
 SetReligion("Aetarin");
 SetBaseLanguage("Avera");
 SetLevel(30);
 SetMorality(75);
 SetLong(
    "Frederick has an oval face with freckles scattered on "
    "his thin cheeks. He is a middle-aged man with salt "
    "and pepper hair and a slightly receding hairline. "
    "His body skin reveals he is not in the sun often, and "
    "probably selling his wares full time. He is wearing "
    "his daily work uniform which looks a bit worn from use."
  );
 SetAction(12, ({
    "!say Welcome to the Averath Tobacco Emporium.",
    "!say If you feel you want to purchase my fine wares, talk to me.",
    "!say Why not purchase an Averath Averan? The finest cigar brand in town!",
    "!say I adore the warm weather here.",
    "!emote patiently waits for a customer to browse his wares.",
    "!say How about a fine pipe for later, after a hearty meal?",
    "!say Stop in and have a cup of coffee while you find what you're looking for.",
    "!say My pipes disappear after they burn out and end up in the barrel.",
    "!light first pipe",
  }) );
   SetLocalCurrency("ducats");
   SetCurrency("ducats", 80);
   SetInventory( ([
        SHOP_OBJ "fshirt"   : "wear shirt",
        SHOP_OBJ "fpants"   : "wear pants",
        SHOP_OBJ "wpipe"    : 3,
  ]) );
 SetMenuItems( ([
    "a fine cigar"          : SHOP_OBJ  "cigar",
    "an averan brand cigar" : SHOP_OBJ  "acigar",
    "a manmade wooden pipe" : SHOP_OBJ  "wpipe",
    "a cheap corncob pipe"  : SHOP_OBJ  "cpipe",
    "a special blend cigar" : SHOP_OBJ  "scigar",
    "a fine cup of coffee"  : SHOP_OBJ  "coffee",
    ]) );
 }
