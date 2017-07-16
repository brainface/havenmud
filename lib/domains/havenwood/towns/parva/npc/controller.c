#include <lib.h>
#include <domains.h>
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("ernesto");
  SetShort("Ernesto Guevarra, the Renowned Explorer");
  SetId( ({ "explorer", "ernesto", "che" }) );
  SetAdjectives( ({ "renowned" }) );
  SetRace("half-elf");
  SetGender("male");
  SetBaseLanguage("Enlan");
  SetTown("Parva");
  SetClass("sailor"); // I am a man! not an animal!
  SetLevel(75); //kiiick'n ass cuz i'm a renowned explorer.
  SetLong(
    "Ernesto Guevarra is a renowned explorer. Since his"
    " youth he has been on the move. He has seen every"
    " continent in the world and visited every place"
    " of note upon those continents. His knowledge of"
    " geography and his impressive social network make"
    " him the ideal man for one to talk to if they were"
    " looking for something to do. One can <ask ernesto"
    " for quests> if they were looking for some adventure."
    );
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );
}
