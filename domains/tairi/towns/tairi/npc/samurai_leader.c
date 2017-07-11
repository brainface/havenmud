/* The samurai leader */
#include <lib.h>
#include "../tairi.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Minamoto Ka");
  SetShort("Minamoto Ka, Lord Samurai of Tairi");
  SetClass("cavalier");
  SetLevel(67);
  SetGender("male");
  SetId( ({ "minamoto", "ka", "samurai", "citizen" }) );
  SetFriends( ({ "samurai", "daimyo" }) );
  SetAdjectives( ({ "minamoto", "lord" }) );
  SetLong("The great samurai lord of Tairi looks much as any other "
         "samurai, except that his armour is slightly more ornate. "
          "Young warriors come to him for instruction in the ways of "
          "the samurai.");
  SetCurrency("koken", random(3000) );
  SetMorality(500);
  SetTown("Tairi");
  SetNoMulti(1);
  SetRestrictRace(1);
  AddUniqueSkill("multi-weapon", 1);
  AddUniqueSkill("reinforced armour", 1);
  AddUniqueSkill("plate armour", 4);
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetAction(5, ({
      "!speak Young warriors may join our ranks.",
      "!speak Only pure humans need bother me.",
      "!speak The way of the warrior is painful and long.",
      "!speak Know that we are unlike other honored warriors.",
    }) );
  SetFreeEquip( ([
     TAI_RI_OBJ + "katana" : 1,
     TAI_RI_OBJ + "wakasashi" : 1,
     TAI_RI_OBJ + "newbie_oyoroi" : 1,
    ]) );

  SetPlayerTitles( ([
     "newbie" : "the Young Warrior of Tairi",
     "mortal" : "the Samurai of Tairi",
     "hm" : "the High Samurai of Tairi",
     "legend" : "the Legendary Samurai of Tairi",
     "avatar" : "the Godlike Warrior Lord of Tairi",
    ]) );
  SetInventory( ([
     TAI_RI_OBJ "oyoroi" : "wear armour",
     TAI_RI_OBJ "katana" : "wield katana",
     TAI_RI_OBJ "wakasashi" : "wield wakasashi",
    ]) );
}
