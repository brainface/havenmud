#include <lib.h>
#include "../path.h"
#include <std.h>
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("josef");
  SetRace("halfling");
 
  SetTown("Lloryk");
  SetClass("fighter"); 
  SetLevel(20);
  SetShort("Josef Varis, Guard Captain of the Shire");
  SetId( ({ "josef", "guard", "captain", "varis", }) );
  SetAdjectives( ({ "josef", "guard", "captain" }) );
  SetLong("Josef Varis leads the Shire Defense Forces. "
          "He is a small but burly halfling with a large, "
          "bushy mustache.  His swagger depicts a halfling "
          "that knows he is in charge.");
  SetGender("male");
  SetCurrency("rounds", 100);
  SetMorality(-500);
  SetLimit(1);
  SetFreeEquip( ([
    STD_WEAPON "slash/shortsword" : 1,
    STD_WEAPON "hack/hand-axe"    : 1,
    STD_ARMOUR "shield/small_wooden" : 1,
    ]) );
  SetInventory( ([ 
    LLORYK + "obj/chainmail.c" : "wear chainmail",
    LLORYK + "obj/pike.c" : "wield pike",
    LLORYK + "obj/breeches.c" : "wear breeches",
    LLORYK + "obj/helm.c" : "wear helm",
    LLORYK + "obj/boots.c" : "wear boots",
    LLORYK + "obj/gauntlets.c" : 2, 	
    ]) );
  SetFirstCommands( ({
  	"wear 1st gauntlet on right hand",
  	"wear 1st gauntlet on left hand",
    }) );
  SetPlayerTitles( ([
    "newbie" : "the Conscript of the Shire",
    "mortal" : "the Shire Guard",
    "hm"     : "the Veteran Shire Guard",
    "legend" : "the Legendary Shire Guard",
    ]) );
  SetAction(3, ({
  	"!speak You could ask me to join fighters.",
  	"!speak Left, Right, Left, Right.",
  	"!speak Down with the Imperialist Lizardmen!",
  	}) );
}