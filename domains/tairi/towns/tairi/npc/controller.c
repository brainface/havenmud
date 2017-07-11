#include <lib.h>
#include <domains.h>
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("Kazuichiro");
  SetShort("Kazuichiro the Quest Giver");
  SetId( ({ "giver", "kazuichiro" }) );
  SetAdjectives( ({ "quest" }) );
  SetRace("human");
  SetGender("male");
  SetTown("Tairi");
  SetBaseLanguage("Tai");
  SetClass("contemplator");
  SetLevel(15);
  SetLong(
    "Kazuichiro is a tall and rugged man. His body has been"
    " marred by many scars and abrasions. In contrast to his"
    " beaten appearance, Kazuichiro is known to be extremely"
    " content almost jovial. His reputation as an adventurer"
    " is well known throughout the land. Those in need of a"
    " quest should <ask kazuichiro for quests>."
    );
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
    "!speak I have seen much of this island... and more!",
    "!speak Surely you do not wish to be a humble"
    " basketweaver all your life! Go adventuring!",
  }) );
}

