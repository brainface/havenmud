/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: perch.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1997
// Abstract: This is a perch caught from the stream in the Jidoor Forest.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_FISH;

static void create() 
  {
  fish::create();
  SetKeyName("perch");
  SetFood("domains/valley/areas/jidoor_forest/meal/meal_perch");
  SetShort("a small perch");
  SetLong("This is a small perch caught from a stream in the Jidoor "
          "Forest It would make a good meal.");
  SetMass(35);
  SetId( ({ "fish", "perch" }) );
  }
