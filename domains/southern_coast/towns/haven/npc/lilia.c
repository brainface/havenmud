#include <lib.h>
#include <daemons.h>
#include "../haven.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("lilia");
  SetUniqueSkills( ([
    ]) );
	SetTaughtSpheres( ({
		"clerical",
		"religion kylin",
		"clerical healing",
		"clerical enchantment"}) );
  SetRace("gelfling");
  SetGender("female");
  SetClass("priest");
  SetClass("bard");
  SetSkill("melee combat",1,2);
  SetSkill("instrumental music",1,1);
  SetSkill("vocal music",1,1);
 
  SetLevel(30);
  SetReligion("Kylin","Kylin");
  SetShort("Lilia Theselwig, the Chorist Director of Kylin");
  SetMorality(1050);
  SetId( ({ "lilia", "lilia theselwig", "theselwig", "chorist" }) );
  SetLong("Lilia Theselwig used to head up the Kylin faith in "
          "the HavenWood. With the rise of Eclat, she fled to "
          "Haven Town to study and assist Dalahalus in his work.");
  SetAction(5, ({
     "!speak Would you like to be converted?",
     "!speak I teach the chorists of Kylin.",
     }) );
  SetCombatAction(40, ({
  	 "!cast fidei defensor",
  	 "!cast wrath",
  	 }) );
  SetSongBook( ([
     "thirst" : 100,
     "tavernsong" : 100,
     ]) );
  SetSpellBook( ([
     "cure blindness"   : 100,
     "remove paralysis" : 100,
     "mend"             : 100,
     "bless"            : 100,
     "revive"           : 100,
     "fidei defensor"   : 100,
     "wrath"            : 100,
     ]) );
 }
