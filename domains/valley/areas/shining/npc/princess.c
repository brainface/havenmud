#include <lib.h>
#include "../sf.h"

inherit LIB_NPC;
#include "greeter.h"
static void create() {
   ::create();
   SetKeyName("laria");
   SetShort("Laria, princess of the Shining forest");
   SetId( ({ "laria", "princess"}) );
   SetMorality(0);
   SetClass("bard");
   SetLevel(125);
   SetGender("female");
   SetRace("sprite");
   SetLong("Laria the princess stands in the middle of the room. "
           "Her body is covered in possibly the most elegant and "
           "beautiful dress known to the lands. Its silky look "
           "and glistening accents are amazing. She has a beautiful "
           "tiara sitting perfectly on her head. On her feet are a "
           "pair of small pearl colored slippers. In her hand is a "
           "small golden harp. Her amazingly green eyes seem to be "
           "looking around contently. ");
   SetCurrency("rupies", random(7000)+500);
   SetLanguage("Sprith", 100, 1);
   SetAction(1, ({"!speak Hello and welcome to the roots of mother nature!",
                  "!speak Please do not harm the forest, it is all that I "
                  "know and love!", }) );
   SetReligion("Magildan");
   SetStat("intelligence", 400);
   SetStat("wisdom", 400);
   SetStat("charisma", 400);
   SetStat("durability", 125);
   SetStat("strength", 125);
   SetSkill("enchantment", 320 ,1);
   SetSkill("instrumental music", 320 ,1);
   SetSkill("vocal music", 320 ,1);
   SetSkill("faith", 300 ,1);
   SetSkill("evokation", 320 ,1);
   SetSkill("blunt combat", 300 ,1);
   SetSkill("conjuring", 320,1);
   SetInventory( ([ 
      SF_OBJ + "/helm/princess_tiara" : "wear tiara",
      SF_OBJ + "/clothing/princess_dress" : "wear dress",
      SF_OBJ + "/weapon/princess_harp" : "wield harp",
      SF_OBJ + "/armour/princess_shoe" : "wear slippers",
      SF_OBJ + "pkey" : 1,
      ]) );

   SetSongBook( ([
                "star strike" : 100,
                "star fall" : 100,
                "aria of angels" : 100,
                "mesmerize audience" : 100,
                "song of forgotten battles" : 100,
               ]) );
   SetSpellBook( ([
                "temporal barrier" : 100,
                "divine power" : 100,
               ]) );
   SetFirstCommands(({
                "sing song of forgotten battles",
                "sing divine power",
                "cast temporal barrier",
                "cast temporal barrier",
                "cast temporal barrier",
                "sing aria of angels",
                   }));
   SetCombatAction(15, ({
                "!sing mesmerize audience",
                "!sing star strike",
                "!yell Ahh, Music to my ears!",
                "!sing star fall",
                }) );
   SetGreet("Greetings and welcome to the Shining Forest!");
}
