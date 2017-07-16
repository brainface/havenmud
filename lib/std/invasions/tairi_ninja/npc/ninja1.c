#include <lib.h>
#include <std.h>
#include "../nit.h"

inherit LIB_INVADER;

static void create() {
  ::create();
  SetKeyName("assassin");
  SetShort("a ninja assassin");
  SetFriends( ({"ninja","assassin","ninja lord"}) );
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetClass("rogue");
  SetLevel(random(25)+70);
  SetGender("female");
  SetId( ({ "assassin", "ninja" }) );
  SetAdjectives( ({ "assassin", "ninja" }) );
  SetLong("This person is dressed in black clothing.  The person "
    "appears very slender and stands here with a solid stance that "
    "seems deadly to those who would challenge her.");
  SetAction(5, ({
    "!emote stands absolutely motionless.",
    "!emote considers you.",
  }) );
  SetCombatAction(5, ({
    "!yell NIIIIIINNNNNNJJJJJJAAAAAA!!!!!!",
    "!emote moves about silently.",
  }) );
  SetWanderPath( ({
    "go south", "go south", "go south", "go south", "go east",
    "go east", "go east", "enter 2nd building", "attack loa", 
    "go up", "attack tsai", "go down", "go out" 
  }) );
  SetEnemyTown("Tairi");
  SetWanderSpeed(3);
}