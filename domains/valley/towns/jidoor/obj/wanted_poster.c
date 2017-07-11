/*  Zaxan Zimtafarous@haven
 *    - May 29, 1999
 */
#include <lib.h>
#include "../jidoor.h"
inherit LIB_ITEM;
#include "../wanted.h"

int eventReadPoster(string msg, string msgtwo, string lang, object who);

static void create() {
  item::create();
  SetKeyName("poster");
  SetPreventGet("It is nailed firmly to the wall.");
  SetMass(50);
  SetShort("a wanted poster");
  SetLong("The poster is a piece of velium nailed to the wall.  There is "
          "some writing on it.");
  SetRead("default", (: eventReadPoster :) );
  }

int eventReadPoster(string msg, string msgtwo, string lang, object who) {

who = this_player();
lang = "Sprith";
msg = "Jidoor City Wanted Poster\n";

foreach(string person in Wanted) {
     msg += ""+capitalize(person) + " is wanted for " +
         Crimes[person] + ".\n";
      }

   if (this_player()->GetSleeping()) { 
   message("whatever", "You are asleep!", who);
   return 0;
   }

   if((this_player()->GetLanguageLevel(lang)) > 0) {
   msg = translate(msg, this_player()->GetLanguageLevel(lang));
   message("whatever", "The poster reads: \n"+msg+"", who);
    return 1;
   }
   else {
   message("whatever", "You do not recognize the language.", who);
   return 0;
   }
}
