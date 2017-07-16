#include <lib.h>
inherit LIB_LEADER;
#include "../soleil.h"

static void create() {
   leader::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Sauras");
   SetShort("Sauras, the Soleil Enchanter");
   SetLong("Sauras has a calm, reserved air about her, but she has an "
           "intelligent look behind her eyes.  She looks young, but "
           "those years have made her wise.");
   SetGender("female");
   SetRace("muezzin");
   SetClass("enchanter");
   SetLevel(50);
   SetTown("Soleil");
   SetReligion("Eclat","Eclat");
   SetInventory( ([
      S_OBJ + "pole_short" : "wield pole in left hand",
      ]) );
   SetFreeEquip( ([
      S_OBJ + "pole_short_newbie" : 1,
      ]) );
   SetPlayerTitles( ([
      "newbie"      : "the Studious Child of Soleil",
      "mortal"      : "the Enlightened Enchanter of Soleil",
      "high mortal" : "the Creative",
      "legend"      : "the Talented Creator of Soleil",
      "avatar"      : "the Wise One of Soleil",
      ]) );
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","shaggy dog","Sorgan","Foret","Fait",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum",
                  "Acclima" }) );
   SetSpellBook( ([
   	 "paralysis"         : 100,
   	 "chain lightning"   : 100,
   	 "mesmer barrier"    : 100,
   	 	]) );
   SetCombatAction(80, ({ 
   	 "!cast paralysis",
   	 "!cast chain lightning",
   	 "!cast mesmer barrier",
   	 }) );
   	 
   SetMorality(100);
   //SetNoJoin(1);
}
