/* Sandy -- Mystic Natural Enchantment Leader
 * Ranquest@Haven
 * 02/13/99
 */
#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetReligion("Magildan","Magildan");
  SetShort("Sandy, a mystic of the grove");
  SetKeyName("sandy");
  SetId( ({"sandy","mystic"}) );
  SetLong(
    "Sandy is a small elf who has forsaken the religion of"
    " Kylin in favour of the Magildan triad. Her blue eyes"
    " are crinkled with an everpresent joy, and her straw-"
    "coloured hair seems to shine in the sunshine.");
  SetRace("elf");
  SetClass("mystic");
  SetGender("female");
  RemoveLanguage("Eltherian");
  SetLanguage("Sprith",100,1);
  SetLevel(55);
  SetSpellBook( ([
    "cleanse flesh" : 100,
    "invigorate" : 100,
    "tend wounds" : 100,
    "regrowth" : 100,
    ]) );
  SetAction(1, ({
    "!say I can teach you some natural healing spells.",
    "!ask Would you like me to teach you some spells?",
    "!emote sighs contentedly.",
    }) );
  }
