/* Zeratul@Haven
 * Concept: The big bad necro leader
 * 11/03/2001
 */

#include <lib.h>
#include <domains.h>
#include "../undead.h"

inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("mordon");
  SetId( ({ "mordon", "guard_shrine" }) );
  SetShort("Mordon the Master of the Undead");
  SetLong(
     "This frail looking man stands with a odd expression on his face. His eyes are "
     "completely black and his skin is a pale grey. He stands firm, giving a grin "
     "to all of those around him. "
  );
  SetLevel(60);
  SetRace("human");
  SetClass("necromancer");
  SetGender("male");
  SetMorality(-500);
  SetProperty("no bump", 1);
  SetTaughtSpheres( ({ "necromancy" }) );
  SetFreeEquipment( ([ "/std/weapon/small_knife" : 1, ]) );
  SetStat("durability", 75, 3);
  SetStat("strength", 75, 3);
  SetStat("intelligence", 125, 1);
  SetStat("speed", 75, 3);
  SetStat("agility", 75, 3);
  SetStat("wisdom", 75, 3);
  SetStat("charisma", 10, 5);
  SetStat("coordination", 75, 3);
  SetRestrictRace(1);
  SetGlobalLeader(1);
  SetInventory( ([
     UNDEAD_OBJ + "kris" : "wield kris",
     UNDEAD_OBJ + "barmour" : "wear armour",
  ]) );
  SetStat("coordination", 75, 3);
  SetPlayerTitles( ([
     "newbie"        : "the Youth of the Darkness",
     "mortal"        : "the Warlock of the Darkness",
     "high mortal"   : "the Master over the Darkness",
     "legend"        : "the Evil Ruler over the Hordes of the Undead",
     "avatar"        : "the One with Absolute Power of Undeath",
     "demigod"       : "the One Whom is Spoken of in Legends of Absolute Evil",
  ]) );
  SetSpellBook( ([
     "spook" : 100,
     "pain touch" : 100,
     "drain soul" : 100,
     "paralysis" : 100,
     "touch of death" : 100,
     "chill touch" : 100,
     "choking shadows" : 100,
     "cloak of darkness" : 100,
     "chaos bolt" : 100,
     "gangrene" : 100,
     "poison explosion" : 100,
  ]) );
  SetAction(2,({
     "!emote grins at you.",
     "!say The undead flesh...",
     "!say A thousand eyes...peer out from the darkness.",
     "!say Can you hear the voices?",
     "!say The voices call your name.",
     "!say The harmony...is disturbed.",
     "!emote twitches slightly.",
     "!cast cloak of darkness",
  }) );
  SetCombatAction(10, ({
     "!cast spook",
     "!cast drain soul",
     "!yell Silence the Discord!",
     "!cast paralysis",
     "!cast touch of death",
     "!cast poison explosion",
     "!cast chaos bolt",
     "!cast gangrene",
     "!cast pain touch",
     "!cast choking shadows",
     "!yell They seeeeee yoouuuu!"
  }) );
  }
