#include <lib.h>
#include <vendor_types.h>
#include "../soleil.h"
inherit LIB_VENDOR;

static void create() {
   vendor::create();
   SetProperty("soleilnoleave",1);
   SetTown("Soleil");
   SetKeyName("Clef");
   SetShort("Clef, the music store vendor");
   SetId( ({ "vendor","clef" }) );
   SetAdjectives( ({ "music","store" }) );
   SetLong("Clef has played music since he "
           "was very young, and decided to "
           "start making and selling instruments "
           "to all the musical bards and chorists "
           "of Kailie.");
   SetGender("male");
   SetRace("muezzin");
   SetClass("bard");
   SetSkill("healing",1,1);
   SetSkill("bargaining",1,1);
   SetSkill("faith",1,1);
   SetLevel(35);
   SetVendorType(VT_INSTRUMENT);
   SetLocalCurrency("cuicui");
   SetStorageRoom(S_ROOM + "str_mus");
   SetMaxSingleItem(15);
   SetMorality(500);
   SetSongBook( ([
                   "exultant tintinnabulatin" : 100,
                   "harmonic shield" : 100,
                   "spiccato" : 100,
                   "joyous cacophony" : 100,
                   "merry euphony" : 100,
                   "ballad of autumn" : 100,
                   "ballad of summer" : 100,
              ]) );
   SetAction(10, ({ "!say I make some great "
                    "instruments, but I have "
                    "some for beginners, too.",
                    "!say I sell instruments.",
                    "!sing exultant tintinnabulation",
                    "!sing harmonic shield",
                    "!say Come buy some instruments!",
                    "!say Let me show you my wares.",
                    "!say This is a beautiful "
                    "town.", }) );
   SetCombatAction(40, ({ "!shout Help me!",
                    "!say Fiend!  Get away from me!",
                    "!say Stop this dreadful act!",
                    "!sing spiccato","!sing "
                    "joyous cacophony","!sing ballad "
                    "of autumn","!sing ballad of "
                    "summer","!sing merry euphony to "
                    "me" }) );
   switch(random(5)) {
      case 0:
      SetInventory( ([ "/std/obj/instruments/drum" : 1 ]) );
      break;
      case 1:
      SetInventory( ([ "/std/obj/instruments/fife" : 1 ]) );
      break;
      case 2:
      SetInventory( ([ "/std/obj/instruments/lyre" : 1 ]) );
      break;
      case 3:
      SetInventory( ([ "/std/obj/instruments/mandolin" : 1 ]) );
      break;
      case 4:
      SetInventory( ([ "/std/obj/instruments/recorder" : 1 ]) );
      break;
   }
}
