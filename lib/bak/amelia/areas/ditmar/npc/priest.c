// Add more spells as they get coded/apped/looked through/etc.

#include <lib.h>
inherit LIB_LEADER;
#include "ditmar.h"

void CheckFood();
void CheckFollowers();

static void create() {
   leader::create();
   SetTown("Ditmar");
   SetKeyName("Eric");
   SetShort("Eric, the Marn Priest"); 
   SetId( ({ "eric","priest" }) );
   SetAdjectives( ({ "marn" }) );
   SetLong("The Marn Priest has long, shaggy fur and an old, pious "
           "look about him.  Eric's hands drag on the cavern floor "
           "below him, and his eyes gleam as they notice the "
           "beautiful ice and rock formations that fill the temple.  "
           "Whenever her comes near one, he grows suddenly reverent "
           "and lifts his hands as if to caress the ice or rock, but "
           "puts them back down so as to protect the often delicate "
           "formations.");
   SetGender("male");
   SetRace("mar");
   SetClass("cleric");
   SetUniqueSkills( ([
                       "melee attack" : 1,
                       "evokation" : 1,
                       "enchantment" : 1,
                       "healing" : 2,
                       "stealth" : 2,
                  ]) );
   SetLevel(65);
   SetFreeEquip( ([
                    D_OBJ + "/freerobe" : 1,
               ]) );  
   SetMorality(135);
   SetPlayerTitles( ([
                       "newbie"   : "the Young Marn",
                       "mortal"   : "the Ice Worshipper",
                       "hm"       : "the Marn Cleric",
                       "legend"   : "the Ice Cleric",
                       "avatar"   : "the Glacier Walker",
                       "cavalier" : "the Ice Knight",
                       "fighter"  : "the Ice Fighter",
                  ]) );
   SetReligion("Marn","Marn");
   SetSpellBook( ([
                    "flaming arrow" : 100,
                    "disperse protections" : 100,
                    "holy shield" : 100,
                    "protect" : 100,
                    "bless" : 100,
                    "divine mana" : 100,
                    "blessed water" : 100,
                    "create detox potion" : 100,
                    "dispel poison" : 100,
                    "revive" : 100,
                    "resurrect" : 100,
                    "mend" : 100,
                    "limb regeneration" : 100,
               ]) );
   SetAction(3, ({ "!cast holy shield","!cast protect",
                   (:CheckFood:),(:CheckFollowers:) }) );
   SetCombatAction(30, ({ "!cast flaming arrow","!cast mend" }) );
   SetInventory( ([
                    D_OBJ + "/robe" : "wear robe",
               ]) );
}

void CheckFood() {
   if(this_object()->GetFood() < 1) {
      eventForce("cast divine mana");
      eventForce("eat mana");
      CheckFood();
      return;
   }
   if(this_object()->GetDrink() < 1) {
      eventForce("cast blessed water");
      eventForce("drink water");
      CheckFood();
      return;
   }
   return;
}

void CheckFollowers() {
   object me = this_object();
   object array envppl = all_inventory(environment(me));
   if(random(10)) return;
   foreach(object prsn in envppl) {
      if(!living(prsn)) envppl -= ({ prsn });
      if(prsn->GetReligion() != GetReligion()) envppl -= ({ prsn });
   }
   foreach(object prsn in envppl) {
      if(prsn->GetMaxHealth() > prsn->GetHealth() ) {
         eventForce("cast mend on " + prsn->GetKeyName());
         return;
      }
      if(prsn->GetMissingLimbs()) {
         if(sizeof(prsn->GetMissingLimbs()) == 1) {
            eventForce("cast regenerate limb on " + prsn->GetKeyName());
         }
         else {
            eventForce("cast regenerate limb on " + prsn->GetKeyName());
            eventForce(prsn->GetMissingLimbs()[0]);
         }
         return;
      }
   }
   return;
}