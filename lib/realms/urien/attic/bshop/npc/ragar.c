
#include <lib.h>
#include <daemons.h>
#include "../defs.h"
inherit LIB_BARKEEP;

static void create() {
 ::create();
 SetKeyName("Ragar");
 SetShort("Ragar, the smoke vendor");
 SetId( ({ "ragar", "vendor", "Ragar" }) );
 SetAdjectives( ({ "smoke"}) );
 SetRace("human");
 SetGender("male");
 SetClass("merchant");
 SetLimit(1);
 SetReligion("kuthar");
 SetBaseLanguage("barian");
 SetLevel(30);
 SetMorality(5);
 SetLong(
    "Ragar has a very rugged appearance. His dark brown hair "
    "is matted and disheveled. A single bushy black brow rests above "
    "his dark-green sullen eyes. His broad shoulders are covered "
    "by an animal pelt which covers a good portion of his bare "
    "chest. He looks bored, as if he has been doing his duty "
    "for way too long."
  );
 SetAction(8, ({
    "!say Greetings, welcome to the Barian Smoke Hut.",
    "!say If you need anything to smoke, I'm your man.",
    "!say The herbs in the jungle are great for smoking.",
    "!say Only I, Ragar, know where these fine herbs grow.",
    "!say If you're looking for work, the herb runners usually come here.",
    "!emote taps his fingers against his dirk making a clicking noise.",
    "!say Have you ever tried the nectar drinks here in Baria?",
    "!sigh",
    
  }) );
   SetLocalCurrency("chits");
   SetCurrency("chits", 40);
   SetInventory( ([
        SHOP_OBJ "rsash"   : "wear sash",
        SHOP_OBJ "rdirk"   : "wield dirk",
  ]) );
 SetMenuItems( ([
    "a barian rough leaf" : SHOP_OBJ  "rleaf",
    "a ground bark roll"  : SHOP_OBJ  "bpwdr",
    "a whember leaf roll" : SHOP_OBJ  "wroll",
    "an imported cigar"   : SHOP_OBJ  "cigar",
    "a cup of nectar"     : SHOP_OBJ  "lnmug",
    ]) );
 }
