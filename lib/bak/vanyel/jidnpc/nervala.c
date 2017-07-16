/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: nervala.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Sept 17th, 1998
// Abstract: Nevala the cleric of the Magildan Faith.
// Revision History: Orignally created by Zaxan@Haven 
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <daemons.h>
#include "../jidoor.h"

inherit LIB_LEADER;
static void create() {
 leader::create();
  SetKeyName("nervala");
  SetShort("Nervala the Magildan Mystic");
  SetId( ({ "nervala", "mystic" }) );
  SetAdjectives( ({ "magildan" }) );
  SetRace("sprite");
  SetNoMulti(1);
  SetClass("mystic");
  SetGender("female");
  SetLong("This gentle lady stands here as a general resource "
          "for the Magildan religion. She seems solemn and "
          "and consumed with thoughts about her faith.");
  SetMorality(60);
  SetLevel(75);
  SetReligion("Magildan","Magildan");
  SetSkill("melee attack", 35, 2);
  SetAction(1, ({
                  "!speak There are various spell teachers around "
                  "Jidoor who will help you with your magical "
                  "powers.",
                  "!speak Glory to the Gods of Energy!",
                  "!emote mutters a little prayer.",
                  "!emote mutters a little prayer.",
                  }) );
  SetReligion("Magildan","Magildan");
  SetTown("Jidoor");
  SetTaughtSpheres( ({"religion magildan", "magical healing", "magical",
         "magical evokation", "magical enchantment",
         "natural", "natural enchantment", "natural evokation",
          "natural healing",
/*
         "faith divination",
*/
    }) );
  SetSpellBook( ([
/*01*/    "create manastar" : 100,
/*02*/
/*03*/
/*04*/
/*05*/
/*06*/
/*07*/
/*08*/
/*09*/
/*10*/
/*11*/
/*12*/
/*13*/
/*14*/
/*15*/
/*16*/
/*17*/
/*18*/
/*19*/
/*20*/
              ]) );
  SetPlayerTitles( ([
     "newbie" : "the Acolyte Magildan Mystic",
     "mortal" : "the Magildan Mystic",
     "hm" : "the High Magildan Mystic",
     "legend" : "the Protector of Energy",
     "avatar" : "the Weaver of Energy",
     ]) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/mystic_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
  }
