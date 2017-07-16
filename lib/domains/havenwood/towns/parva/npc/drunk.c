#include <lib.h>
#include "../parva.h"
inherit LIB_TOWNGUARD;

static void create() {
   ::create();
   SetTown("Parva");
   switch(random(3)) {

      case 0:
      SetKeyName("drunk");
      SetShort("a drunk halfling");
      SetId( ({ "halfling","drunk" }) );
      SetAdjectives( ({ "drunk","sad","depressed" }) );
      SetLong("The halfling looks sad and depressed.  His "
              "beard is scraggly and dirty; food sticks in it "
              "and it looks wet from beer.  The rest of him is "
              "beer-stained, as well.  His eyes are unfocused "
              "and his body seems to be deteriorating slowly from "
              "the strong, fit form of his youth into old age.");
      SetRace("halfling");
      SetClass("sailor");
      
      SetGender("male");
      SetLevel(random(3)+1);
      SetBaseLanguage("Enlan"); 
      break;

      case 1:
      SetKeyName("drunk");
      SetShort("a drunk human");
      SetId( ({ "human","drunk" }) );
      SetAdjectives( ({ "human","drunk" }) );
      SetLong("Long blond hair straggles down around the thin, "
              "sad, and tired face of this drunk human.  He "
              "is so miserable looking that he seems to not "
              "even want to lift his head.");
      SetRace("human");
      SetClass("rogue");
      SetGender("male");
      SetLevel(4);
      break;

      case 2:
      SetKeyName("drunk");
      SetShort("a drunk gelfling");
      SetId( ({ "drunk","gelfling" }) );
      SetAdjectives( ({ "drunk","gelfling" }) );
      SetLong("Splattered with spilled beer, the gelfling's "
              "eyes glow dully as he cheerfully drinks "
              "himself into bliss.  He appears to be "
              "generally fit and strong, though lacking "
              "severely in coordination.");
      SetRace("gelfling");
      SetClass("rogue");
      SetGender("male");
      SetLevel(10);
      SetLanguage("Enlan",100,1);
      RemoveLanguage("Eltherian");
      break;
   }
   SetInventory( ([
     PARVA_OBJ  "inn_grog" : 1,
     ]) );
   if(GetRace() != "gelfling") {
      SetAction(2, ({ "!emote moans.","!groan","!whine","!emote complains.",
                      "!say I can't believe my life is like this!",
                      "!mutter","!cry","!emote despairs.",
                      "!emote drinks some beer.","!emote spills "
                      "his beer on himself.","!whimper",
                      "!say How can I go on?","!say Oh, Oh!",
                      "!say I hate life!","!say life is miserable.",
                      "!say Fishing is a terrible profession.",
                      "!say harvesting clams and oysters, hauling "
                      "up crab pots--it sucks!","!sigh","!sigh" }) );
   }
   else {
      SetAction(3, ({ "!emote whistles clumsily.","!emote stumbles.",
                      "!emote slurs his words together.",
                      "!emote drinks his beer.","!emote "
                      "spills half his beer.","!say Barkeep!  "
                      "Another!","!say More beer!","!sing",
                      "!chuckle","!giggle","!laugh","!smile",
                      "!say Wooo!","!say Life's just great, isn't "
                      "it?","!say Woo!" }) );
   }
   SetMorality(-100);
   AddAlcohol(50);
   SetCombatAction(10, ({ "!emote stumbles.","!emote falls down and "
                    "tries to stand awkwardly","!emote burps.",
                    "!emote looks confused.","!speak Hey, what're "
                    "ya doing that for?", }) );
   SetFriends( ({"minkin","drunk","pecunia","arpachshad","citizen"}) );
}
