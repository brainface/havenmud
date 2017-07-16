//  A bard leader for Malv  //
//  by Alessandra 9/04       //

#include <lib.h>
#include <std.h>
#include <../mal.h>
inherit LIB_LEADER;

static void create(){
  ::create();

  SetKeyName("darany");
  SetShort("Darany the Siren's Song");
  SetId( ({"bard", "darany"}) );
  SetAdjectives("");
  SetLong(
     "Darany is a masterful songstress, her voice soothing and "
     "bewitching. Her eyes are like large pools of black liquid and "
     "her raven hair falls smoothly down her back. She has a twinkle "
     "in her eye and her deep red lips are constantly curved into a "
     "seductive smile. Around her slender neck hangs an amulet, which "
     "looks as though it is only half of the original piece. She could "
     "possibly help those who seek the lifestyle of a traveling bard."
     );
  SetRace("dark-elf");
  SetGender("female");
  SetReligion("Soirin");
  SetTown("Malveillant");
  SetClass("bard");
  SetLevel(42);
  SetCurrency("roni", 1000);
  SetInventory( ([
     MAL_OBJ + "darany_blouse" : wear blouse,     
     MAL_OBJ + "darany_skirt" : wear skirt,       
     MAL_OBJ + "knee_boots" : wear boots,         
     MAL_OBJ + "etched_dagger" : wield dagger,     
     ]) );
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
     "newbie" : "the Amatuer Song Smith",
     "mortal" : "the Arcane Lyricist",
     "hm"     : "the Enthralling Song Weaver",
     "legend" : "the Salacious Orator",
     "avatar" : "the Wanton Sonneter of Euphonies",
     "cleric" : "the Entrancing Choralist of Malveillant",
     ]) );
  SetFreeEquip( ([
     STD_INSTRUMENTS "lyre" : 1,
     STD_KNIFE       "small_knife" : 2,    
     ]) );
  SetFriends( ({"lucen"}) );
  SetAction(1,({
     "!emote smiles seductively.",
     "!emote flirts with Lucen.",
    }) );
  SetCombatAction(5,({
     "!emote slips easily past your clumsy attack.",
     "!sing famine",
     "!sing ballad of winter",
     "!sing ballad of autumn",
     "!sing glory of the mage",
     "!sing lunar ballad",
     }) );
}

