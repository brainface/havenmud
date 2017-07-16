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
