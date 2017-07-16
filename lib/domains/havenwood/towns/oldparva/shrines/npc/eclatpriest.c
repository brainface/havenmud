#include <lib.h>
#include "../../parva.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetReligion("Eclat","Eclat");
   SetProperty("parvanoleave",1);
   SetTown("Parva");
   SetKeyName("Abijah");
   SetShort("Abijah, an Eclatish priest");
   SetId( ({ "abijah","priest","eclat","muezzin" }) );
   SetAdjectives( ({ "eclatish" }) );
   SetLong("Abijah's fur is dusty and she looks terribly tired, but "
           "appears commited to working until she collapses.  "
           "Her manner is calm and unassuming, and her smile is "
           "cheerful and inviting.  She has a strong, joyous "
           "warmth that few can match.");
   SetGender("female");
   RemoveLanguage("Oiseau");
   SetLanguage("Enlan",100,1);
   SetRace("muezzin");
   SetPlayerTitles( ([
                       "newbie" : "the Young Parvan Eclat",
                       "mortal" : "the Merry Eclatish Cleric",
                       "hm"     : "the Jovial Missionary",
                       "legend" : "the Joyous Wonder",
                       "avatar" : "the Sunny Spark of Joy",
                       "bard"   : "the Choirist of Happiness",
                       "merchant" : "the Merry Merchant",
                       "barbarian" : "the Parvan Defender of Joy",
                       "fighter" : "the Opposer of Unhappiness",
                       "cavalier" : "the Paladin of Joy",
                  ]) );
   SetClass("priest");
   SetUniqueSkills( ([
                       "healing" : 1,
                       "melee combat" : 1,
                       "enchantment" : 1,
                       "divination" : 2,
                       "blunt combat" : 3,
                       "bargaining" : 2,
                       "slash combat" : 3,
                       "melee combat" : 3,
                       "fishing" : 2,
                       "armour smithing" : 4,
                       "weapon smithing" : 4,
                       "leather working" : 4,
                       "metal working" : 4,
                  ]) );
   SetLevel(37);
   SetSpellBook( ([
                    "create flower" : 100,
                    "disperse protections" : 100,
                    "create rose" : 100,
                    "cheerful obstacles" : 100,
                    "create golden ball" : 100,
                    "create meza" : 100,
                    "harm evil" : 100,
                    "divine magic" : 100,
                    "divine magic fully" : 100,
                    "bless" : 100,
                    "blessed water" : 100,
                    "create sacred candle" : 100,
                    "divine mana" : 100,
                    "cure blindness" : 100,
                    "dispel poison" : 100,
                    "mend" : 100,
                    "revive" : 100,
                    "harmony wind" : 100,
               ]) );
   SetAction(10, ({ "!cast mend on first citizen","!cast harmony "
                    "wind","!comfort citizen","!emote cleans up "
                    "a bench.","!say Good cheer to all!",
                    "!smile","!laugh","!giggle","!beam",
                    "!cast cheerful obstacles","!say Come all citizens "
                    "of Parva, and learn the way of joy!",
                    "!say A life of joy is magnificent.",
                    "!smile","!say Eclats are always here to help.",
                    "!say Parva could be such a beautiful town.",
                    "!say This land is beautiful.  If only we could "
                    "take the time to help it." }) );
   SetCombatAction(30, ({ "!cast mend on abijah","!cast harm evil",
                          "!say Help!","!shout Help me!",
                          "!trip","!trip","!shout Please, save me "
                          "someone!","!say You fiend!  Get away from "
                          "here!","!say Repent your evil ways and "
                          "start a new life!","!cast harm evil",
                          "!say You base creature!","!say You're a "
                          "depraved animal, fighting me thus!",
                          "!say Amoral beast!","!say Corrupt creature!",
                          "!say Leave me now!","!say Someone, help "
                          "me!","!say Stop this terrible act, brute!",
                          "!say You fiendish devil, get away and "
                          "leave the good and innocent in this world "
                          "alone!" }) );
}
