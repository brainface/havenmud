/* Silvana
 * The head cleric for the Silvarin relgion
 * By Sardonas (i.e. Robert Kehrer)
 * 10/27/98
 */
 
#include <lib.h>
#include "../ruins.h"
inherit LIB_LEADER;

int Greet(object);

static void create() {
  leader::create();
  SetKeyName("silvana");
  SetId( ({ "silvana", "druid", "illumination" }) );
  SetAdjectives( ({ }) );
  SetShort("Silvana the Illumination of Arcanith");
  SetLong("Silvana is a young woman of remarkable beauty.  She has long, "
          "brown hair which trails down her back.  Her skin is deeply tan, "
          "as if she spends a lot of time in the sun.  Her eyes are the "
          "color of fresh cinnimon, and show a wisdom well beyond her years.  "
          "There is a peaceful look on her face, as if she knows her place "
          "in the world.");
  SetRace("human");
  SetBaseLanguage("Koblich");
  SetClass("druid");
  SetGender("female");
  SetTown("Arcanith");
  SetMorality(1450);
  SetReligion("Magildan");
  SetSkill("melee combat", 1, 2);
  SetLimit(1);
  SetLevel(75);
  SetDie("With her dying breath, Silvana cries out, \"%^BOLD%^CYAN%^I'm sorry my Lord, I have failed you.%^RESET%^\"");
  SetEncounter( (: Greet :) );
  SetAction(6, ({
      "!say May the light shine upon you always",
      "Silvana utters a prayer to her lord.",
      "!say Only while bathed in the light of Magildan can you truly see",
      "Silvana gazes towards the heavens with a look of peace.",
      "!smile",
    }) );

  SetCombatAction(65, ({
    "!cast summon animal", 
    "!cast wall of wood",
    "!cast ice storm",
    "!cast soothe",
    }) );
/*
  SetInventory( ([ OBJ "/mail_silver.c"   :  "wear mail",
                   OBJ "/robe_silver.c"   :  "wear robe",
                   OBJ "/sandals.c"       :  "wear sandals",
                   OBJ "/mace_silver.c"   :  "wield mace",
  ]) );
*/
  SetSpellBook( ([
    "summon animal"  : 100,
    "wall of wood"   : 100,
    "ice storm"      : 100,
    "soothe"         : 100,
    ]) );

  SetPlayerTitles( ([
    "newbie"     :  "the Seeker of the Light",
    "mortal"     :  "the Keeper of the Flame",
    "hm"         :  "the Master of Illumination",
    "legend"     :  "the Tender of the Tree",
    "avatar"     :  "the Gardener of Arcanith",
    "merchant"   :  "the Voice of the Light",
    "fighter"    :  "the Hand of the Light",
    "barbarian"  :  "the Crusader of the Light",
    "cavalier"   :  "the Shimmering Paladin",
  ]) );
/*
  SetFreeEquip( ([OBJ "/robe_white.c"   :  1,
                  OBJ "/mace_silver.c"  :  1,
  ]) );
*/  
}

int Greet(object who) {
  if (who->GetInvis()) return 0;
  call_out( (: eventForce, "say Welcome to you, " + capitalize(who->GetKeyName()) + "!" :), 0);
  return 0;
}
