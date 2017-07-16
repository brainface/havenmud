// Amelia@Haven

#include <lib.h>
inherit LIB_LEADER;
#include "../soleil.h"

static void create() {
   leader::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Oppugno");
   SetShort("Oppugno the fighter");
   SetId( ({ "oppugno the fighter","oppugno","fighter" }) );
   SetLong("Oppugno flexes his muscles to himself, pausing on "
           "occasion to swing his arms around or do other exercises "
           "and stretches.  He seems very full of himself, but the "
           "size of his muscles make it seem unwise to challenge that "
           "smugness.");
   SetRace("muezzin");
   SetClass("fighter");
   SetLevel(37);
   SetGender("male");
   SetPlayerTitles( ([
                       "newbie"      : "the Soleil Fighting Trainee",
                       "mortal"      : "the Soleil Fighter",
                       "high mortal" : "the Fierce Soleil Fighter",
                       "legend"      : "the Soleil Legend-Fighter",
                       "avatar"      : "the Warrior of Soleil",
                       "cleric"      : "the Faithful Soleil Soldier",
                       "barbarian"   : "the Combatent of Soleil",
                       "merchant"    : "the Affluent Soldier of Soleil",
                       "enchanter"   : "the Quarrelsome Charmer of Soleil",
                       "rogue"       : "the Affluent Soldier of Soleil",
                  ]) );
   SetFreeEquip( ([
                    S_OBJ + "sword_freebie" : 1,                    
               ]) );
   SetMorality(95);
   SetReligion("Eclat","Eclatish");
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","shaggy dog","Sorgan",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum" }) );
   SetInventory( ([
                    S_OBJ + "sword_training" : "wield sword in right hand",
               ]) );
}
