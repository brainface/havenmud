#include <lib.h>
#include <std.h>
#include "parva.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("Choeur");
   SetTown("Parva");
   SetShort("Choeur, the bard");
   SetId( ({ "bard","choeur" }) );
   SetLong("Choeur is a short, large human "
           "with jolly, flushed cheeks and "
           "sharp blue eyes.  He has strong "
           "lungs and a powerful voice."); 
   SetGender("male");
   SetClass("bard");
   SetRace("human");
   SetLevel(45);
   SetPlayerTitles( ([
                       "newbie" : "the Parvan Debutant",
                       "mortal" : "the Singer by the Sea",
                       "hm"     : "the Parvan Storyteller",
                       "legend" : "the Enchanting Performer",
                       "avatar" : "the Entertainer",
                       "cleric" : "the Chorist of Parva",
                  ]) );
   SetSongBook( ([
                   "spiccato" : 100,
                   "glory of the mage" : 100,
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
                   "angel whisper" : 100,
                   "debutant aria" : 100,
              ]) );
   SetAction(10, ({ "!sing solar ballad",
                    "!sing lunar ballad",
                    "!sing glory of the mage",
                    "!sing harmonic shield",
                    "!whistle","!emote humms.",
                    "!emote sings a little ditty "
                    "to himself.","!say Come learn "
                    "to sing from me!" }) );
   SetCombatAction(30, ({ "!sing spiccato",
                          "!sing debutant aria",
                          "!sing angel whisper to me",
                          "!sing banshee scream",
                          "!sing ballad of autumn",
                          "!sing ballad of summer",
                          "!sing ballad of winter",
                          "!sing harpy shriek",
                          "!sing tingling song",
                          "!shout Help!  Help!",
                          "!say Get out of here!",
                     }) );
   SetFreeEquip( ([
                   STD_INSTRUMENTS "mandolin" : 1,
                    P_OBJ + "/freeknife" : 1,
               ]) );
}
