// Torak@Haven - 2/27/15 //



#include <lib.h>
#include <daemons.h>

inherit LIB_NPC;

int milk(string args);

 static void create() {
  ::create();
  SetKeyName("dairy cow");
  SetId( ({ "cow" }) );
  SetAdjectives( ({ "dairy" }) );
  SetShort("a dairy cow");
  SetLong("This light brown dairy cow has short horns and "
    "large fluffy ears on her docile head. "
    "Her full utter hangs from her large frame ready to be milked. ");
  SetRace("cow");
  SetClass("animal");
  SetLevel(1);
  SetGender("female");
  SetAction(10, ({
    "!emote exclaims, %^CYAN%^BOLD%^Mooooooooo!%^RESET%^",
    "!emote asks, %^CYAN%^BOLD%^Mooooooooooo?%^RESET%^",
    "!emote casually states, %^CYAN%^BOLD%^Mooo.%^RESET%^",
    "!emote eats something from the ground, not having a care at all about it whatsoever.",
    "!emote swats her tail as she stares dumbfounded and blankly at nothing at all in
particular.",
  }) );
}


void init() {
  ::init();
  add_action("milk", "milk");
  }

int milk(string args) {

  if (!args) {
    message("system", "Perhaps you should try to <milk cow> next time.",
    this_player() );
    return 1;
  }

  if (args == "cow") {
    new("realms/torak/obj/rawmilk.c")->eventMove(this_player());
    send_messages("milk", 
      "$agent_name $agent_verb the cow with a ceramic white cup.",
      this_player(), 0, this_object() );
    return 1;
    }

return 0;
}
