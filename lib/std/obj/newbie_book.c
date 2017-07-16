#include <lib.h>
#include <message_class.h>
#define NEWBIE_HELP_FILE "/doc/help/players/newbie"
inherit LIB_ITEM;
int ReadMe();

static void create() {
  ::create();
  SetKeyName("newbie book");
  SetPreventDrop("You cannot drop the Newbie Guide!");
  SetPreventGet("You cannot take the Newbie Guide!");
  SetShort("a newbie book (game manual)");
  SetId( ({ "book", "manual" }) );
  SetAdjectives( ({ "newbie", "game" }) );
  SetLong("This book should be read by all new players to Haven.");
  SetRead( (: ReadMe :) );
  SetMass(100);
  SetValue(10);
}

int ReadMe() {
  object who = this_player();
  string title;

  title = "of " + who->GetTown();
  send_messages("read",
    "$agent_name $agent_verb a newbie book.",
    who, 0, environment(who) );
  if (who->GetQuestCompleted("Newbie Book") || who->GetQuestCompleted("Newbie")) return 1;
  who->AddQuest(title, "Newbie Book");
  who->SetLevel(1);
  who->AddDevelopmentPoints(160);
  who->eventPrint("You receive 160 development points.");
  who->eventPage(NEWBIE_HELP_FILE, MSG_SYSTEM);
  return 1;
}
