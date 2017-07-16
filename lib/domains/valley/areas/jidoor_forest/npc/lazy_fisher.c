/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: lazy_fisher.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1998
// Abstract: This lazy fisher fishes off the bridge on the forest.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_LEADER;
#include "../jidoor_forest.h"

static void create() 
  {
  leader::create();
  SetKeyName("fisher");
  SetShort("a lazy fisher");
  SetId( ({ "fisher", "lamrani" }) );
  SetLong("This lazy tall lamrani spends his days fishing in the "
          "Jidoor Forest.  He looks as though he doesn't mind company "
          "but he looks as though he could hold his own if attacked.");
  SetRace("lamrani");
  SetMorality(-300);
  SetAdjectives( ({ "lazy" }) );
  SetGender("male");
  SetClass("merchant");
  SetLevel(16+random(5));
  SetInventory( ([ 
         d_obj + "/rod" : "wield rod in right hand",
         d_obj + "/silk_slacks.c" : "wear slacks",
         d_obj + "/silk_shirt.c" : "wear shirt",
         d_obj + "/soft_boots.c" : "wear boots",
         d_obj + "/bulky_pack.c" : "wear pack on left arm",
         d_obj + "/fishing_hat.c" : "wear hat on head",
              ]) );
  SetSkill("blunt combat", 20, 1);
  SetSkill("evokation", 250, 1);
  SetSkill("natural magic", 250, 1);
  SetCurrency("rupies", 80 + random(180));
  SetSpellBook( ([ "animalistic protection" : 100
              ]) );  
  SetAction(10, ({ 
          "!fish with first pole",
          "!fish with first pole",
          "!fish with first pole",
          "The lazy fisher adjusts his fishing hat.",
          "The lazy fisher adjusts his fishing hat.",
          "!speak ah, I love the forest",
          "!speak Been to the town of Jidoor lately?",
          "!speak Have you met P'alirith?",
          "!speak They say the ancient dragon Naluris hid "
            "somewhere in Jidoor Forest after his last battle "
            "with P'alirith.  I don't know if there's any "
            "truth in that though.",
          "!speak I betcha some gelfling was here and "
            "caught all the fish.",
          "The lazy fisher mutters something about gelflings "
            "under his breath.",
          "!speak Soon time for me to head back to Jidoor I "
            "think.  Ah, what the heck, I'll stick around and "
            "fish some more.",
          "!sigh laz",
          "!sigh laz",
                }) );
  }
