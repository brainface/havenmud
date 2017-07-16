#include <lib.h>

inherit LIB_ITEM;

static void create() {
::create();
SetKeyName("the Day of the Black Roses");
SetShort("a golden book with a black rose on the cover");
SetId(({ "day of the roses", "book", "book of faith", "soirin book" }));
SetAdjectives( ({ "golden" }) );
SetLong(
        "This book has a binding of solid gold with golden hinges"
        " to support opening. The cover has intricate geometric"
        " patterns around an embossed black rose in the center."
        " Towards the bottom the title has been etched into it:"
        " The Day of the Black Roses."
        );
SetRead("default", 
   "                     The Day of the Black Roses \n"
     "                        by Tonian Pariad \n\n\n"
     "    ...And so it was that Portia gave birth to the twins, Alessandra \n"
     " and Melchezidek, the head and tail of the coin of Soirin. But it \n"
     " was this very act of birth that weakened the Lady Portia and sapped \n"
     " her immortal spirit, for with this birth she was split into two \n"
     " halves. Her will was divided among the children who would come to \n"
     " rule her domain, but none was left for her.\n\n"
     "    And so she passed from the Heavens leaving behind her essence in the \n"
     " infant immortals. Ages passed for the Soirin without the Divine \n"
     " Presence while the young deities aged and learned to control their \n"
     " essence. The wait was hard for the faithful, for their lives seemed \n"
     " without meaning, without pleasure. By the time the Two matured and \n"
     " returned to their people, it was nearly too late.\n\n"
     "    It was a desolate and sad scene that greeted the Two when they \n"
     " delivered themselves unto Malveillant. The faces of the Malveillanti's \n"
     " were long and drawn until the serene beauty of their newly matured \n"
     " Prince and Princess gazed upon them. Their hearts were once again \n"
     " filled with the pleasure and yearning associated with the Divine \n"
     " Presence and in a downpour of black roses, the Two disapeared once \n"
     " again, to return to their place in the Heavens, but it was enough for \n"
     " the faithful. They had received the sign they had been waiting for \n"
     " for many generations. They had once again been graced by the \n"
     " Mistress of Seduction through her progeny. \n"
     );

}


varargs mixed eventRead(object who, string str) {
if (who->GetReligion() == "Soirin" && who->GetBlessed() < 1) {
    who->AddBlessed(5);
  return ::eventRead(who, "default");
  }
  return ::eventRead(who, "default");
}
