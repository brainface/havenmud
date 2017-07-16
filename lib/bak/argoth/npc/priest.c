#include <lib.h>
#include <std.h>
#include "../argoth.h"

inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("laarg");
  SetId( ({ "laarg", "priest"}) );
  SetAdjectives( ({ "high" }) );
  SetShort("laarg, High Priest of Saahagoth");
  SetLong(
    "Laarg took over as the spiritual leader when Arrhenius, "
    "the previous priest, was killed during the invasion of Karak-Varn. "
    "With the ascendency of Saahagoth, Laarg moved in to a position of power. "
    "He carries himself proudly, constantly aware of his position. Beneath "
    "a heavy brow his eyes of blood red appear to pulse faintly, seeming to "
    "almost ooze with evil power. The rest of his body is formed of dark "
    "green skin, covered in places by matted fur. Shadows seem to gather in "
    "small pools around his feet, never completely visible."
  );
  SetLevel(65);
  SetRace("orc");
  SetClass("priest");
  SetGender("male");
  SetTown("Karak");
  SetReligion("Saahagoth");
  SetPlayerTitles( ([
    "newbie" : "the Apprentice Ecclesiastic",
    "mortal" : "the Karak Priest",
    "hm" : "Mosignor $N the High Priest of Karak",
    "legend" : "Elder $N the Manipulator of Darkness",
    "avatar" : "the Leader of the Dark Horde",
  ]) );
  SetFreeEquip( ([
    STD_HACK + "hand-axe" : 1,
    STD_ARMOUR + "shirt/lg_studded_leather" : 1,
  ]) );
  SetUniqueSkills( ([
  ]) );
  SetSpellBook( ([
    "revive" : 100,
    "protect" : 100,
    "divine mana" : 100,
    "flaming arrow" : 100,
    "sting" : 100,
    "bless" : 100,
    "divine magic" : 100,
    "divine cloak" : 100,
    "divine magic fully" : 100,
    "holy shield" : 100,
    "flaming arrow" : 100,
]) );
  SetAction(5, ({
    "!speak The days of Ahriman are ended! Worship Taigis as the one true "
    "Orc God, and you will be richly rewarded!",
  }) );
  SetTalkResponses( ( [
    "ahriman" : "Ahriman was a fool, the orcs are better off without him.",
    "aberach" : "Saahagoth will lead the orcs into a glorious new age!",
  ]) );
  SetInventory( ([
    ARGOTH_OBJ + "cleaver.c" : "wield cleaver",
  ]) );
  SetCombatAction(5, ({
    "!cast holy shield",
    "!cast bless on cleaver",
  }) );
}
