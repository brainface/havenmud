/*  A basic history book of Kailie */
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("book");
  SetAdjectives( ({ "large" }) );
  SetId( ({ "book", "history", "history of kailie" }) );
  SetShort("a large book");
  SetLong("This large tome has the words, \"A history of Kailie\"  " 
          "written on it. Its leather binding seems to hold "
          "the papyrus leaves in place.");
  SetRead(
    "default",
    "In the beginning, there was nothing. \n"
    "From the nothing came the Immortals, their glory spreading "
    "into all corners of the universe. The gods came together for the "
    "first time, a feat to be accomplished only one other time, in order "
    "to create the world of Kailie. Each Immortal gave it a gift, and "
    "each left its own special mark upon the land. The animals were created, "
    "the flora was grown, and the world was at peace. This state of affairs "
    "lasted for millenia uncounted, as the Immortals lived in a state of "
    "peace and reflection, each getting acquainted with its new powers. "
    "These Immortals were the young, birthed of the universe, they had "
    "never faced the fears of mortality, and they were prone to mistakes. "
    "\n"
    "And mistakes they made. The Immortals, seeking more to do with "
    "these vast powers, went beyond creating simple life and entered "
    "into creating sentient life. The first thinking race upon Kailie "
    "were the Elves. Their creation lies a mystery in the swirls of time, "
    "and the Elves have legends that they are not of this world, but the "
    "truth to this historian is that they were the first to walk upon this "
    "land. They came, and they inhabited the forests known as the HavenWood. "
    "Their home there was tranquil and peaceful. It lasted generations, "
    "until Ahriman created the Orcs in a sick parody of the Elves. "
    "Where the elven skin is a fair faint green, the orkish skin is "
    "a sickly green. Ahriman's evil was great, and his creation caused "
    "the Immortals to see that they, too, needed followers of their own. "
    "\n"
    "From this point, all the Immortal created their kin, Zaxan created "
    "the Sprites, Balishae created the Halflings, and Durandel created "
    "the Drughkor. These creatures lived upon Kailie in peace with "
    "the Elves. And then came the GodsWar. \n\n"
    "See the tome entitled, \"The GodsWar\" for details."
  );
 SetPreventGet("The book seems to like being where it is.");
 }
