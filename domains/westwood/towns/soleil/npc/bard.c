#include <lib.h>
#include "../soleil.h"
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Melody");
  SetShort("Melody, the Joyful Bard");
  SetId( ({ "bard","melody" }) );
  SetReligion("Eclat","Eclat");
  SetTown("Soleil");
  SetAdjectives( ({ "joyful" }) );
  SetLong("Melody is a sweet muezzin with dark "
    "brown fur and eyes.  She is very "
    "short but appears to be "
    "agile and dexterous, making her "
    "very good at playing music."); 
  SetGender("female");
  SetRace("muezzin");
  SetClass("bard");
  SetSkill("faith",90,1);
  SetSkill("healing",90,1);
  SetUniqueSkills( ([
 		"healing"      : 1,
 		"knife combat" : 2,
  	]) );
  SetLevel(145);
  SetStat("agility",50,1);
  SetPlayerTitles( ([
    "newbie" : "the Muezzin Debutant",
    "mortal" : "the Scintillante Singer",
    "hm"     : "the Performer of Scherzo",
    "legend" : "the Spianato Singer",
    "avatar" : "the Entertainer",
    "cleric" : "the Chorist of Soleil",
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
    "!emote humms.",
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
  SetFreeEquip( ([
    STD_INSTRUMENTS + "fife" : 1,
    STD_KNIFE + "freeknife"  : 1,
  ]) );
  SetFirstCommands( ({
  	"sing wail of the banshee",
  	"sing wail of the banshee",
  	"sing wail of the banshee",
  	}) );
}

void eventJoin(object who, string args) {
  if(member_array(who->GetRace(), ({ "halfling","muezzin",
    "gelfling" })) == -1) {
    eventForce("speak Sorry, I only help my local races.");
    return;
  }
  return ::eventJoin(who,args);
}
