/* bartender.c for Black Horse Inn
   Atrus@Haven
   19MAY2013
*/

#include <lib.h> 
#include "../bhi.h"
inherit LIB_BARKEEP;
static void create() {
    barkeep::create();
    SetKeyName("raven");
    SetId( ( "bartender" ) );
    SetAdjectives( ({"black haired"}) );
    SetShort("Raven the black haired bartender");
    SetLong(
       "This tall, beautiful, black haired woman is named Raven. Her face "
       "rarely misses her smile, and her teeth are clean and straight. Her body "
       "is slender and sleek with muscular forearms and rough hands. Raven's "
       "job is simple, keep everyone in the bar happy, and she does it very well. "
       "She has a confident look about her that suggests caution. "
       "You can <ask raven to browse> to see what is one sale today."
       );
    SetRace("lamrani");
    SetGender("female");
    SetClass("merchant");
    SetLevel(random(45) + 10);
    SetInventory( ([
        BHI_OBJ "blouse" : "wear blouse",
        BHI_OBJ "slacks" : "wear slacks",
        BHI_OBJ "rag" : "wield rag",
      ]) ); 
    SetMorality(-400);
    SetSkill("brawling", 100, 1);
    SetSkill("melee combat", 100, 1);
    SetAction(random(16), ({ "!yell Damnit, Al I need more ale!",
            "!emote wipes the sweat from her brow.",
            "!smile",
            "!emote takes an order.",
            "!emote wipes down the bar.",
            "!emote walks around the room smiling and looking to the needs of others.",
            "!emote whispers something your direction that you didn't quite catch.",
            "!emote walks away.",
             }) );
  SetLocalCurrency("imperials");
  SetMenuItems( ([
    "stew" : BHI_OBJ + "stew",
    "ale" : BHI_OBJ + "ale",
    "steak" : BHI_OBJ + "steak",
    "eggs" : BHI_OBJ + "eggs",
    "lager" : BHI_OBJ + "lager",
    "bread" : BHI_OBJ + "bread",
  ]) );
}
