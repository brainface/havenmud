#include <lib.h>
#include "../glim.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("Rallor");
   SetShort("Rallor the Voice of Allegory");
   SetId( ({ "rallor",  "bard" }) );
   SetAdjectives( ({ }) );
   SetLimit(1);
   SetLong("Rallor is the master storyteller "
           "of Glimmerdin and is quite old. Over the years he "
           "has accumulated much knowledge of lore and stories, "
           "both true and untrue, along with many songs. His gray "
           "is meticulously braided and white with age.");
   SetGender("male");
   SetClass("bard");
   SetRace("dwarf");
   SetLevel(50);
   SetRestrictRace(1);
   SetMorality(200);
   SetPlayerTitles( ([
                       "newbie" : "the Student of Dwarven Stories", 
                       "mortal" : "the Dwarven Storyteller",
                       "hm"     : "the Greater Dwarven Storyteller",
                       "legend" : "the Voice of the Past",
                       "avatar" : "the Master of Lore and Stories",
                       "cleric" : "the Intoner of the Kylin Church",
                  ]) );
   SetSongBook( ([
      "harpy shriek" : 1,
      ]) );
   SetAction(1, ({ "!emote yawns.", 
     "!emote hums a little tune.",
      }) );
   SetCombatAction(15, ({ "!say Critics!",
      "!say Stuff your foul mouth with my fist, fool, and trouble "
        "the air no more with your obsene presence!",   
      "!sing harpy shriek" }) );
   SetFreeEquipment( ([
                    "/std/obj/instruments/drum" : 1,
                    "/std/weapon/small_knife" : 1,
               ]) );
}
