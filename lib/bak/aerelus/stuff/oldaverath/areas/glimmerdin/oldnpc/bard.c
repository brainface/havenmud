#include <lib.h>
#include "../glim.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("Rallor");
   SetShort("Rallor the Voice of Allegory");
   SetId( ({ "rallor", "storyteller", "bard" }) );
   SetAdjectives( ({ "old" }) );
  SetReligion("Kylin", "Kylin");
   SetLong("rallor is the master storyteller "
           "of Glimmerdin and is quite old.  Over the years he "
           "has accumulated much knowledge of lore and stories, "
           "both true and untrue, along with many songs.  His gray "
           "is meticulously braided and white with age.");
   SetGender("male");
   SetClass("bard");
   SetRace("dwarf");
   SetLevel(50);
  SetFriends( ({"tembeg", "rancor", "raal", "rallor", 
    "tabitha", "dwarf", "civak", "guard", "patrol", 
    "samik", "gracchus", "eredos", "dorscha", "bralor"}) );
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
                   "ballad of winter" : 100,
                   "harmonic shield" : 100,
                   "ballad of autumn" : 100,
                   "ballad of summer" : 100,
                   "song of sorrow" : 100,
                   "ballad of spring" : 100,
                   "solar ballad" : 100,
                   "lunar ballad" : 100,
                   "tingling song" : 100,
                   "shieldling song" : 100,
                   "banshee scream" : 100,
                   "pianississimo" : 100,
                   "harpy shriek"  : 100,
              ]) );
   SetAction(1, ({ "!emote yawns.", 
     "!emote hums a little tune.",
}) );
   SetCombatAction(15, ({ "!say Critics!",
      "!say Stuff your foul mouth with my fist, fool, and trouble "
        "the air no more with your obsene presence!",   
      "!sing harpy shriek" }) );
   SetFreeEquip( ([
                    "/std/obj/instruments/drum" : 1,
                    "/std/weapon/knife/freeknife" : 1,
               ]) );
}
