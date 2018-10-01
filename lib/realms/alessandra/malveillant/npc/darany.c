//  A bard leader for Malv  //
//  by Alessandra 9/04       //

#include <lib.h>
#include <std.h>
#include "../mal.h"
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
  SetMorality(-200);
  SetGender("female");
  SetReligion("Soirin","Soirin");
  SetTown("Malveillant");
  SetClass("bard");
  SetLevel(42);
  SetCurrency("roni", 1000);
  SetInventory( ([
     MAL_OBJ + "/clothing/darany_blouse" : "wear blouse",     
     MAL_OBJ + "/clothing/darany_skirt" : "wear skirt",       
     MAL_OBJ + "/clothing/knee_boots" : "wear boots",         
     MAL_OBJ + "/weapons/etched_dagger" : "wield dagger",   
     STD_INSTRUMENTS "lyre" : 1,	  
     ]) );
  SetSongBook( ([
     "famine" : 100,
     "ballad of winter" : 100,
     "glory of the mage" : 100,
     "angel whisper" : 100,
     "aria of fire" : 100,
     "lunar ballad" : 100,
     ]) );
  SetPlayerTitles( ([
     "newbie" : "the Amateur Songsmith",
     "mortal" : "the Arcane Lyricist",
     "hm"     : "the Enthralling Song Weaver",
     "legend" : "the Salacious Orator",
     "avatar" : "the Wanton Sonneter of Euphonies",
     "cleric" : "the Entrancing Choralist of Malveillant",
     "rogue"  : "the Dissolute Serenader",
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
  SetCombatAction(55,({
     "!emote slips easily past your clumsy attack.",
     "!sing famine",
     "!sing ballad of winter",
     "!sing aria of fire",
     "!sing glory of the mage",
     "!sing lunar ballad",
     }) );
}

