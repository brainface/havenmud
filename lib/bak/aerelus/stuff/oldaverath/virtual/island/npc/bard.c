/*  A bard for Haven Town */
#include <lib.h>
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("athurin");
  SetShort("Athurin the Fair, a storyteller");
  SetId( ({ "athurin", "storyteller", "bard" }) );
  SetAdjectives( ({ "fair" }) );
  SetRace("human");
  SetRestrictRace(1);
  SetClass("bard");
  SetGender("male");
  SetLevel(38);
  SetCurrency("ducats", 200);
  SetLong("Athurin the Fair is a bard of great reknown throughout "
          "all of Kailie. His calm demeanor suggests he has seen "
          "much to sing about, both happy and sad. He could teach "
          "anyone that was interested in becoming a bard.");
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
      "newbie" : "the Soft Storyteller",
      "mortal" : "the Storyteller of Averath",
      "hm"      : "the SongMaster",
      "legend"   : "the Bardic Legend",
      "avatar"   : "the Truly Divine SongMaster",
      ]) );
  SetFreeEquipment( ([
    "/std/obj/instruments/lyre" : 1,
    "/std/weapon/small_knife" : 2,    
    ]) );
  SetTown("Averath");
 }
