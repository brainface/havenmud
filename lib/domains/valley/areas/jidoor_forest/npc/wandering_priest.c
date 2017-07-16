/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: wandering_priest.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 23rd, 1998
// Abstract: This is a wandering priest of the Magildans who shouts word 
//           of the magildan faith to all those who can hear him.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   September 17th, 1998 - Magildan yells changed to 
//                                          reflect change in the religion.
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_SENTIENT;
#include "../jidoor_forest.h"
static void create() 
  {
  sentient::create();
  SetKeyName("priest");
  SetId( ({ "priest" }) );
  SetShort("a wandering priest");
  SetAdjectives( ({ "a wandering" }) );
  SetLong("This priest wanders the lands spreading word of the "
          "Magildan faith.  He appears friendly but looks like "
          "he would be a difficult fight if attacked.");
  SetMorality(400);
  SetRace("sprite");
  SetClass("priest");
  SetLevel(10+random(10));
  SetGender("male");
  SetAction(5, ({ 
        "!yell Believe in the power of magic!",
        "!yell Zaxan Zimtafarous had blessed us all!",
        "!yell magic is the ultimate power in the universe!",
        "!yell Those who do not succumb to the power of magic "
           "lead poor lives, for the magic is in us all!",
        "!yell See the true power of magic, join the faith of "
           "the magildans!",
        "!yell Flock to the city of Jidoor, Zaxan Zimtafarous shall guide "
           "us all!"
             }));
 
  SetSpellBook( ([ 
        "bless" : 100,
        ]) );
  SetCombatAction(25, ({ 
        "!cast bless on white mace",
        "!cast bless on me",
        }) );

  SetInventory( ([ 
        d_obj + "/sandals" : "wear sandals",
        d_obj + "/white_mace" : "wield mace",
        d_obj + "/white_robe" : "wear robes",
        ]) );
  SetCurrency("rupies", random(300)+50);
  SetWander(4);
  SetLimit(4);
}
