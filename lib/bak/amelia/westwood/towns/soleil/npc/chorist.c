#include <lib.h>
#include "../soleil.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetNoJoin(1);
   SetKeyName("Trill");
   SetShort("Trill, the Joyful Chorist");
   SetReligion("Eclat","Eclat");
   SetTown("Soleil");
   SetId( ({ "trill","chorist" }) );
   SetAdjectives( ({ "joyful" }) );
   SetLong("Trill is a skinny, medium-height "
           "Eclatish chorist.  She teaches "
           "the Eclatish hymns to other "
           "such chorists."); 
   SetGender("female");
   SetClass("bard");
   SetClass("cleric");
   SetUniqueSkills( ([
                       "healing" : 1,
                       "melee attack" : 1,
                       "enchantment" : 1,
                       "divination" : 2,
                       "blunt defense" : 3,
                       "bargaining" : 2,
                       "slash defense" : 3,
                       "melee defense" : 3,
                       "fishing" : 2,
                       "armour smithing" : 4,
                       "weapon smithing" : 4,
                       "leather working" : 4,
                       "metal working" : 4,
                  ]) );
   SetRace("muezzin");
   SetLevel(45);
   SetRestrictRace(1);
   SetPlayerTitles( ([
                       "newbie" : "the Muezzin Debutant",
                       "mortal" : "the Scintillante Singer",
                       "hm"     : "the Performer of Scherzo",
                       "legend" : "the Spianato Singer",
                       "avatar" : "the Entertainer",
                       "cleric" : "the Joyous Chorist",
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
                   "shielding song" : 100,
                   "banshee scream" : 100,
                   "pianississimo" : 100,
                   "angel whisper" : 100,
                   "debutant aria" : 100,
                   "exultant tintinnabulation" : 100,
                   "merry euphony" : 100,
                   "joyous cacophony" : 100,
              ]) );
   SetAction(10, ({ "!sing solar ballad",
                    "!sing lunar ballad",
                    "!sing glory of the mage",
                    "!sing harmonic shield",
                    "!whistle","!emote humms.",
                    "!emote sings a little ditty "
                    "to herself.","!emote looks "
                    "joyous.","!sing exultant "
                    "tintinnabulation" }) );
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
                          "!sing merry euphony to me",
                          "!sing joyous cacophony",
                     }) );
}
