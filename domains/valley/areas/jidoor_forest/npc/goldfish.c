/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: goldfish.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1997
// Abstract: This is a goldfish caught from the
//           stream in the Jidoor Forest.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_FISH;

static void create() {
  fish::create();
  SetKeyName("goldfish");
  SetFood("domains/valley/areas/jidoor_forest/meal/meal_goldfish");
  SetShort("a big goldfish");
  SetLong("This is a big goldfish caught from a stream in the Jidoor "
          "Forest. It looks like it would make a good meal.");
  SetMass(20);
  SetId( ({ "fish", "goldfish" }) );
  }
