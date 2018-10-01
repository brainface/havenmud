#include <lib.h>
#include <std.h>
#include "../grymxoria.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("cyra");
  SetShort("Cyra, a Captain of the Brute Squad");
  SetId( ({
    "brute", "captain", "cyra", "grym_npc",
  }) );
  SetAdjectives( ({ "captain", "brute", "squad" }) );
  SetLong(
    "Cyra wears the blood red livery of the Grymxorian brute squad. "
    "She doesn't appear to be all that different than the average "
    "citizen, yet one must be leery, for members of the Grymxorian "
    "brute squad must battle their superior officer in a bout to the "
    "death to attain their rank. A captain is second only to the "
    "commander of the squad, so Cyra must know quite "
    "a bit about what it means to be a brute. Perhaps "
    "one could ask her." 
  );
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Blaodric", 100, 1);
  SetGender("female");
  SetMorality(-200);
  SetClass("fighter");
  SetLevel(35);
  SetTown("Grymxoria");
  SetInventory( ([
    G_OBJ + "nosf_lance"   : "wield lance",
    G_OBJ + "guard_armour" : "wear chainmail",
    G_OBJ + "nosf_sword"   : "wield sword",
  ]) );
  SetPlayerTitles( ([
    "newbie" : "the Brute",
    "mortal" : "the Member of the Grymxorian Brute Squad",
    "hm"     : "Captain $N of the Grymxorian Brute Squad",
    "legend" : "the Legendary Grymxorian Brute",
    "avatar" : "Commander $N of the Grymxorian Brute Squad",
    "enchanter" : "the Sorcerer of Grymxoria",
    "cleric" : "the Grymxorian Monk",
  ]) );
  SetFreeEquip( ([
    STD_WEAPON "hack/wood-axe" : 1,
    STD_WEAPON "slash/shortsword" : 1,
  ]) );
  SetFriends( ({ "grym_npc" }) );
  SetLimit(1);
}

	
