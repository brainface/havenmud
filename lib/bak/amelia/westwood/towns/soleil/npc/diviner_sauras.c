#include <lib.h>
inherit LIB_LEADER;
#include "../soleil.h"

static void create() {
   leader::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Sauras");
   SetShort("Sauras, the Soleil Diviner");
   SetLong("Sauras has a calm, reserved air about her, but she has an "
           "intelligent look behind her eyes.  She looks young, but "
           "those years have made her wise.");
   SetGender("female");
   SetRace("muezzin");
   SetClass("diviner");
   SetLevel(49);
   SetTown("Soleil");
   SetReligion("Eclat","Eclatish");
   SetInventory( ([
                    S_OBJ + "pole_short" : "wield pole in left hand",
               ]) );
   SetFreeEquip( ([
                    S_OBJ + "pole_short_newbie" : 1,
               ]) );
   SetPlayerTitles( ([
                       "newbie"      : "the Studious Child of Soleil",
                       "mortal"      : "the Enlightened Diviner of Soleil",
                       "high mortal" : "the Discerning",
                       "legend"      : "the Profound Sage of Soleil",
                       "avatar"      : "the Wise One of Soleil",
                  ]) );
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","shaggy dog","Sorgan","Foret","Fait",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum",
                  "Acclima" }) );
   SetSpellBook( ([
                    "detect magic" : 100,
                    "discern magic" : 100,
                    "research history" : 100,
                    "telepathy" : 100,                    
                    "dimension door" : 100,
                    "ethereal touch" : 100,
                    "lock area" : 100,
                    "lock person" : 100,
                    "teleport" : 100,
               ]) );
   SetMorality(100);
SetTaughtSpheres( ({"magical divination","magical necromancy","magical planar"}) );
  SetNoJoin(1);
}
