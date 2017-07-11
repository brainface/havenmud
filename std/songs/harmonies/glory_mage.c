/* ----------------------------------------------------------------------- */
// Filename: glory_mage.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Dec 19th, 1998
// Abstract: This is a shielding song against magical damage.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <music.h>
inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("glory of the mage");
  SetRules("", "LIV");
  SetSongType(SONG_DEFENSE);
  SetShieldType(SHIELD_DAMAGE);
  SetSkills( ([
     "vocal music" : 25,
     "instrumental music" : 25,
    ]) );
  SetMagicCost(30, 30);
  SetProtectionTypes(MAGIC|ALL_ELEMENTS);
  SetProtectionAmount(16);
  SetProtectionTime(35);
  SetDifficulty(35);
  SetHelp("Glory of the Mage was written by a bard who witnessed the "
          "Kylin Templar invasion of Jidoor in the year 108.  While "
          "the invasion was being beaten back, the bard decided to "
          "glorify how even a great horde of well protected templars "
          "could be turned away by the power of magic. The song "
          "itself uses a harmonic technique that allows the vocalist to "
          "create a shield of protection against magical and elemental "
          "damage for a short while.");
  SetMessages( ({
    ({  ({ "sing", "play" }), "$agent_name $agent_verb and "
                  "$agent_verb a single note of such "
                  "intensity that it creates a %^GREEN%^hazy "
                 "shield%^RESET%^ around $target_name." }),
    ({ "strike", "The %^GREEN%^hazy shield %^RESET%^around "
                 "$agent_name makes an eerie humming noise "
                 "as $target_name $target_verb it." }),
    ({ "", "The %^GREEN%^hazy shield %^RESET%^around "
           "$agent_name disperses as its harmonic note gently fades "
           "into silence." }),
    }) );
 }

/* Approved by Rhakz on Sat Dec 19 02:53:29 1998. */
