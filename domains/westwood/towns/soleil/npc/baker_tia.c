#include <lib.h>
inherit LIB_BARKEEP;
#include "../soleil.h"

static void create() {
   barkeep::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Tia");
   SetShort("Tia, the young baker");
   SetId( ({ "baker","tia" }) );
   SetAdjectives( ({ "young" }) );
   SetLong("Youthful eyes are hidden in the neatly brushed fur "
           "of Tia, the daughter of the baker of Soleil.  She "
           "is already cooking, just like her mom.");
   SetGender("female");
   SetRace("muezzin");
   SetClass("merchant");
   SetLevel(2);
   SetLocalCurrency("cuicui");
   SetMenuItems( ([
                    "ginger cookie" : S_OBJ + "cookie_ginger",
                    "sugar cookie" : S_OBJ + "cookie_sugar",
                    "chocolate chip cookie" : S_OBJ + "cookie_chocochip",
                    "diet cookie" : S_OBJ + "cookie_diet",
               ]) );
   SetAction(8, ({
                   "!speak in oiseau Here, here!  Come buy some "
                      "cookies!  I don't charge much!",
                   "!speak in oiseau Delicious cookies, right here!  "
                      "Cheap prices!",
                   "!emote trots up to a passing muezzin and begs him "
                      "to buy a cookie.  He reaches into a pocket "
                      "and pulls out a few cuicui, handing them to "
                      "Tia, and walks off with a tasty sugar cookie.",
                   "!emote bounces around, looking for customers to "
                      "support her young business.",
              }) );
   AddTalkResponse("diet","I don't think the diet cookies are really "
                   "all that good.  They made me a little sick when "
                   "I tried one, but mom said that people would still "
                   "buy them from someone cute like me.");
   SetMorality(360);
   SetCurrency("cuicui", 20);
   SetReligion("Eclat","Eclat");
   SetFriends( ({ "Dulcae",
                  "shaggy dog","Sorgan",
                  "Iuvo","Fossis","Kiee","Miserum" }) );
}
