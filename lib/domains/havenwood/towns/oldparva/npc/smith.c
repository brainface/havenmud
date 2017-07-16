#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "parva.h"
inherit LIB_VENDOR;

static void create() {
   vendor::create();
   SetProperty("parvanoleave",1);
   SetTown("Parva");
   SetKeyName("Er Shelah");
   SetShort("Er Shelah, the smith of Parva");
   SetId( ({ "er","shelah","smith","parva" }) );
   SetAdjectives( ({ "er","shelah","smith","smith of" }) );
   SetLong("Er Shelah is a strange old gelfling with muscular "
           "arms and a seedy look.  He looks lazy and slothful, "
           "but is probably challenging to fight.");
   SetGender("male");
   SetRace("gelfling");
   SetStat("strength",70,1);
   SetClass("rogue");
   SetLevel(25);
   SetMeleeAttackString("fists");
   SetMeleeDamageType(BLUNT);
   SetSkill("bargaining",15,1);
   SetStorageRoom(P_ROOM + "/str_smith");
   SetVendorType(VT_WEAPON);
   SetLocalCurrency("oros");
   SetMaxSingleItem(20);
   SetMorality(-200);
   RemoveLanguage("Eltherian");
   SetLanguage("Enlan",100,1);
   AddAlcohol(50);
   SetAction(5, ({ "!burp","!laugh","!emote looks confused.",
                   "!say 'Sgreat town, Parva is!",
                   "!emote nods off." }) );
   SetCombatAction(20, ({ "!trip","!trip","!trip","!say Pond "
                          "scum!","!say Jerk!","!say Idiot!",
                          "!say Get outta my shop!", }) );
   SetInventory( ([
                    "/std/clothing/shirt/drab_shirt" : "wear shirt",
                    "/std/clothing/pant/drab_pants" : "wear pants",
               ]) );
}
