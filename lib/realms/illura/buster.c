//Illura@Haven
//Happy Birthday John!
#include <lib.h>
inherit LIB_NPC;
static void create(){
  npc::create();
  SetShort("Buster the Birthday Monster");
  SetId(({"buster", "monster", "cat"}));
  SetAdjectives(({"birthday"}));
  SetKeyName("Buster");
  SetLong("This is Buster. He is an eight foot "
    "tall, pink haired monster with seventeen eyes "
    "and kitty ears. He loves wishing people a "
    "happy birthday and makes it somewhat of his "
    "job. He's a big sweety.");
  SetRace("cat", "monster");
  SetGender("male");
  SetClass("animal");
  SetLevel(10);
  SetLanguage("common");
  SetAction(80, ({ 
    "!yell Happy Birthday!",
    "!say Is it your birthday?",
    "!say How old are you today?",
    "!yell Who wants cake?",
    "!woo",
    "!dance",
    "!say Do a birthday dance with me!",
    "!emote blows a kazoo at you. Bzzzzt!",
    "!clap",
    "!say I bet you'll get lots of presents.",
    "!say Do you like ice cream? I sure do!",
    "!yell Bless my stars, we have a birthday here!",
    "!say Who wants birthday spankings?",
    "!giggle",
    "!say let's make this the best birthday EVER.",
    "!say Watch out for those gray hairs, huh? Just kidding!",
    "!say You're aging like a fine wine! Not that I drink, guh!",
    "!say Oh, I looooove birthdays.",
    "!whee"
  })
  );
}
