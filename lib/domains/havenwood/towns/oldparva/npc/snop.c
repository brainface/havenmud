#include <lib.h>
#include "parva.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetTown("Parva");
   SetProperty("parvanoleave",1);
   SetKeyName("Snop");
   SetShort("Snop, Pons' twin brother");
   SetId( ({ "Snop","brother","twin" }) );
   SetAdjectives( ({ "snop","pons","twin","brother" }) );
   SetLong("Snop is very similar to his brother pons, if "
           "just a touch fatter, though not much.  They "
           "share everything, even the store, though "
           "Pons does most of the actual work.  Snop just "
           "lounges around and, if someone wants to be a "
           "merchant, sets them up with their basic skills.");
   SetClass("merchant");
   SetGender("male");
   SetRace("human");
   SetLevel(40);
   SetInventory( ([
                    P_OBJ + "/pants_pons" : "wear pants",
                    P_OBJ + "/shirt_pons" : "wear shirt",
                    P_OBJ + "/boots_pons" : "wear slippers",
               ]) );
   SetUniqueSkills( ([
                       "knife combat" : 1,
                       "fishing" : 1,
                       "bargaining" : 1,
                       "wood working" : 1,
                       "weapon smithing" : 2,
                       "natural working" : 2,
                       "textile working" : 3,
                  ]) );
   SetPlayerTitles( ([
                       "newbie"  : "the Parva Fisherman Who Catches Tiny Fish",
                       "mortal"  : "the Great Parva Catcher of Fish",
                       "hm"      : "the Master Fish-Catcher of Parva",
                       "legend"  : "the Master of the Sea",
                       "avatar"  : "the Grand Fisherman of the East",
                       "fighter" : "the Mariner of Parva",
                       "rogue"   : "the Parva Catcher of Fish",
                  ]) );
   SetFreeEquip( ([
                    "/std/obj/fishing/pole" : 1,
                    P_OBJ + "/freeknife" : 1,
               ]) );
   SetLanguage("Enlan",100,1);
   SetMorality(-10);
   RemoveLanguage("Eltherian");
   SetFriends( ({ "Pons" }) );
   SetAction(2, ({ "!whistle","!emote looks bored.",
                   "!emote pretends to do work for a moment.",
                   "!emote lounges.","!emote smiles lazily.",
                   "!emote pauses in his inactivitely to "
                   "stretch a little." }) );
}
