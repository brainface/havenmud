//  A rogue leader for Malv  //
//  by Alessandra 9/04       //

#include <lib.h>
#include <std.h>
#include <../mal.h>
inherit LIB_LEADER;

static void create(){
  ::create();

  SetKeyName("lucen");
  SetShort("Lucen the Shadow Stalker");
  SetId( ({"rogue", "lucen"}) );
  SetAdjectives("stalker");
  SetLong(
     "Lucen's midnight black hair is pulled back neatly and "
     "bound at the nape of his neck. His eyes are a vibrant dark "
     "shade of violet and crackle with amusement at his surroundings. "
     "He has an aura of confidence and arrogance about him, but his "
     "smile is utterly disarming. Around his neck hangs an amulet, "
     "which looks as though it is only half of the original piece. "
     "He is a man of many talents, and could probably help guide "
     "those without a chosen path."
     );
  SetRace("dark-elf");
  SetGender("male");
  SetReligion("Soirin");
  SetTown("Malveillant");
  SetClass("rogue");
  SetLevel(52);
  SetCurrency("roni", 1000);
  SetInventory( ([
     MAL_OBJ + "elf_tunic" : wear tunic,        
     MAL_OBJ + "elf_leggings" : wear leggings,  
     MAL_OBJ + "g_boots" : wear boots,          
     MAL_OBJ + "etched_dagger" : wield dagger,   
     ]) );
  SetPlayerTitles( ([
     "newbie"      : "the Novice Purveyer of Purses",
     "mortal"      : "the Quickfinger",
     "hm"          : "the Covetous Miscreant",
     "legend"      : "the Lecherous Prowler of Shadows",
     "avatar"      : "the Depraved Shadow Reaver",
     "evoker"      : "the Adept Prestidigitator",
     "fighter"     : "the Dark Assassin of Malveillant",
     "necromancer" : "the Reaper of Souls",
     ]) );
  SetFreeEquip( ([
     STD_KNIFE + "small_knife" : 2,    
     ]) );
  SetFriends( ({"darany"}) );
  SetAction(1,({
     "!emote glances about the room slyly.",
     "!wink darany",
    }) );
  SetCombatAction(5,({
     "!emote lunges towards you menacingly.",
     "!say Attacking me was your last mistake!",
     "!emote slips easily past your clumsy attack.",
     }) );
}
