#include <lib.h>
#include "../soleil.h"
inherit LIB_SENTIENT;

static void create() {
   sentient::create();
   SetProperty("soleilnoleave",1);
   SetTown("Soleil");
   SetReligion("Eclat","Eclat");
   SetWander(20);
   SetKeyName("student");
   SetShort("a music student");
   SetId( ({ "student","bard" }) );
   SetAdjectives( ({ "music" }) );
   SetLong("This music student wanders around, "
           "happy to be an Eclatish chorist "
           "studying in the beautiful city "
           "of Soleil.");
   if(random(2)) { SetGender("male"); }
   else { SetGender("female"); }
   SetRace("muezzin");
   SetClass("bard");
   SetSkill("healing",1,1);
   SetSkill("faith",1,1);
   SetLevel(10+random(5));
   SetSongBook( ([
                   "exultant tintinnabulatin" : 100,
                   "harmonic shield" : 100,
                   "spiccato" : 100,
                   "joyous cacophony" : 100,
              ]) );
   SetAction(5, ({ "!sing exultant tintinnabulation",
                   "!sing harmonic shield",
                   "!emote sings a lovely ballad.",
                   "!emote laughs.","!emote smiles.",
                   "!say It's a beautiful town!", }) );
   SetCombatAction(40, ({ "!sing joyous cacophony",
                          "!sing spiccato",
                          "!say Help!","!say Stop "
                          "that!","!shout Help!",
                          "!sing spiccato" }) );
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
