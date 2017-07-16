/* A sled... guard... dog
 *
 * These guys know something is wrong as fuck, but they're just dogs
 *   So they can't tell you what it is.
 */

#include <lib.h>
#include "../camp.h"

inherit LIB_SENTIENT;

static void create() {
    ::create();

    //descriptions
    SetKeyName("husky");
    SetId( ({ "dog", "husky", "uninfected" }) );
    SetShort("a furry husky");
    SetLong(
      "This massive sled dog seems clothed in a thick layer of snow. "
      "Under that somewhere is probably fur, but you can't quite tell. "
      "His eyes dart about in paranoid fashion, and his tail is "
      "tucked between his legs."
    );
    SetGender("male");

    //vital statistics
    SetClass("animal");
    AddSkill("dodge",1);
    SetLevel(15);
    SetRace("dog");

    SetFriends("uninfected");

    SetMeleeAttackString("snap");

    //miscellaneous
    SetAction(2, ({
      "!emote braces himself on the snow and ice and growls ferociously "
        "at a completely empty patch of snow.",
      "!emote whines piteously.",
      "!emote runs around in a circle, sniffing at the snow.",
      "!emote howls out a warning.",
      "!emote sniffs suspiciously at you.",
      "!emote tries to dig a hole in the ice, whimpering.",
    }) );
    
    SetWanderSpeed(30);
}

