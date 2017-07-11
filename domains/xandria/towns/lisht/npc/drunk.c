
//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   switch(random(3)) {

      case 0:
      SetKeyName("drunk");
      SetShort("a drunk gnoll woman");
      SetId( ({ "woman","drunk" }) );
      SetAdjectives( ({ "drunk" }) );
      SetLong("The woman is a lewd harlot. She's had way too "
              "much to drink, and she's flaunting her goodies "
              "to everyone within eyeshot. Her unfocused, bleary "
              "eyes occasionally flutter kittenishly toward "
              "various people and objects in the room. ");
      SetRace("gnoll");
      SetClass("rogue");
      SetGender("female");
      SetLevel(1 + random(2));
      SetBaseLanguage("Rehshai");
      break;

      case 1:
      SetKeyName("drunk");
      SetShort("a drunk gnoll man");
      SetId( ({ "gnoll","drunk" }) );
      SetAdjectives( ({ "drunk" }) );
      SetLong("This tired, sad gnoll seems to be having quite "
              "a life. Maybe it's his wife, or his job, but "
              "he appears more miserable by the moment. ");
      SetRace("gnoll");
      SetClass("rogue");
      SetGender("male");
      SetLevel(4);
      SetBaseLanguage("Rehshai");
      break;

      case 2:
      SetKeyName("drunk");
      SetShort("a drunk old man");
      SetId( ({ "drunk","gnoll", "man" }) );
      SetAdjectives( ({ "drunk","old" }) );
      SetLong("This man has been steadily drinking himself "
              "to death these past few years. He holds his "
              "alcohol only slightly better than other drunks, "
              "but he also seems sad and uncoordinated. ");
      SetRace("gnoll");
      SetClass("rogue");
      SetGender("male");
      SetLevel(9);
      SetBaseLanguage("Rehshai");
      break;
   }
   SetInventory( ([
                    LISHT_OBJ + "sweetbeer" : 2,
                   LISHT_OBJ + "shenti" : "wear shenti",
               ]) );
   if(GetGender() != "female") {
      SetAction(2, ({ "!groan","!moan","!emote stumbles.",
                      "!say What say we go back to my place...",
                      "!emote flutters her eyelashes at you.",
                      "!emote drinks some beer.","!emote spills "
                      "her beer on herself.","!giggle",
                      "!laugh","!woo", "!say Woooo!",
                      "!say You from around here, partner?",
                      "!say That's hot. ", "!say Mmmmm.." }) );
   }
   else {
      SetAction(3, ({ "!cry.","!mutter.", "!grumble",
                      "!emote slurs his words together.",
                      "!emote drinks his beer.","!emote "
                      "spills half his beer.","!say Barkeep!  "
                      "Another!","!say More beer!","!kick",
                      "!say Life is worthless. Stupid life.",
                      "!say What are YOU looking at?" }) );
   }
   SetMorality(-200);
   AddAlcohol(50);
   SetCombatAction(10, ({ "!emote stumbles.","!emote falls down and "
                    "tries to stand awkwardly","!emote burps.",
                    "!emote looks confused.","!speak Hey, what're "
                    "ya doing that for?", }) );
   SetFriends( ({"hathor","drunk","patron","citizen"}) );
}
