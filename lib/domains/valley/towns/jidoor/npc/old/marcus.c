/* Marcus -- Mystic Natural Enchantment Leader
 * Ranquest@Haven
 * 02/13/99
 */
#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetReligion("Magildan","Magildan");
  SetShort("Marcus, a mystic of the grove");
  SetKeyName("marcus");
  SetId( ({"marcus","mystic"}) );
  SetLong(
    "Marcus is a fairly tall human, with reddish-brown hair"
    " and a sober disposition. He seems quite content with his"
    " place here in the grove, as an assistant to Garath. His"
    " green eyes reveal his deep nature.");
  SetRace("human");
  SetClass("mystic");
  SetGender("male");
  RemoveLanguage("Enlan");
  SetLanguage("sprith",100,1);
  SetLevel(55);
  SetSpellBook( ([
    "chameleon" : 100,
    "create prism" : 100,
    "dust to water" : 100,
    "mend leather" : 100,
    "mend metal" : 100,
    "mend wood" : 100,
    "soothe" : 100,
    "wall of wood" : 100,
    "warp wood" : 100,
    ]) );
  SetAction(1, ({
    "!say I can teach you some natural enchantment spells.",
    "!ask Would you like me to teach you some spells?",
    "!emote sighs contentedly.",
    }) );
  }
