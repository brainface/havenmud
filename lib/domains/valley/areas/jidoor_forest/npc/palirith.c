/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: Palirith.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 23rd, 1998
// Abstract: P'alirith Battle Evoker of Jidoor Forest.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_NPC;
#include "../jidoor_forest.h"

static void create() {
  npc::create();
  SetKeyName("Palirith");
  SetShort("P'alirith the Battle Evoker");
  SetId( ({ "Palirith", "evoker","sprite" }) );
  SetAdjectives( ({ "battle","aged" }) );
  SetLong("This middle aged sprite appears very intelligent. He "
          "has short black hair and pure green eyes. He looks "
          "to be extremely wrapped in his work on constellations.");
  SetRace("sprite");
  SetMorality(1000);
  SetGender("male");
  SetStat("durability", 40);
  SetClass("evoker");
  SetLevel(80);
  SetSpellBook( ([
           "energy wall"    : 100,
           "disintegrate" : 100,
           "chain lightning"     : 100,
           ]) );
  SetCurrency("rupies", 5000 + random(2000));
  SetInventory( ([
           d_obj + "/darkred_robe"       : "wear robe",
           d_obj + "/regal_mace" : "wield mace",
           d_obj + "/sandals"     : "wear sandals",
           d_obj + "/spellbook"   : 1,
           d_obj + "/skullcap.c"   : "wear cap",
           ]) );
  SetAction(20, ({
           "!emote studies the constellations",
           "!emote looks up and out the window.",
           "!peer up",
           "!speak He will not get away so easily next time. It can't be fate th
at keeps us from killing each other! ",
           "!smile tired",
           "!emote studies the constellations",
           "!speak Lauranna you gotta come see this!",
           "!speak HURRY!",
           "!speak This is amazing!",
           "!speak Lauranna are you coming?",
           "!speak I'm gonna kill that dragon one of these days he will not cont
inue to get away!",
           }) );
  SetCombatAction(40, ({ 
           "!cast energy wall",
           "!cast disintegrate",
           "!cast chain lightning",
           }) );
}
