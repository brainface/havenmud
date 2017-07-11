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
           "happy to be an Eclatish bard "
           "studying in the beautiful city "
           "of Soleil.");
   if(random(2)) { SetGender("male"); }
   else { SetGender("female"); }
   SetRace("muezzin");
   SetClass("bard");
   SetSkill("healing",1,1);
   SetSkill("melee combat",1,2);
  
   SetLevel(10+random(5));
   SetSongBook( ([
      "drift"             : 100,
      "harmonic shield"   : 100,
      "glory of the mage" : 100,
      "staccato"          : 100,
      "pianissimo"        : 100,
      ]) );
   SetAction(5, ({ 
   		"!sing glory of the mage",
      "!sing harmonic shield",
      "!emote sings a lovely ballad.",
      "!emote laughs.",
      "!emote smiles.",
      "!say It's a beautiful town!", 
      }) );
   SetCombatAction(60, ({ 
   		"!sing glory of the mage",
      "!sing staccato",
      "!say Help!",
      "!say Stop that!",
      "!shout Help!",
      "!sing harmonic shield",
      "!sing drift",
      }) );
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
