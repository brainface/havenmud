/* Wither spell
 * Created by Morgoth@Haven
 * Balanced by Duuktsaryth@Haven
 * 8 Sep 1997
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
    spell::create();
    SetSpell("wither");
    SetRules("", "LIV");
    SetSpellType(SPELL_COMBAT);
    SetSkills( ([
      "necromancy" : 100,
      "conjuring"  : 100,
    ]) );
    SetDifficulty(30);
    SetMorality(-2);
    SetAutoDamage(0);
    SetDamageType(MAGIC);
    SetMessages(({ ({ ({"feel", "shake"}), "$target_name $target_verb slightly "
          "weakened, but $target_nominative $target_verb it off immediately."}),
          ({ "feel", "$target_name $target_verb sharp jabs of%^BOLD%^RED%^ "
          "pain%^RESET%^ from $agent_possessive_noun spell." }),
          ({ "double", "$target_name $target_verb over in %^BOLD%^RED%^pain "
          "%^RESET%^as $target_possessive body is %^MAGENTA%^withered"
          "%^RESET%^." }),
          ({ "fall", "$target_name $target_verb to the ground, %^BOLD%^RED%^"
          "crippled%^RESET%^ by the intense pain of $agent_possessive_noun spell!" }) }));
  SetHelp(
            "This spell causes the target's body to wither away. "
            "The target is subjected to extreme pain as his or her "
            "muscles are diminished, and their body withers away. "
            "If cast without a target the spell will be directed at "
            "your current opponent.");
  }

