// Torak@Haven 7/20/2016

#include <lib.h>
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Rene");
   SetShort("Rene the Acrobat");
   SetId( ({ "rene the acrobat","rene","acrobat", }) );
   SetLong("Rene is a slim and trim muezzin with silky soft milky white fur. "
           "She moves with grace and dignity as she walks, the tone of her muscles "
           "visible beneath her fur coat.");
   SetRace("muezzin");
   SetTown("Soleil");
   SetClass("acrobat");
   SetLevel(40);
   SetGender("female");
   SetPlayerTitles( ([
     "newbie"       : "the Handstand Apprentice",
     "mortal"       : "the Acrobatic Initiate of Soleil",
     "high mortal"  : "the Gymnast of Soleil",
     "legend"       : "the Legendary Acrobat of Soleil",
     "avatar"       : "the Parkour Artist",
     "demi-god"     : "the Parkour Master of Soleil",
     "epic paragon" : "the Grand Master of Acrobatics",
     "ranger"       : "the Freerunner of the Forest",
     "enchanter"    : "the Cirque du Soleil Artist",
     "bard"         : "the Master of Capoeira",
     "cleric"       : "the Ecstatic Aerialist",
   ]) );
   SetFreeEquip( ([
     "/std/weapon/pole/staff" : 1,
     "/std/armour/free_armour/small/oldvest" : 1,
   ]) );
   SetMorality(195);
   SetReligion("Eclat","Eclat");
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","shaggy dog","Sorgan",
                  "Dedan", "Sauras", "Harmony", "Melody", "Foret",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum" }) );
   SetInventory( ([
     "/std/weapon/pole/staff.c" : "wield staff",
     "/std/armour/free_armour/small/oldvest.c" : "wear vest",
   ]) );
   SetAction(5, ({
     "!emote does an amazing pole stand atop her staff.",
     "!emote jumps high into the air.",
     "!emote runs in place.",
     "!speak I would love to teach you!",
   }) );
   SetCombatAction(20, ({
     "!disorient",
   }) );
   SetWander(15);
   SetLimit(1);

}

