/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: lauranna.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 23rd, 1998
// Abstract: This is P'alirith's wife.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_NPC;
#include "../jidoor_forest.h"
static void create() 
  {
  npc::create();
  SetKeyName("lauranna");
  SetShort("Lauranna the Battle Enchanter");
  SetId( ({ "lauranna", "enchanter","sprite" }) );
  SetAdjectives( ({ "battle","aged" }) );
  SetLong("Although aged, this sprite's beauty is still evident. She looks "
          "about fourty year old but her age is becoming. She has long "
          "silver hair and green eyes. She looks busy cleaning but she "
          "seems distracted.");
  SetRace("sprite");
  SetMorality(1000);
  SetGender("female");
  SetStat("durability", 40);
  SetClass("enchanter");
  SetLevel(30);
  SetSpellBook( ([
           "sphere"    : 100,
           "paralysis" : 100,
           "shock"     : 100,
           ]) );
  SetCurrency("rupies", 150 + random(200));
  SetInventory( ([
           d_obj + "/dress"       : "wear dress",
           d_obj + "/cedar_staff" : "wield staff",
           d_obj + "/sandals"     : "wear sandals",
           d_obj + "/spellbook"   : 1,
//           d_obj + "/bag"   : 1,
           d_obj + "/ribbon"      : "wear ribbon",
           ]) );
  SetAction(20, ({
           "!emote cleans the countertop.",
           "!emote looks out the window.",
           "!peer up",
           "!look at table",
           "!smile tired",
           "!emote cleans the table.",
           "!speak are you here to see P'alirith?",
           "!speak Now where did I put the scissors?",
           "!speak Now where did I put the cutting board?",
           "!speak P'alirith is upstairs if you wish to see him.",
           "!speak I'm so glad my husband has retired."
           }) );
  SetCombatAction(40, ({ 
           "!cast sphere",
           "!cast paralysis",
           "!cast shock",
           }) );
  }
