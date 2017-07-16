#include <lib.h>
#include <std.h>
#include "../soleil.h"
inherit LIB_LEADER;

static void create() {
   leader::create();

   SetKeyName("Trill");
   SetShort("Trill, the Joyful Chorist");
   SetReligion("Eclat","Eclat");
   SetTown("Soleil");
   SetId( ({ "trill","chorist" }) );
   SetAdjectives( ({ "joyful" }) );
   SetLong("Trill is a skinny, medium-height "
           "Eclatish chorist.  She teaches "
           "the Eclatish hymns to other "
           "such chorists."); 
   SetGender("female");
   SetRace("muezzin");
   SetClass("bard");
   SetUniqueSkills( ([
     ]) );
   SetFreeEquip( ([
     STD_INSTRUMENTS + "fife" : 1,
    ]) );
   
   SetLevel(145);
   SetRestrictRace(1);
   SetPlayerTitles( ([
     "newbie" : "the Muezzin Debutant",
     "mortal" : "the Scintillante Singer",
     "hm"     : "the Performer of Scherzo",
     "legend" : "the Spianato Singer",
     "avatar" : "the Entertainer",
     "cleric" : "the Joyous Chorist",
     ]) );
   SetSongBook( ([
    "angel whisper" 			: 100,
    "ballad of autumn" 		: 100,
    "ballad of spring" 		: 100,
   	"star strike"  				: 100,
    "ballad of the seasons"  : 100,
    "ballad of summer" 		: 100,
    "ballad of winter" 		: 100,
    "banshee scream" 			: 100,
    "debutant aria" 			: 100,
    "glory of the mage" 	: 100,
    "harmonic shield" 		: 100,
    "harpy's shriek" 			: 100,
    "lunar ballad" 				: 100,
    "pianissimo" 					: 100,
    "shielding song" 			: 100,
    "solar ballad" 				: 100,
    "song of sorrow" 			: 100,
    "staccato" 					  : 100,
    "tingling song" 		  : 100,
    "wail of the banshee" : 100,
    "song of the dance"   : 100,
  	]) );
  SetAction(10, ({ 
  	"!sing solar ballad",
    "!sing lunar ballad",
    "!sing glory of the mage",
    "!sing wail of the banshee",
    "!whistle",
    "!hum",
    "!emote sings a little ditty to herself.",
    "!emote looks joyous.",
    }) );
  SetCombatAction(90, ({ 
  	"!sing star strike",
    "!sing ballad of the seasons",
    "!sing wail of the banshee",
    "!sing song of the dance",
    }) );
  SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
    "Soleil citizen","Oppugno","shaggy dog","Sorgan",
    "entrance guard","Iuvo","Fossis","Kiee","Miserum","knight","guard",
    "Acclima","Trill","Kiee","Miserum","Fossis","Aegri","Melody",
  }) );
  SetFirstCommands( ({
  	"sing wail of the banshee",
    "sing wail of the banshee",
    "sing wail of the banshee",
  	}) );
}
