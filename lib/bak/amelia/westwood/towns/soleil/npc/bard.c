#include <lib.h>
#include "../soleil.h"
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
  SetClass("bard");
  SetRace("muezzin");
  SetSkill("faith",90,1);
  SetSkill("healing",90,1);
  SetUniqueSkills( ([
    "healing" : 1,
    "knife attack" : 2,
  ]) );
  SetLevel(45);
  SetStat("agility",50,1);
  SetStat("dexterity",50,1);
  SetPlayerTitles( ([
    "newbie" : "the Muezzin Debutant",
    "mortal" : "the Scintillante Singer",
    "hm"     : "the Performer of Scherzo",
    "legend" : "the Spianato Singer",
    "avatar" : "the Entertainer",
    "cleric" : "the Chorist of Soleil",
  ]) );
  SetSongBook( ([
    "angel whisper" : 100,
    "ballad of autumn" : 100,
    "ballad of spring" : 100,
    "ballad of summer" : 100,
    "ballad of winter" : 100,
    "banshee scream" : 100,
    "debutant aria" : 100,
    "exultant tintinnabulation" : 100,
    "glory of the mage" : 100,
    "harmonic shield" : 100,
    "harpy's shriek" : 100,
    "joyous cacophony" : 100,
    "lunar ballad" : 100,
    "merry euphony" : 100,
    "pianissimo" : 100,
    "shielding song" : 100,
    "solar ballad" : 100,
    "song of sorrow" : 100,
    "spiccato" : 100,
    "tingling song" : 100,
  ]) );
  SetAction(10, ({ "!sing solar ballad",
    "!sing lunar ballad",
    "!sing glory of the mage",
    "!sing harmonic shield",
    "!whistle","!emote humms.",
    "!emote sings a little ditty "
    "to herself.","!emote looks "
    "joyous." }) );
  SetCombatAction(30, ({ "!sing spiccato",
    "!sing debutant aria",
    "!sing angel whisper to me",
    "!sing banshee scream",
    "!sing ballad of autumn",
    "!sing ballad of summer",
    "!sing ballad of winter",
    "!sing harpy shriek",
    "!sing tingling song",
    "!shout Help!  Help!",
    "!say Get out of here!",
  }) );
  SetFreeEquip( ([
    "/std/obj/instruments/fife" : 1,
    "/std/weapon/knife/freeknife" : 1,
  ]) );
}

void eventJoin(object who, string args) {
  if(member_array(who->GetRace(), ({ "halfling","muezzin",
    "gelfling" })) == -1) {
    eventForce("speak Sorry, I only help my local races.");
    return;
  }
  return ::eventJoin(who,args);
}
