#include <lib.h>
#include <domains.h>
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("morin");
  SetShort("Morin the Pious, a Cleric of Saryth");
  SetId( ({ "morin", "cleric" }) );
  SetAdjectives( ({ "pious", "sarythian" }) );
  SetReligion("Kylin");
  SetGender("male");
  SetTown("Averath");
  SetRace("human");
  SetRestrictRace(1);
  SetClass("cleric");
  SetUniqueSkills( ([
    "blunt attack" : 1,
    "healing" : 2,
    "blunt defense" : 2,
    ]) );
  SetTaughtSpheres( ({ "clerical", "clerical healing", "clerical enchantment" }) );
  SetLevel(30);
  SetMorality(1600);
  SetLong("Morin the Pious is the primary cleric of Saryth in "
          "Averath. He would be more than willing to \"describe "
          "clerics\" if you asked him, as well as \"convert\" you "
          "and even let you \"join clerics\".");
  SetInventory( ([
    AVERATH_OBJ "morin_mace" : "wield mace",
    ]) );
  SetAction(10, ({
    "!say Ours is a wonderful day!",
    "!say Saryth preaches tolerance!",
    "!say Join the Order!",
    }) );
  SetProperty("no bump", 1);
  SetFreeEquipment( ([
    AVERATH_OBJ "newbie_mace" : 1,
    ]) );
  SetPlayerTitles( ([
    "newbie" : "the Pious Learner of Saryth",
    "mortal" : "the Devout Learner of Saryth",
    "high mortal" : "the Priest of Saryth",
    "legend" : "the Legendary Priest of Saryth",
    "avatar" : "the Godlike Priest of Saryth",
    "demigod" : "the One With Saryth",
    ]) );
}


