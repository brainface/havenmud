/* a faerie 
   Ela
*/
#include <lib.h>
#include "../wood.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Targyn");
  SetShort("Targyn, the Bard");
  SetId( ({"faerie","man","bard","targyn"}) );
  SetAdjectives( ({"young","wiry","slight","sad","confident","faerie"}) );
  SetLong(
      "The young bard has the wiry strength and slight build "
      "of his kind. Quick silver eyes reveal pools of sadness. "
      "His musical adeptness and mesmerizing tales have earned "
      "him a golden reputation while his skill with his staff "
      "is widely acknowledged as quite superb. Confidence "
      "that he can defend himself well shines clearly in his "
      "eyes.");
  SetNoJoin(1);
  SetLimit(1);
  SetWander(10);
  SetWanderPath( ({
      "go south","go east","go east","go north",
      "go south","go west","go west","go north",
      }) );
  SetWanderRecurse(1);
  SetGender("male");
  SetRace("faerie");
  SetClass("bard");
  SetSkill("pole combat", 1, 2);
  SetLevel(12);
  SetMorality(200);
  SetAction(4, ({
      "!say It is fabled that the faeries go parading at night, "
      "dancing and making merry. Those that witness them are "
      "spellbound and perish by light of day, pining for one "
      "more chance to hear their enchanting song.",
      "!say I am cursed to walk this wood, with none but "
      "wild beasts to hear my tales for displeasing my Queen.",
      "!emote closes his eyes and captivatingly sings of the Fae.",
      "!emote sighs dejectedly.",
      }) );
  SetInventory( ([
      WOOD_OBJ + "staff" : "wield staff",
      WOOD_OBJ + "lyre" : 1,
      ]) );
  SetSongBook( ([
     "sonic movement" : 100,
     "sonic barrier"  : 100,
     ]) );
}
