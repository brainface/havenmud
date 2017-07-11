#include <lib.h>
#include <domains.h>
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("Godard the Quest Giver");
  SetShort("Godard the Quest Giver");
  SetId( ({ "giver", "godard" }) );
  SetAdjectives( ({ "quest" }) );
  SetRace("human");
  SetGender("male");
  SetTown("Averath");
  SetBaseLanguage("Avera");
  SetClass("rogue");
  SetLevel(15);
  SetLong(
    "Godard is a very sleek looking man. He has dark black hair,"
    " and a very calm and collected look upon his face. As a younger"
    " man he spent a lot of time dedicating himself to the art of"
    " adventuring. Because of his time spent travelling as a youth,"
    " he knows much about the Island of Averath and what one might"
    " do to learn something about it. One could <ask godard for"
    " quests> if they were so inclined."
    );
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
    "!speak I have seen much of this island... and more!",
    "!speak Surely you do not wish to be a humble"
    " basketweaver all your life! Go adventuring!",
  }) );
}
