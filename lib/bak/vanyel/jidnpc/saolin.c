/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: saolin.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: February 2nd, 1998
// Abstract: Saolin Soceror Leader
// Revision History:  
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <std.h>

#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("Saolin");
   SetShort("Saolin the Wizard of War");
   SetLong("Saolin is a exceptionally strong sprite and is dressed in the "
          "traditional robes of the enchanter but she wields two very "
          "traditional weapons of a fighter.  She is one of Jidoor's "
          "greatest sorcerers and she looks exceptionally dangerous.");
   SetId( ({ "saolin", "enchanter","wizard","wizard of war",}) );
   SetRace("sprite");
   SetClass("fighter");
   SetGender("female");
   SetTown("Jidoor");
   SetStat("durability", 55);
   SetStat("strength", 55);
   SetSkill("evokation", 135, 1);
   SetSkill("enchantment", 135, 1);
   SetSkill("conjuring", 135, 1);
   SetFreeEquip( ([ 
      STD_HACK + "hand-axe" : 1, 
      STD_SLASH + "shortsword" : 1, 
   ]) );
   SetPlayerTitles( ([ 
      "fighter" : "the Wizard of War",
   ]) );
   SetLevel(45);
   SetMorality(25);
   SetSpellBook( ([
  /*1*/      "wards of light" : 100,
  /*2*/      "chain lightning" : 100,
                ]) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/enchanter_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
      STD_SLASH + "shortsword" : "wield sword",
      STD_HACK + "hand-axe" : "wield axe",
   ]) );
   SetAction(1, ({
      "!cast wards of light",
      "!speak A Sorcerer is an Enchanter who has learned the arts "
      "of war by becoming a Fighter as well.",
      "!speak I can teach you about Fighters.",
      "!grin casually",
   }) );
   SetCombatAction(5, ({
      "!cast wards of light",
      "!cast wards of light",
      "!cast wards of light",
      "!cast wards of light",
      "!cast wards of light",
      "!cast chain lightning",
      "!cast chain lightning",
   }) );
}

void eventJoin(object who, string args) {
  if (!(who->GetClass("enchanter"))) { 
          eventForce("speak I only teach the ways of the Fighter "
            "to those who have already begun their careers as "
            "Enchanters.  Go see Dolad first if you are interested "
            "in becoming a Enchanter and then return to me "
            "if you wish to become a Sorcerer.");
  return;
  }
  return leader::eventJoin(who, args);
}
