#include <lib.h>
#include "parva.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create() {
   vendor::create();
   SetProperty("parvanoleave",1);
   SetTown("Parva");
   SetKeyName("Pons");
   SetShort("Pons, the storekeeper");
   SetId( ({ "pons","storekeeper" }) );
   SetAdjectives( ({ "storekeeper","pons","the" }) );
   SetLong("Pons is a short, fat halfling who has a constant "
           "cold.  His nose is always running and "
           "red, as a result of his constant attempts to "
           "keep it clean.  His eyes are quick and bright, "
           "however, and his fingers nimble and swift.");
   SetGender("male");
   SetRace("halfling");
   SetClass("rogue");
   SetSkill("bargaining",1,1);
   SetLevel(19);
   SetVendorType(VT_TREASURE | VT_WEAPON | VT_ARMOUR | VT_MAGIC | VT_FISHING);
   SetLocalCurrency("oros");
   SetStorageRoom(P_ROOM + "/str");
   SetMaxSingleItem(15);
   SetMorality(-10);
   SetInventory( ([
                    P_OBJ + "/pants_pons" : "wear pants",
                    P_OBJ + "/shirt_pons" : "wear shirt",
                    P_OBJ + "/knife_pons" : "wield knife in right hand",
                    P_OBJ + "/boots_pons" : "wear slippers",
               ]) );
   SetAction(5, ({ "!speak I'll buy your weapons, armours, "
                   "treasures, and magic items, but most of "
                   "all, I want things that have to do with "
                   "fishing!","!speak Come here and buy the "
                   "best poles in Kailie!  We have cheap poles "
                   "for those just getting started, ones a "
                   "lot better for the more serious fisherman, "
                   "and amazing blue fishing poles--blessed with "
                   "magic and amazing!","!speak Come here and "
                   "examine my wares!","!emote pants with "
                   "exertion.","!speak Buy some fishing "
                   "poles!  Get more than one!  You can never "
                   "have too many!  You never know when one "
                   "will break!" }) );
   SetCombatAction(10, ({ "!yell Help!  Help me!","!yell Help me!  "
                    "I'm being attacked!","!yell Help!",
                    "!cry","!whimper","!speak I never should have "
                    "left the safe lands of central Kailie for "
                    "this awful pit of land on the coast!",
                    "!speak I hate the water!  I really hate " 
                    "fishing too!","!grovel","!speak Help!  "
                    "Help me!","!speak Don't kill me please "
                    "sir!","!speak Help me!  Please!" }) );
   SetLanguage("Enlan",100,1);
   RemoveLanguage("Eltherian");
   SetFriends( ({ "Snop" }) );
}


/* Approved by Ukla on Mon Oct 19 03:29:04 1998. */
