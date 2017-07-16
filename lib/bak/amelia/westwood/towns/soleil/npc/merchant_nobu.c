#include <lib.h>
#include "../soleil.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetTown("Soleil");
   SetProperty("soleilnoleave",1);
   SetGender("female");
   SetRace("halfling");
   SetClass("merchant");
   SetUniqueSkills( ([
                       "melee attack" : 1,
                       "fishing" : 1,
                       "bargaining" : 1,
                       "healing" : 1,
                       "armour working" : 2,
                       "wood working" : 2,
                       "textile working" : 3,
                  ]) );
   SetMorality(500);
   SetKeyName("Nobu");
   SetShort("Nobu the Merchant");
   SetId( ({ "nobu","merchant","leader" }) );
   SetAdjectives( ({ "nobu the" }) );
   SetLong("Long hair falls down Nobu the Merchant's "
           "back, carefully held back from her face "
           "and out of the way.  Her face is clean "
           "and sparkling, and she appears to be "
           "extravagantly rich.  Perhaps she "
           "would teach about merchants and help "
           "a beginner get started.");
   SetLevel(50);
   AddTalkResponse("help","!speak Would you like "
                   "some assistance?  I can teach "
                   "you to be a merchant.");
   SetAction(6, ({ "!speak I can help people who "
                   "want to be merchants.",
                   "!speak Soleil is a lovely "
                   "town, and it is wonderful that "
                   "the gelflings, halfings, and "
                   "muezzin all live here together.",
                   "!smile","!look","!whistle",
                   "!emote folds her hands together "
                   "and sighs contentedly.","!speak "
                   "it is so nice to not have to "
                   "travel all over to trade goods "
                   "as a merchant.","!speak Being "
                   "a merchant is great fun.",
                   "!speak ask  me to join merchants "
                   "if you want me to teach you to "
                   "be a merchant." }) );
   SetCombatAction(10, ({ "!speak Help! Oh, help!",
                          "!shout Help me!",
                          "!say Stop it at once!",
                          "!say I can't believe you're "
                          "attacking me, a helpless "
                          "halfling!","!trip", }) );
   SetFreeEquip( ([
                    "/std/obj/fishing/pole" : 1,
               ]) );
   SetMorality(400);
   RemoveLanguage("Eltherian");
   SetLanguage("Oiseau",1);
   SetPlayerTitles( ([
                       "newbie" : "the Apprentice Merchant of Soleil",
                       "mortal" : "the Trader",
                       "hm"     : "the Merchant",
                       "legend" : "the Opulent",
                       "avatar" : "the Filthy Rich",
                       "caravener" : "the Strong Merchant",
                       "evangelist" : "the Preaching Merchant",
                       "pirate" : "the Strong Merchant",
                       "oracle" : "the Wise Merchant",
                  ]) );
}
