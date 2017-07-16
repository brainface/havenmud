/* The Kylin Bible */
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("book of faith");
  SetShort("a small leather-bound book");
  SetId( ({ "book of faith", "kylin book", "book" }) );
  SetAdjectives( ({ "leather-bound", "small" }) );
  SetLong("This book seems to be very worn, as if it had been carried "
         "for centuries by the caring hands of some faithful person. "
         "Inscribed on the cover is a balance with a red dragon wrapped "
         "around it, as if protecting it. At various times, it seems that "
         "there is a khopesh sword sitting beneath the balance, and at "
         "other times there is no chance it could be there.");
  SetRead("default",
    "The Book of Faith is the source of all religious knowledge of Kylin. "
    "When Duuktsaryth created the Elves, he gave them a sense of order "
    "and balance, and a mind to know that theirs was a responsability "
    "like no other on this world. The elves would keep the balance. "
    "Never would the elves be allowed peace, for they would be the "
    "keepers of the Immortals, they would make sure that no single "
    "force became too powerful, lest it destroy the simple axis that "
    "Kailie needs in order to continue. And so the Elves carried this "
    "burden before the GodsWar alone, watching and waiting. \n"
    "With the coming of the GodsWar, the Elves were forced out of their "
    "watching and had to act. With the dominance of the evil forces, "
    "the Elves attacked the city of Haven, a city held by the Orcs, "
    "and destroyed it utterly. Duuktsaryth in his wisdom ended the "
    "war by destroying Durandel and the Drughkor. Seeing the fate "
    "that befell one supposed to be \"Immortal\", the others quickly "
    "fell into line. The elves were left in Haven Town to rule as "
    "conquerers over a shattered town. \n"
    "The end of the GodsWar and the creation of humans brought new "
    "waves to the followers of Kylin, but still the balance of "
    "the world was threatened, and the elves were not enough to "
    "strike terror into the hearts of a race that had not been "
    "created during the GodsWar. And so the Lord of Balance looked "
    "for a way to stave off the coming destruction he saw as a "
    "result of the balance being offset. \n"
    "Duuktsaryth found his answer in a tribe of humans living in "
    "the Yozrath Desert. The Padashi tribe living in the village of "
    "Yozrath were a fierce warrior clan, but Duuktsaryth saw the "
    "usefulness of these humans. And so he appeared to Sulemain, "
    "the chief Shaman of the Padashi, and he showed them the glowing "
    "path of Balance and Order. The Padashi took to it with a vengence "
    "that even the Lord of Balance could not have forseen. "
    "The swords of the Padashi protect the faith in these troubled "
    "days, and the shields of the elven Kylin give it support and "
    "reason. Where the Desert Kylin followers tend towards Jihad, "
    "the Kylin followers of old tend towards docile contemplation of "
    "the Balance. It is a match which keeps the Lord of Balance's "
    "desires met."
  );
 }

varargs mixed eventRead(object who, string str) {
  if (who->GetReligion() == "Kylin" ||
      creatorp(who) ||
     who->GetReligion() == "Desert Kylin" ) {
  return ::eventRead(who, "default");
  }
  else {
  who->eventPrint("You are blinded and stricken by the Book, Infidel!");
  who->SetParalyzed(25);
  who->SetBlind(25);
  return 1;
   }
 }
