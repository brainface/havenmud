/*  Necromancer until someone else has one */
// mahkefel 2014: made more colorful and less gothy
#include <lib.h>
#include "../parva.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Muertan");
  SetId( ({ "muertan", "necromancer", "colom" }) );
  SetRace("human");
  SetGender("male");
  SetClass("necromancer");
  SetTown("Parva");
  SetShort("Muertan Colom the Necromancer");
  SetLong(
    "Muertan Colom is the most feared necromancer in Parva. "
    "Muertan is possibly also the only necromancer in Parva, as those seeking "
    "any kind of art, even dark arts, tend to go anywhere else but Parva. It's "
    "well known that he resides in the crypt, but anyone of even marginal "
    "status in the city is buried at sea, and only the complete destitute are "
    "buried here, a number that will likely someday include Muertan himself. "
    "Despite his... less than glamorous demeanor, he may have a thing or two "
    "to teach those seeking to follow his road."
    );
  SetMorality(-500);
  SetLevel(40);
  SetPlayerTitles( ([
    "newbie" : "the Crypt Dweller",
    "mortal" : "the Worm Eater",
    "hm"     : "the Dark Walker of the Crypts",
    "legend" : "the Friend of all Dead Things",
    "avatar" : "the Champion of Crypts and Coffers",
    "fighter" : "the Grinning Guardian of Ghosts and Ghasts",
  ]) );
  SetFreeEquip( ([
    "/std/weapon/pole/staff" : 1,
    PARVA_OBJ "necro_cape" : 1,
  ]) );
  SetInventory( ([
    PARVA_OBJ "necro_cape" : "wear cape",
    "/std/weapon/pole/staff" : "wield staff",
  ]) );
  SetCurrency("oros", random(300) + 10);
  SetAction(5, ({
    "!cast necromantic shield",
    "!pet eustice",
    "!emote twirls his cape.",
    "!say have you come... to learn of the DARK ARTS?!",
    "!emote cackles a bit sadly.",
    "!say I was once feared THROUGHOUT THE LAND! ... but then, but... then",
    "!say no friends? Do what I do! Make them!",
    "!emote tosses a bone for Eustice to fetch.",
    "!say Eustice! Stop that!",
  }) );
  SetCombatAction(65, ({
    "!cast wound",
    "!cast cloud kill",
    "!cast acid splash",
    "!cast necromantic shield",
    "!cast acid blast",
    "!cast acid rain",
    "!cast drain soul",
    "!cast fireball",
    "!cast chain lightning",
    "!say Run Eustice! Save yourself!",
    "!say DON'T HURT EUSTICE! PLEASE!",
    }) );
  SetFriends("eustice");
}

