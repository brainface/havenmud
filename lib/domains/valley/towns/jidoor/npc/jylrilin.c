/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: jylrilin.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: February 2nd, 1998
// Abstract: Jylrilin Shadow Mage Leader
// Revision History:
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <std.h>
#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("Jylrilin");
   SetShort("Jylrilin, the Spellweaver in the Shadows");
   SetLong("Jylirin is dark and ominous looking.  He is obviously some kind "
           "of mage and judging by his attire, an evoker.  Something about "
           "him is different from other evokers.  His choice of weapons "
           "is an obvious clue. He doesn't appear to be very friendly nor "
           "good company but he is available to teach the arts of his "
           "second trade to those willing and capable to learn.");
   SetId( ({ "jylrilin", "evoker","rogue","spellweaver",
             "spellweaver in the shadows", "mage", "shadow mage",
             "jidoor_npc",
             }) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetClass("rogue");
   SetGender("male");
   SetTown("Jidoor");
   SetStat("durability", 65);
   SetStat("strength", 55);
   SetSkill("evokation", 135, 1);
   SetSkill("conjuring", 135, 1);
   SetFreeEquip( ([
      STD_KNIFE + "small_knife.c" : 1,
   ]) );
   SetPlayerTitles( ([
      "shadow mage" : "the Spellweaver in the Shadows",
   ]) );
   SetLevel(45);
   SetMorality(-100);
   SetSpellBook( ([
                        "energy field" : 100,
      "chain lightning" : 100,
      ]) );
   SetInventory( ([
      JID_OBJ + "/clothing/evoker_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
      STD_KNIFE + "stiletto" : "wield stiletto",
                ]) );
   SetAction(1, ({
      "!cast energy field",
      "!speak What do you want?",
      "!speak Listen, if you're just going to stand there, go "
      "somewhere else.",
      "!speak So you want me to tell you about the Shadow Mage do "
      "ya. Well, a Shadow Mage is an Evoker who has learned the arts "
      "of the Rogue.  We are deadly wielders of stealth and magic "
      "and if you have your path crossed by one of us, I suggest you "
      "stay well out of our way.",
      "!speak I could teach you about Rogues if you are already "
      "versed in the ways of the Evoker otherwise, go bug someone else.",
   }) );
   SetCombatAction(15, ({
      "!cast energy field",
      "!cast chain lightning",
      "!disorient",
   }) );
}

void eventJoin(object who, string args) {
  if (!(who->GetClass()=="evoker")) {
          eventForce("speak I only teach the ways of the Rogue "
            "to those who have already begun their careers as "
            "Evokers.  Go see Warlad or Ryl first if you are interested "
            "in becoming a Evoker and then return to me "
            "if you wish to become a Shadow Mage.");
  return;
  }
  return leader::eventJoin(who, args);
}

