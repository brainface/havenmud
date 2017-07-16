#include <lib.h>
#include <std.h>
#include "../grymxoria.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("cyra");
  SetShort("Cyra, a Captain of the Brute Squad");
  SetId(  ({
    "brute",
    "captain",
    "cyra",
    "grym_npc",
  })  );
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
  SetRace("nosferatu");
  SetMorality(-200);
  RemoveLanguage("Enlan");
  SetLanguage("Blaodric", 100, 1);
  SetClass("fighter");
  SetLimit(1);
  SetLevel(35);
  SetGender("female");
  SetFriends( ({ "grym_npc" })  );
  SetTown("Grymxoria");
  SetMorality(-1000);
  SetInventory(  ([
    G_OBJ + "nosf_lance"   : "wield lance",
    G_OBJ + "guard_armour" : "wear chainmail",
    G_OBJ + "nosf_sword"   : "wield sword",
  ]) );
  SetPlayerTitles(  ([
    "newbie" : "the Brute",
    "mortal" : "Footsoldier $N of the Grymxorian Brute Squad", 
    "hm"     : "Captain $N of the Grymxorian Brute Squad",
    "legend" : "Commander $N of the Grymxorian Brute Squad", 
    "avatar" : "General $N, Leader of the Grymxorian Brute Squad", 
    "enchanter" : "the Arch-Mage of the Brute Squad", 
    "cleric" : "the Maniacal Taskmaster of the Dark Goddess",
    "necromancer" : "the Unhallowed Tormenter of the Dark Goddess",
  ]) );
  SetFreeEquip(  ([
    STD_HACK + "wood_axe"     : 1,
  ]) );
}

	
