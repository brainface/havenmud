#include <lib.h>
inherit LIB_ITEM;
inherit LIB_READ;

int ReadMe(object);

static void create() {
  item::create();
  SetKeyName("plaque");
  SetShort("a small steel plaque");
  SetRead( (: ReadMe :) );
  SetId( ({ "plaque" }) );
  SetAdjectives( ({ "small", "steel" }) );
  SetLong("This small plaque seems to have a deep meaning. "
          "Perhaps you should <read> it?"
          );
  SetPreventGet("The plaque is firmly planted into the ground.");
}
  
int ReadMe(object who) {
  string message = "The desert is a fickle creature, nearly a god but "
                   "within the control of He Who Judges. Ours is not "
                   "to question his will, but merely to permit the "
                   "desert to shape us and guide us.";
  
  message = translate(message, who->GetLanguageLevel("Padashi"), "Padashi");
  send_messages( ({ "read" }),
    "$agent_name $agent_verb a small steel plaque.",
    who, 0, environment(who) );
  who->eventPrint("You read the message as \"" + message + "\".");
  return 1;
}
