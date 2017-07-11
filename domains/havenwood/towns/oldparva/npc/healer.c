#include <lib.h>
inherit LIB_HEALER;

static void create() {
   healer::create();
   SetTown("Parva");
   SetProperty("parvanoleave",1);
   SetKeyName("Iana");
   SetShort("Iana the healer");
   SetId( ({ "iana","healer","female","muezzin" }) );
   SetAdjectives( ({ "iana","the","female","muezzin","healer"}) );
   SetLong("Iana has a wild, insane look in her eyes, but she "
           "seems pleasant enough in demeaner.  She has soft "
           "brown fur that has grown a little long.");
   SetGender("female");
   SetRace("muezzin");
   SetClass("rogue");
   SetLevel(13+random(3));
   
   SetLocalCurrency("oros");
   SetFees( ([
    "resurrect" : 100,
     "magic" : 25,
   "stamina" : 15,
    "health" : 3,
    "restore" : 50,
   ]) );
   RemoveLanguage("Oiseau");
   SetLanguage("Enlan",100,1);
   SetMorality(100);
   SetAction(5, ({ "!say Come!  Come!  Let me heal you!",
                   "!say For a small price I will heal you!",
                   "!say Welcome, all!","!emote dances.",
                   "!emote gleefully claps.","!giggle",
                   "!laugh","!say Let us be merry and have "
                   "fun!","!say Life is grand, isn't it?",
                   "!say Bright colors make life worth living.",
                   "!smile" }) );
   SetCombatAction(24, ({ "!trip","!shout Help me! Heelp!",
                          "!shout Please, come save me!",
                          "!say Stop you rogue!","!say Get "
                          "out of my house!","!say Leave me!",
                          "!trip","!say Help!","!say Foul demon!",
                          "!say Evil creature!" }) );
}
