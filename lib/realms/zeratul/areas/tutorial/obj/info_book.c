#include <lib.h>
#include <message_class.h>
#define NEWBIE_HELP_FILE "/doc/help/players/newbie"
inherit LIB_ITEM;
int ReadMe();

static void create() {
  ::create();
  SetKeyName("information book");
  SetPreventGet("The book jumps out of your hands as you attempt to take it.");
  SetShort("an information book");
  SetId( ({ "book" }) );
  SetAdjectives( ({ "information" }) );
  SetLong(
      "This book contains valuable information for new players. Type <read book> to learn more."
  );
  SetRead( (: ReadMe :) );
  SetMass(100);
  SetValue(10);
}

int ReadMe() {
  object who = this_player();

  send_messages("read",
    "$agent_name $agent_verb an information book.",
    who, 0, environment(who) );
  who->eventPage(NEWBIE_HELP_FILE, MSG_SYSTEM);
  return 1;
}
