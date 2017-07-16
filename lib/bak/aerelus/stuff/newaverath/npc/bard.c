#include <lib.h>
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Catherine Alliaume");
  SetId( ({ "catherine", "alliaume", "bard", "averath_person" }) );
  SetShort("Catherine Alliaume the Professional Singer");
  SetLong(
    "Cathering Alliaume the Professional Singer is a bard of great reknown "
    "throughout all of Averath. Her morose demeanor suggests she has seen "
    "much sadness to sing about. She could teach anyone that was interested "
    "in becoming a bard."
  );
  SetAdjectives( ({ "professional" }) );
  
  SetRace("human");
  SetGender("female");
  SetBaseLanguage("Avera");
  SetReligion("Aetarin");  
  AddCurrency("ducats", random(100));
  SetMorality(0);
  SetClass("bard");
  SetLevel(100);
  
  SetSongBook( ([
      "tingling song" : 100,
      "shielding song" : 100,
      "harmonic shield" : 100,
      "harpy's shriek" : 100,
      "song of sorrow" : 100,
      "ballad of autumn" : 100,
      "ballad of spring" : 100,
      "ballad of winter" : 100,
      "ballad of summer" : 100,
      "glory of the mage" : 100,
      "angel whisper" : 100,
      "debutant aria" : 100,
      "pianississimo" : 100,
      "spiccato" : 100,
      "banshee scream" : 100,
      "lunar ballad" : 100,
      "solar ballad" : 100,
    ]) );
  SetPlayerTitles( ([
      "newbie" : "the Lowly Busker",
      "mortal" : "the Amateur Minstrel",
      "hm"     : "the Songsmith",
      "legend" : "the Inspired Weaver of Songs",
      "avatar" : "the Voice of Averath",
      ]) );
  SetFreeEquipment( ([
    "/std/obj/instruments/lyre" : 1,
    "/std/weapon/small_knife" : 2,    
    ]) );
  SetTown("Averath");
  SetRestrictRace(1);
 }
