/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: fountain.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: Nov 1st, 1998
// Abstract: The fountain in the study of the Jidoormage Hall.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetProperty("history", "The fountain was brought here in the year one "
                         "hundred and eight and was created by a magic "
                         "wizard who chose to remain anonymous for her "
                         "work.",);
  SetProperty("magic", "The water in the fountain is not magical, but "
                      "the fountain itself is enchanted with powerful "
                      "enchantment and planar magic." );
  SetKeyName("fountain");
  SetShort("a abstract looking fountain");
  SetMealType(MEAL_DRINK);
  SetId( ({ "fountain", "water" }) );
  SetAdjectives( ({"abstract looking", "abstract"}) );
  SetLong("The abstract creation of an unknown wizard lies here. Water "
          "pours from a spout looking thing at the top and falls down "
          "towards the floor but not before magically disappearing from "
          "existance. Where the water flows from, or where it goes "
          "it entirely a mystery.");
  SetPreventGet("%^MAGENTA%^%^BOLD%^The fountain refuses to be moved, as "
                "if protected by magical wards.%^RESET%^");
  SetPortions(-1);
  SetStrength(15);
  SetMealMessages( ({ "$N feel refreshed after a drink from the abstract "
                      "fountain.",
                      "$N looks refreshed after drinking from the abstract "
                      "fountain.",
                     }) );
}
 
