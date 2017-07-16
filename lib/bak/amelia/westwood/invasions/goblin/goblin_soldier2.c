#include <lib.h>
#include "ginvade.h"

inherit LIB_INVADER;

   string array wanderpathlist = ({
                          ({ "attack first guard" }),
                          ({ "attack second guard" }),
                          ({ "go up","enter townhall",
                             "attack fossis" }),
                          ({ "go up","enter townhall",
                             "attack aegri" }),
                          ({ "go up","enter townhall",
                             "attack miserum" }),
                          ({ "go up","go south","go down",
                             "attack foret" }),
                          ({ "go up","go south","go down",
                             "attack nascima" }),
                          ({ "go up","go south","go down",
                             "go southwest","attack oppugno" }),
                          ({ "go up","go south","go down",
                             "enter inn","attack barkeep" }),
                          ({ "go up","go south","go southeast"
                             "attack acclima" }),
                          ({ "go up","go south","go southeast"
                             "go up","attack sorgan" }),
                          ({ "go up","go south","go southeast"
                             "go up","attack dulcae" }),
                          ({ "go up","go south","attack tia" }),
                          ({ "go up","go south","go southeast",
                             "go east","attack kiee" }),
                          ({ "go up" })
                       })[random(15)];

static void create() {
invader::create();
SetKeyName("soldier");
SetId( ({ "goblin", "soldier" }) );
SetAdjectives("goblin");
SetShort("a goblin soldier");
SetLong("This is a small goblin soldier.  He is light green "
	"in color and is a dog-faced thing.  He appears to be very "
	"busy as he runs about trying to prepare for something.");
SetRace("goblin");
SetClass("barbarian");
SetAction(6, ({ "!say Me kill!","!attack first citizen",
	"!attack first muezzin" }) );
SetCombatAction(30, ({
	"!emote stumbles about in his attack.",
	"!emote swings his sword wildly about in an attack.",
}) );
SetDie("Soldier drops to the ground and bleeds over the grass.");
SetInventory( ([
	GOBLIN_DIR + "leather_armour" : "wear armour",
	GOBLIN_DIR + "short_sword" : "wield sword",
]) );
SetWanderSpeed(5);
SetWanderPath(wanderpathlist);
SetLevel(10);
SetGender("male");
SetCurrency("cuicui", 10 + random(10));
}