#include <lib.h>
#include <message_class.h>
#define NEWBIE_HELP_FILE "/doc/help/players/rules"
inherit LIB_ITEM;
int ReadMe();

static void create() {
  ::create();
  SetKeyName("rule book");
  SetPreventDrop("You cannot drop the Rule Book!");
  SetPreventGet("You can't take that.");
  SetShort("a rule book");
  SetId( ({ "book" }) );
  SetAdjectives( ({ "rule" }) );
  SetLong("This book should be read by all players on Haven.");
  SetRead( (: ReadMe :) );
  SetMass(100);
  SetValue(10);
}

int ReadMe() {
  object who = this_player();
  string title;

  title = "of " + who->GetTown();
  send_messages("read",
    "$agent_name $agent_verb a rule book.",
    who, 0, environment(who) );
  who->eventPage(NEWBIE_HELP_FILE, MSG_SYSTEM);
  return 1;
}
