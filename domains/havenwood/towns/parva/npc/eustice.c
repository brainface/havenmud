#include <lib.h>
inherit LIB_NPC;
static void create(){
    npc::create();
    SetKeyName("eustice");
    SetId( ({ "eustice","dog","mutt" }) );
    SetAdjectives( ({ "mangy","very","and","decaying" }) );
    SetShort("a mangy and very decaying mutt");
    SetLong(
      "This sad looking dog looks like he's seen better days. Days when he "
      "had both his eyes, and a heartbeat. Holes in his side reveal yellowed "
      "ribs and a hollowed out gut that can't hold a single treat. His tongue "
      "still lolls with some animation, though, and his single eye tracks you "
      "as a guileless grin splits his face rather really a bit too far for "
      "comfort."
      );
    SetRace("dog");
    SetUndead(1);
    SetUndeadType("zombie");
    SetGender("male");
    SetClass("animal");
    SetLevel(18);
    SetLimit(1);
    SetAction(5, ({
      "!emote tries to lick you.",
      "!lick muertan happily",
      "!emote bites a bone in half.",
      "!emote sniffs around the crypt for something to eat.",
      "!bark happily",
      "!emote holds a bone in his muzzle up to you, trying to get you to play fetch.", 
    }) );
    SetCombatAction(5, ({
      "!emote whines.",
      "!emote looks confused and hurt.",
      "!emote growls.",
      "!guard muertan.",
    }) );
    SetFriends( ({ "muertan" }) );    
}

