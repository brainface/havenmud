#include <lib.h>
#include "../ungkh.h"

inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("corlebus");
  SetRace("ogre");
  RemoveLanguage("Shangtai");
  SetLanguage("Uruk",100,1);
  SetClass("barbarian");
  SetLevel(50);
  SetGender("male");
  SetTown("Ungkh");
  SetReligion("Kuthar", "Kuthar");
  SetMorality(0);
  SetId( ({
    "ogre","corlebus","barbarian","citizen",
    }) );
  SetAdjectives( ({
    "strong",
    }) );
  SetShort("corlebus, the barbarian");
  SetLong("Always being strong for his age, Corlebus spent his time "
          "training.  A self built warrior, he always has the "
          "experience to face any and all challenges.  He looks "
          "prepared to defend Ungkh with his life.");
  SetAction(1, ({
    "!exclaim ugh, me big! Me stong! Yoo be doo, if yoo wan!",
    "!stretch",
    "!grunt",
    "!scratch",
    }) );
  SetCombatAction(1, ({
    "!grunt angrily",
    "!curse",
    "!say yoo baad!",
    }) );
  SetFriends( ({"ogre","guard"}) );
  SetCurrency("skins",250+random(150));
  SetPlayerTitles( ([
    "newbie" : "the Lowly Toe Nail of Ungkh",
    "mortal" : "the Arm of Ungkh",
    "hm"     : "the Pride of Ungkh",
    "legend" : "the Muscle of Ungkh",
    "avatar" : "the Destroyer of All",
    ]) );
}
