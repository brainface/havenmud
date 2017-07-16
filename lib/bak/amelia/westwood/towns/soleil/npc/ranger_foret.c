#include <lib.h>
#include <std.h>
inherit LIB_LEADER;
#include "../soleil.h"

static void create() {
   leader::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Foret");
   SetShort("Foret, the Soleil Ranger");
   SetId( ({ "foret","ranger" }) );
   SetAdjectives( ({ "soleil" }) );
   SetLong("Foret is the ranger of Soleil, and is always willing to "
           "introduce others to his art.  He is tall and sturdy on "
           "his feet, and looks as if he knows his way around.");
   SetRace("muezzin");
   SetClass("ranger");
   SetLevel(47);
   SetGender("male");
   SetReligion("Eclat","Eclatish");
   SetTown("Soleil");
   SetPlayerTitles( ([
                       "newbie"      : "the Trainee",
                       "mortal"      : "the Gentle WestWood Woodsman",
                       "high mortal" : "the Kind Soleil Forester",
                       "legend"      : "the WestWood Naturalist",
                       "avatar"      : "the Ranger of Soleil",
                       "nomad"       : "the Nomadic WestWood Brawn",
                  ]) );
   SetFreeEquip( ([
                    STD_PROJECTILE + "bow_long_newbie" : 1,
               ]) );
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",   
                  "Soleil citizen","shaggy dog","Sorgan",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum" }) );
   SetInventory( ([
                    S_OBJ + "bow_long" : "wield long bow",
               ]) );
   SetSpellBook( ([
                    "barkskin"       : 100,
                    "feast"          : 100,
                    "natural shield" : 100,
                    "summon animal"  : 100,
                    "tangle"         : 100,
                    "tend wounds"    : 100,
                    "transmorph"     : 100,
               ]) );
   SetCombatAction(20, ({ "!cast natural shield","!cast summon animal",
                         "!cast tangle" }) );
   SetMorality(200);
SetTaughtSpheres( ({"natural"}) );
}
